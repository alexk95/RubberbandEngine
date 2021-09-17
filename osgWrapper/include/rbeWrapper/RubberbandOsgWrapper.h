/*
 *	File:		RubberbandOsgWrapper.h
 *	Package:	rbeWrapper
 *
 *  Created on: September 17, 2021
 *	Author: Alexander Kuester
 *  Copyright (c) 2021 Alexander Kuester
 *	This file is part of the RubberbandEngine package.
 *	This file is subject to the terms and conditions defined in
 *	file 'LICENSE', which is part of this source code package.
 */

#pragma once

// RBE header
#include <rbeWrapper/rbeOsgWrapperDatatypes.h>
#include <rbeCore/RubberbandEngine.h>

namespace rbeWrapper {

	class RBE_OSG_API_EXPORT RubberbandOsgEngine : public rbeCore::RubberbandEngine {
	public:

		RubberbandOsgEngine(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW);
		virtual ~RubberbandOsgEngine();

		// ############################################################################################

		// Base class functions

		virtual void addPoint(rbeCore::Point * _point) override;

		virtual void replaceOrigin(coordinate_t _originU, coordinate_t _originV, coordinate_t _originW) override;

		virtual void updateCurrent(coordinate_t _currentU, coordinate_t _currentV, coordinate_t _currentW) override;

		virtual void setupFromJson(const char * _json) override;

		virtual void clear(void) override;

		virtual void activateStepOne(void) override;

		virtual void activateNextStep(void) override;

		virtual void applyCurrentStep(void) override;

	private:

	};
	
}

