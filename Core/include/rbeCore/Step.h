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

// C++ header
#include <string>
#include <list>
#include <sstream>

namespace rbeCore {

	class Point;
	class RubberbandEngine;
	class AbstractConnection;

	class RBE_API_EXPORT Step {
	public:

		enum eProjection {
			pUV,
			pW
		};

		Step();
		virtual ~Step();

		// ###################################################################################

		// Setter

		void setId(int _id) { m_id = _id; }

		void setMayEndWithout(bool _mayEnd) { m_mayEndWithout = _mayEnd; }

		void setProjection(eProjection _projection) { m_projection = _projection; }

		void addPoint(Point * _p);

		void setupFromJson(RubberbandEngine * _engine, const std::string& _json);

		void givePointOwnershipToEngine(RubberbandEngine * _engine);

		// ###################################################################################

		// Getter

		int id(void) const { return m_id; }

		bool mayEndWithout(void) const { return m_mayEndWithout; }

		eProjection projection(void) const { return m_projection; }

		Point * point(int _id);

		bool hasPoint(int _id);

		std::string debugInformation(const std::string& _prefix);

		void addConnectionsToJsonArray(RubberbandEngine * _engine, std::stringstream& _array, bool& _first, bool _isHistory);

		void addConnectionsToList(std::list<AbstractConnection *>& _list, bool _isHistory);

	private:
		struct sData;

		bool			m_pointsOwned;
		bool			m_mayEndWithout;
		int				m_id;
		sData *			m_data;
		eProjection		m_projection;

		Step(Step&) = delete;
		Step& operator = (Step&) = delete;
	};

}