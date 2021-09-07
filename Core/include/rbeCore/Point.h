/*
 *	File:		Point.h
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

// Project header
#include <rbeCore/dataTypes.h>

namespace rbeCalc {
	class AbstractItem;
}

namespace rbeCore {

	class RBE_API_EXPORT Point {
	public:

		Point();

		// #################################################################################################

		// Setter

		void setId(int _id) { m_id = _id; }

		// #################################################################################################

		// Getter

		int id(void) const { return m_id; }

		double x(void);

		double y(void);

		double z(void);

		double distance(const Point& _other, eAxisDistance _axis);
		
	private:
		int			m_id;
		double		m_x;
		double		m_y;
		double		m_z;


	};

}