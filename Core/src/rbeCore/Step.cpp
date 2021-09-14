/*
 *	File:		Step.h
 *	Package:	rbeCore
 *
 *  Created on: September 07, 2021
 *	Author: Alexander Kuester
 *  Copyright (c) 2021 Alexander Kuester
 *	This file is part of the RubberbandEngine package.
 *	This file is subject to the terms and conditions defined in
 *	file 'LICENSE', which is part of this source code package.
 */

// RBE header
#include <rbeCore/Step.h>
#include <rbeCore/Point.h>
#include <rbeCore/RubberbandEngine.h>

// C++ header
#include <map>
#include <cassert>

using namespace rbeCore;

struct Step::sPointData {
	std::map<int, Point *>		points;
};

Step::Step()
	: m_pointsOwned(true), m_id(0)
{
	m_points = new sPointData;
}

Step::~Step() {
	if (m_pointsOwned) {
		for (auto p : m_points->points) {
			delete p.second;
		}
	}
	delete m_points;
}

// ###################################################################################

// Setter

void Step::addPoint(Point * _p) {
	if (_p == nullptr) {
		rbeAssert(0, "nullptr provided as point @Step");
		return;
	}

	if (m_points->points.find(_p->id()) != m_points->points.end()) {
		rbeAssert(0, "Point with the given id already exists @Step");
		return;
	}

	m_points->points.insert_or_assign(_p->id(), _p);
}

void Step::setupFromJson(const std::string& _json) {

}

void Step::givePointOwnershipToEngine(RubberbandEngine * _engine) {
	if (!m_pointsOwned) {
		rbeAssert(0, "Point ownership already moved to engine @Step");
		return;
	}

	for (auto p : m_points->points) {
		_engine->addPoint(p.second);
	}
	m_pointsOwned = false;
}

// ###################################################################################

// Getter

Point * Step::point(int _id) {
	auto p = m_points->points.find(_id);
	if (p == m_points->points.end()) {
		rbeAssert(0, "Point with given ID not found @Step");
		return nullptr;
	}
	return p->second;
}