/*
 *	File:		RubberbandEngine.h
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

// C++ header
#include <string>
#include <list>

namespace rbeCore {

	class Point;
	class Step;
	class AbstractConnection;
	class NumericPoint;

	class RBE_API_EXPORT RubberbandEngine {
	public:
		RubberbandEngine(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW);
		virtual ~RubberbandEngine(); 

		// #################################################################################################################

		// Getter

		NumericPoint * origin(void) { return m_origin; }
		
		NumericPoint * current(void) { return m_current; }

		Point * point(int _id);
		
		bool hasPoint(int _id);
		
		int currentStep(void) const { return m_currentStep; }
		
		bool hasStep(int _id);

		Step * step(int _id);

		std::string debugInformation(void);

		std::string connectionsJsonArray(void);

		std::list<AbstractConnection *> connectionsToDisplay(void);

		// #################################################################################################################

		// Setter

		void addPoint(Point * _point);

		void replaceOrigin(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW);

		void updateCurrent(coordinate_t _currentU, coordinate_t _currentV, coordinate_t _currentW);

		void setupFromJson(const char * _json);

		void clear(void);

		void activateStepOne(void);

		void activateNextStep(void);

		bool hasNextStep(void);
		
	private:

		struct d_data;
		d_data *						m_data;

		int								m_currentStep;
		rbeCore::NumericPoint *			m_origin;
		rbeCore::NumericPoint *			m_current;
		

		RubberbandEngine() = delete;
		RubberbandEngine(RubberbandEngine&) = delete;
		RubberbandEngine& operator = (RubberbandEngine&) = delete;
	};

}