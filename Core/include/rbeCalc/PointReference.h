/*
 *	File:		PointReference.h
 *	Package:	rbeCalc
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
#include <rbeCalc/AbstractItem.h>

namespace rbeCore {
	class Point;
}

namespace rbeCalc {

	class RBE_API_EXPORT PointReference : public AbstractItem {
	public:
		PointReference(rbeCore::Point * _point, rbeCore::eAxis _axis);

		virtual double value(void) override;

	private:

		rbeCore::Point *		m_point;
		rbeCore::eAxis			m_axis;

		PointReference() = delete;
		PointReference(PointReference&) = delete;
		PointReference& operator = (PointReference&) = delete;
	};

}