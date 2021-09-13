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
#include <rbeCore/AbstractPoint.h>

namespace rbeCalc {
	class AbstractItem;
}

namespace rbeCore {

	class RBE_API_EXPORT Point : public AbstractPoint {
	public:

		Point();
		Point(rbeCalc::AbstractItem * _u, rbeCalc::AbstractItem * _v, rbeCalc::AbstractItem * _w);
		virtual ~Point();

		// #################################################################################################

		// Setter

		void replaceU(rbeCalc::AbstractItem * _u);

		void replaceV(rbeCalc::AbstractItem * _v);

		void replaceW(rbeCalc::AbstractItem * _w);

		// #################################################################################################

		// Getter
		
		virtual coordinate_t u(void) const override;

		virtual coordinate_t v(void) const override;

		virtual coordinate_t w(void) const override;

	private:
		rbeCalc::AbstractItem *		m_u;
		rbeCalc::AbstractItem *		m_v;
		rbeCalc::AbstractItem *		m_w;

		Point(Point&) = delete;
		Point& operator = (Point&) = delete;
	};

}