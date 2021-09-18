/*
 *	File:		RubberbandOsgWrapper.cpp
 *	Package:	rbeWrapper
 *
 *  Created on: September 17, 2021
 *	Author: Alexander Kuester
 *  Copyright (c) 2021 Alexander Kuester
 *	This file is part of the RubberbandEngine package.
 *	This file is subject to the terms and conditions defined in
 *	file 'LICENSE', which is part of this source code package.
 */

#include <stdafx.h>

// RBE header
#include <rbeWrapper/RubberbandOsgWrapper.h>

#include <rbeCore/AbstractConnection.h>
#include <rbeCore/LineConnection.h>
#include <rbeCore/CircleConnection.h>
#include <rbeCore/AbstractPoint.h>

// osg header
#include <osg/Array>
#include <osg/StateSet>
#include <osg/Node>
#include <osg/Geode>
#include <osg/Group>
#include <osg/Geometry>
#include <osg/PolygonMode>
#include <osg/LineWidth>

// C++ header
#include <cassert>

using namespace rbeCore;

rbeWrapper::RubberbandOsgEngine::RubberbandOsgEngine(osg::Group * _parentGroup, coordinate_t _originU, coordinate_t _originV, coordinate_t _originW)
	: rbeCore::RubberbandEngine(_originU, _originV, _originW), m_parentGroup(_parentGroup), m_node(nullptr),
	m_r(1.), m_g(0.), m_b(0.), m_depthTest(false), m_circleSegments(10)
{

}

rbeWrapper::RubberbandOsgEngine::~RubberbandOsgEngine() {

}

// ############################################################################################

// Base class functions

void rbeWrapper::RubberbandOsgEngine::addPoint(rbeCore::Point * _point) {

	RubberbandEngine::addPoint(_point);
}

void rbeWrapper::RubberbandOsgEngine::replaceOrigin(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW) {
	RubberbandEngine::replaceOrigin(_originU, _originV, _originW);
	updateNode();
}

void rbeWrapper::RubberbandOsgEngine::updateCurrent(coordinate_t _currentU, coordinate_t _currentV, coordinate_t _currentW) {
	RubberbandEngine::updateCurrent(_currentU, _currentV, _currentW);
	updateNode();
}

void rbeWrapper::RubberbandOsgEngine::setupFromJson(const char * _json) {
	cleanupOsgData();
	RubberbandEngine::setupFromJson(_json);
}

void rbeWrapper::RubberbandOsgEngine::clear(void) {
	RubberbandEngine::clear();
	cleanupOsgData();
}

void rbeWrapper::RubberbandOsgEngine::activateStepOne(void) {
	RubberbandEngine::activateStepOne();
	buildNode();
}

void rbeWrapper::RubberbandOsgEngine::activateNextStep(void) {
	RubberbandEngine::activateNextStep();
	buildNode();
}

void rbeWrapper::RubberbandOsgEngine::applyCurrentStep(void) {

	RubberbandEngine::applyCurrentStep();
}

// ############################################################################################

// Private functions

void rbeWrapper::RubberbandOsgEngine::cleanupOsgData(void) {
	if (m_node) {
		m_parentGroup->removeChild(m_node);
		m_node = nullptr;
	}
}

void rbeWrapper::RubberbandOsgEngine::buildNode(void) {
	cleanupOsgData();

	// Read connections and create edges list
	std::list<AbstractConnection *> connections = connectionsToDisplay();	
	std::list<osg::Vec3> edgesList;

	for (AbstractConnection * connection : connections) {
		switch (connection->type())
		{
		case AbstractConnection::ctLine:
		{
			LineConnection * actualConnection = dynamic_cast<LineConnection *>(connection);
			edgesList.push_back({ actualConnection->from()->u(), actualConnection->from()->v(), actualConnection->from()->w() });
			edgesList.push_back({ actualConnection->to()->u(), actualConnection->to()->v(), actualConnection->to()->w() });
		}
		break;
		case AbstractConnection::ctCircle:
		{
			CircleConnection * actualConnection = dynamic_cast<CircleConnection *>(connection);
			coordinate_t midU = actualConnection->centerPoint()->u();
			coordinate_t midV = actualConnection->centerPoint()->v();
			coordinate_t midW = actualConnection->centerPoint()->w();
			coordinate_t radius = actualConnection->radius();
			CircleConnection::eCircleOrientation orientation = actualConnection->orientation();

			bool hasLast{ false };
			coordinate_t lU, lV, lW;

			switch (orientation)
			{
			case rbeCore::CircleConnection::coUV:
			{
				for (int i = 0; i < m_circleSegments; i++)
				{
					if (hasLast) {
						edgesList.push_back({ lU, lV, lW });
					}

					float theta = 2.f * 3.1415926f * float(i) / float(m_circleSegments);
					float u = radius * cosf(theta);
					float v = radius * sinf(theta);
					
					lU = midU + u;
					lV = midV + v;
					lW = midW;
					hasLast = true;
					edgesList.push_back({ lU, lV, lW });
				}
			}
				break;
			case rbeCore::CircleConnection::coUW:
			{
				for (int i = 0; i < m_circleSegments; i++)
				{
					if (hasLast) {
						edgesList.push_back({ lU, lV, lW });
					}

					float theta = 2.f * 3.1415926f * float(i) / float(m_circleSegments);
					float u = radius * cosf(theta);
					float w = radius * sinf(theta);

					lU = midU + u;
					lV = midV;
					lW = midW + w;
					hasLast = true;
					edgesList.push_back({ lU, lV, lW });
				}
			}
				break;
			case rbeCore::CircleConnection::coVW:
			{
				for (int i = 0; i < m_circleSegments; i++)
				{
					if (hasLast) {
						edgesList.push_back({ lU, lV, lW });
					}

					float theta = 2.f * 3.1415926f * float(i) / float(m_circleSegments);
					float v = radius * cosf(theta);
					float w = radius * sinf(theta);

					lU = midU;
					lV = midV + v;
					lW = midW + w;
					hasLast = true;
					edgesList.push_back({ lU, lV, lW });
				}
			}
				break;
			default:
				rbeAssert(0, "Invalid circle orientation");
				break;
			}
		}
		break;
		default:
			rbeAssert(0, "Not implemented connection type");
			break;
		}
	}

	// Create array
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(edgesList.size());
	size_t ct{ 0 };
	for (auto pt : edgesList) {
		vertices->at(ct++).set(pt);
	}

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	colors->push_back(osg::Vec4(m_r, m_g, m_b, 1.0f));

	// Create the geometry object to store the data
	osg::ref_ptr<osg::Geometry> newGeometry = new osg::Geometry;

	newGeometry->setVertexArray(vertices);

	newGeometry->setColorArray(colors.get());
	newGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);

	newGeometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, ct));

	//	if (depthTest) {
	//		osg::ref_ptr<osg::Material> matEdges = new osg::Material;
	//		this->setMaterialProperties(matEdges, r, g, b);
	//		newGeometry->getOrCreateStateSet()->setAttribute(matEdges.get());
	//	}

		// Now create the geometry node and assign the drawable
	m_node = new osg::Geode;
	m_node->addDrawable(newGeometry);

	// Set the display attributes for the edges geometry
	osg::StateSet *ss = m_node->getOrCreateStateSet();

	//osg::ref_ptr<osg::BlendFunc> blendFunc = new osg::BlendFunc;
	//blendFunc->setFunction(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//ss->setAttributeAndModes(blendFunc);

	ss->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	ss->setMode(GL_BLEND, osg::StateAttribute::OFF);
	ss->setAttributeAndModes(new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::LINE));
	ss->setMode(GL_LINE_SMOOTH, osg::StateAttribute::ON);
	ss->setAttribute(new osg::LineWidth(1.0), osg::StateAttribute::ON);

	if (!m_depthTest)
	{
		ss->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
		ss->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	}

	m_parentGroup->addChild(m_node);
}

void rbeWrapper::RubberbandOsgEngine::updateNode(void) {

}