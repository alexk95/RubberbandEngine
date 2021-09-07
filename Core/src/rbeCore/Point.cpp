/*
 *	File:		Point.cpp
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
#include <rbeCore/Point.h>

// C++ header
#include <cassert>
#include <math.h>

using namespace rbeCore;

Point::Point() : m_id(0), m_x(0.0), m_y(0.0), m_z(0.0) {}

Point::Point(double _x, double _y, double _z) : m_id(0), m_x(_x), m_y(_y), m_z(_z) {}

Point::Point(const Point& _other) : m_id(_other.m_id), m_x(_other.m_x), m_y(_other.m_y), m_z(_other.m_z) {}

Point& Point::operator = (const Point& _other) {
	m_id = _other.m_id;
	m_x = _other.m_x;
	m_y = _other.m_y;
	m_z = _other.m_z;
	return *this;
}

// #################################################################################################

// Setter

void Point::set(double _x, double _y, double _z) {
	m_x = _x;
	m_y = _y;
	m_z = _z;
}

// #################################################################################################

// Getter

double Point::distance(const Point& _other, eAxisDistance _axis) {
	double d;
	switch (_axis)
	{
	case rbeCore::All:
		d = pow(pow(m_x - _other.m_x, 2) + pow(m_y - _other.m_y, 2) + pow(m_z - _other.m_z, 2), .5);
		break;
	case rbeCore::X: d = m_x - _other.m_x; break;
	case rbeCore::Y: d = m_y - _other.m_y; break;
	case rbeCore::Z: d = m_z - _other.m_z; break;
	case rbeCore::XY:
	{
		double dx = m_x - _other.m_x;
		double dy = m_y - _other.m_y;
		if (dx < 0.) dx *= (-1);
		if (dy < 0.) dy *= (-1);
		if (dx == 0 && dy == 0) { return 0.; }
		d = sqrt(pow(dx, 2) + pow(dy, 2));
	}
		break;
	case rbeCore::XZ:
	{
		double dx = m_x - _other.m_x;
		double dz = m_z - _other.m_z;
		if (dx < 0.) dx *= (-1);
		if (dz < 0.) dz *= (-1);
		if (dx == 0 && dz == 0) { return 0.; }
		d = sqrt(pow(dx, 2) + pow(dz, 2));
	}
		break;
	case rbeCore::YZ:
	{
		double dz = m_z - _other.m_z;
		double dy = m_y - _other.m_y;
		if (dz < 0.) dz *= (-1);
		if (dy < 0.) dy *= (-1);
		if (dz == 0 && dy == 0) { return 0.; }
		d = sqrt(pow(dz, 2) + pow(dy, 2));
	}
		break;
	default:
		assert(0);
		d = 0.;
		break;
	}
	if (d < 0.) d *= (-1);
}
