/*
 *	File:		CircleConnection.h
 *	Package:	rbeCore
 *
 *  Created on: September 15, 2021
 *	Author: Alexander Kuester
 *  Copyright (c) 2021 Alexander Kuester
 *	This file is part of the RubberbandEngine package.
 *	This file is subject to the terms and conditions defined in
 *	file 'LICENSE', which is part of this source code package.
 */

#pragma once

// RBE header
#include <rbeCore/AbstractConnection.h>

namespace rbeCalc {
	class AbstractItem;
}

namespace rbeCore {

	class AbstractPoint;

	class RBE_API_EXPORT CircleConnection : public AbstractConnection {
	public:
		enum eCircleOrientation {
			coUV,
			coUW,
			coVW
		};

		CircleConnection();
		virtual ~CircleConnection();

		// #######################################################################################################

		// Base class functions

		virtual std::string debugInformation(const std::string& _prefix) override;

		virtual void addToJsonArray(RubberbandEngine * _engine, std::stringstream& _array, bool& _first) override;

		// #######################################################################################################

		// Setter

		void setCenterpoint(AbstractPoint * _point) { m_centerPoint = _point; }

		void setRadius(rbeCalc::AbstractItem * _radius);

		void setOrientation(eCircleOrientation _orientation) { m_orientation = _orientation; }

		// #######################################################################################################

		// Getter

		AbstractPoint * centerPoint(void) { return m_centerPoint; }

		coordinate_t radius(void) const;

		eCircleOrientation orientation(void) const { return m_orientation; }

		std::string orientationToString(void) const;

	private:

		AbstractPoint *				m_centerPoint;
		rbeCalc::AbstractItem *		m_radius;
		eCircleOrientation			m_orientation;

		CircleConnection(CircleConnection&) = delete;
		CircleConnection& operator = (CircleConnection&) = delete;
	};

}