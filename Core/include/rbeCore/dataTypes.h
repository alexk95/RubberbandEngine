/*
 *	File:		dataTypes.h
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

#define RBE_API_EXPORT __declspec(dllexport)

namespace rbeCore {

	enum eAxis {
		X,
		Y,
		Z
	};

	enum eAxisDistance {
		All,
		X,
		Y,
		Z,
		XY,
		XZ,
		YZ
	};
}