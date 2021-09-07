/*
 *	File:		NumericPoint.h
 *	Package:	rbeCore
 *
 *  Created on: September 07, 2021
 *	Author: Alexander Kuester
 *  Copyright (c) 2021 Alexander Kuester
 *	This file is part of the RubberbandEngine package.
 *	This file is subject to the terms and conditions defined in
 *	file 'LICENSE', which is part of this source code package.
 */

#pragma once

// RBE header
#include <rbeCore/dataTypes.h>

namespace rbeCore {

	class RBE_API_EXPORT NumericPoint {
	public:
		NumericPoint();
		NumericPoint(double _x, double _y, double _z);
		virtual ~NumericPoint();

		// ################################################################################

		// Setter

		void set(double _x, double _y, double _z);

		void setX(double _x) { m_x = _x; }

		void setY(double _y) { m_y = _y; }

		void setZ(double _z) { m_z = _z; }
		
		// ################################################################################

		// Getter

		double x(void) const { return m_x; }

		double y(void) const { return m_y; }

		double z(void) const { return m_z; }

	private:
		double		m_x;
		double		m_y;
		double		m_z;
	};

}