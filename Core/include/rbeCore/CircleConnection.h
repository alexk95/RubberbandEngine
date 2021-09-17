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

namespace rbeCore {

	class RBE_API_EXPORT CircleConnection : public AbstractConnection {
	public:
		CircleConnection();
		virtual ~CircleConnection();

		// ###############################################################################

		// Base class functions

		virtual std::string debugInformation(const std::string& _prefix) override;

		virtual void addToJsonArray(RubberbandEngine * _engine, std::stringstream& _array, bool& _first) override;

	private:


		CircleConnection(CircleConnection&) = delete;
		CircleConnection& operator = (CircleConnection&) = delete;
	};

}