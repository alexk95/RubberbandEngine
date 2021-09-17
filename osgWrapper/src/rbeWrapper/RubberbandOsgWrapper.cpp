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

rbeWrapper::RubberbandOsgEngine::RubberbandOsgEngine(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW)
	: rbeCore::RubberbandEngine(_originU, _originV, _originW)
{

}

rbeWrapper::RubberbandOsgEngine::~RubberbandOsgEngine() {

}

// ############################################################################################

// Base class functions

void rbeWrapper::RubberbandOsgEngine::addPoint(rbeCore::Point * _point) {

	rbeCore::RubberbandEngine::addPoint(_point);
}

void rbeWrapper::RubberbandOsgEngine::replaceOrigin(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW) {

	rbeCore::RubberbandEngine::replaceOrigin(_originU, _originV, _originW);
}

void rbeWrapper::RubberbandOsgEngine::updateCurrent(coordinate_t _currentU, coordinate_t _currentV, coordinate_t _currentW) {

	rbeCore::RubberbandEngine::updateCurrent(_currentU, _currentV, _currentW);
}

void rbeWrapper::RubberbandOsgEngine::setupFromJson(const char * _json) {

	rbeCore::RubberbandEngine::setupFromJson(_json);
}

void rbeWrapper::RubberbandOsgEngine::clear(void) {

	rbeCore::RubberbandEngine::clear();
}

void rbeWrapper::RubberbandOsgEngine::activateStepOne(void) {

	rbeCore::RubberbandEngine::activateStepOne();
}

void rbeWrapper::RubberbandOsgEngine::activateNextStep(void) {

	rbeCore::RubberbandEngine::activateNextStep();
}

void rbeWrapper::RubberbandOsgEngine::applyCurrentStep(void) {

	rbeCore::RubberbandEngine::applyCurrentStep();
}