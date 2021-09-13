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

#pragma once

// RBE header
#include <rbeCore/dataTypes.h>

namespace rbeCore {

	class Point;
	class RubberbandEngine;

	class RBE_API_EXPORT Step {
	public:
		Step();
		virtual ~Step();

		// ###################################################################################

		// Setter

		void setId(int _id) { m_id = _id; }

		void addPoint(Point * _p);

		void givePointOwnershipToEngine(RubberbandEngine * _engine);

		// ###################################################################################

		// Getter

		int id(void) const { return m_id; }

		Point * point(int _id);

	private:
		struct sPointData;

		bool			m_pointsOwned;
		int				m_id;
		sPointData *	m_points;

		Step(Step&) = delete;
		Step& operator = (Step&) = delete;
	};

}