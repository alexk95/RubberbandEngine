/*
 *	File:		RubberbandEngine.cpp
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
#include <rbeCore/RubberbandEngine.h>
#include <rbeCore/Point.h>
#include <rbeCore/NumericPoint.h>
#include <rbeCore/Step.h>

// rapidjson
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

// C++ header
#include <cassert>
#include <map>
#include <vector>
#include <string>

using namespace rbeCore;

struct RubberbandEngine::d_data {
	std::map<int, rbeCore::Point *>	points;
	std::map<int, std::pair<Step *, std::string>> steps;
};

RubberbandEngine::RubberbandEngine(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW)
	: m_origin(nullptr), m_current(nullptr), m_currentStep(0) {

	m_origin = new NumericPoint(_originU, _originV, _originW);
	m_current = new NumericPoint(_originU, _originV, _originW);

	m_data = new d_data;
}

RubberbandEngine::~RubberbandEngine() {
	clear();
	delete m_data;
}

// #################################################################################################################

// Getter

Point * RubberbandEngine::point(int _id) {
	auto p = m_data->points.find(_id);
	if (p == m_data->points.end()) {
		rbeAssert(0, "Provided point ID not found @RubberbandEngine");
		return nullptr;
	}
	return p->second;
}

std::string RubberbandEngine::debugInformation(void) {
	std::string ret{ "RubberbandEngine -  Data\n{\n\t\"Origin\": " };
	ret.append(m_origin->debugInformation("\t"));
	ret.append(",\n\t\"Current\": ");
	ret.append(m_current->debugInformation("\t"));
	ret.append(",\n\t\"Points\": [");

	bool first{ true };
	for (auto p : m_data->points) {
		if (first) { ret.append("\n\t\t"); first = false; }
		else { ret.append(",\n\t\t"); }
		ret.append(p.second->debugInformation("\t\t"));
	}

	ret.append("\n\t],\n\t\"Steps\": [");
	first = true;
	for (auto s : m_data->steps) {
		if (first) {
			ret.append("\n\t\t"); first = false;
		}
		else {
			ret.append(",\n\t\t");
		}
		if (s.second.first) {

		}
		else {
			ret.append("{\n\t\t\t\"ID\": ");
			ret.append(std::to_string(s.first));
			ret.append(",\n\t\t\t\t\"json\": \"");
			ret.append(s.second.second).append("\n\t\t\t}");
		}
	}
	ret.append("\n\t]\n}");
	return ret;
}

// #################################################################################################################

// Setter

void RubberbandEngine::addPoint(Point * _point) {
	if (_point) {
		auto p = m_data->points.find(_point->id());
		if (p == m_data->points.end()) {
			m_data->points.insert_or_assign(_point->id(), _point);
		}
		else {
			rbeAssert(0, "Provided point ID already in use @RubberbandEngine");
		}
	}
	else {
		rbeAssert(0, "nullptr provided to addPoint @RubberbandEngine");
	}
}

void RubberbandEngine::replaceOrigin(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW) {
	m_origin->set(_originU, _originV, _originW);
}

void RubberbandEngine::updateCurrent(coordinate_t _currentU, coordinate_t _currentV, coordinate_t _currentW) {
	m_current->set(_currentU, _currentV, _currentW);
}

void RubberbandEngine::setupFromJson(const char * _json) {
	clear();

	if (_json == nullptr) {
		rbeAssert(0, "No json string provided @RubberbandEngine");
		return;
	}

	rapidjson::Document doc;
	doc.Parse(_json);

	if (!doc.IsObject()) {
		rbeAssert(0, "Invalid JSON format: Document is not an object"); return;
	}
	if (!doc.HasMember("RubberBandSteps")) {
		rbeAssert(0, "Invalid JSON format: Document has no Steps"); return;
	}
	if (!doc["RubberbandSteps"].IsArray()) {
		rbeAssert(0, "Invalid JSON format: Steps data is not an array"); return;
	}

	auto stepsData = doc["RubberbandSteps"].GetArray();
	
	for (rapidjson::SizeType i{ 0 }; i < stepsData.Size(); i++) {
		if (!stepsData[i].IsObject()) {
			rbeAssert(0, "Invalid JSON format: Step entry is not an object"); return;
		}
		auto sObj = stepsData[i].GetObject();

		if (!sObj.HasMember("Step")) {
			rbeAssert(0, "Invalid JSON format: Step id is missing"); return;
		}
		else if (!sObj["Step"].IsInt()) {
			rbeAssert(0, "Invalid JSON format: Step id format is invalid"); return;
		}
		int id = sObj["Step"].GetInt();

		rapidjson::Document sDoc;
		sDoc.Set(sObj);

		rapidjson::StringBuffer buffer;
		buffer.Clear();

		// Setup the Writer
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		sDoc.Accept(writer);

		// Return string
		m_data->steps.insert_or_assign(id, std::pair<Step *, std::string>(nullptr, buffer.GetString()));
	}

}

void RubberbandEngine::clear(void) {
	for (auto p : m_data->points) {
		delete p.second;
	}
	m_data->points.clear();

	if (m_origin) { delete m_origin; } m_origin = nullptr;
	if (m_current) { delete m_current; } m_current = nullptr;

}