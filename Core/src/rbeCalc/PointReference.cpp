/*
 *	File:		PointReference.cpp
 *	Package:	rbeCalc
 *
 *  Created on: September 07, 2021
 *	Author: Alexander Kuester
 *  Copyright (c) 2021 Alexander Kuester
 *	This file is part of the RubberbandEngine package.
 *	This file is subject to the terms and conditions defined in
 *	file 'LICENSE', which is part of this source code package.
 */
 
 // RBE header
#include <rbeCalc/PointReference.h>
#include <rbeCore/Point.h>

// C++ header
#include <cassert>

using namespace rbeCalc;

PointReference::PointReference(rbeCore::Point * _point, rbeCore::eAxis _axis)
	: m_point(_point), m_axis(_axis) {}

double PointReference::value(void) {
	switch (m_axis)
	{
	case rbeCore::X: return m_point->x();
	case rbeCore::Y: return m_point->y();
	case rbeCore::Z: return m_point->z();
	default:
		assert(0);
		return 0.;
	}
}