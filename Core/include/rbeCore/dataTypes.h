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

#ifdef RUBBERBANDENGINECORE_EXPORTS
#define RBE_API_EXPORT __declspec(dllexport)
#else
#define RBE_API_EXPORT __declspec(dllimport)
#endif // RUBBERBANDENGINECORE_EXPORTS

#ifdef RBE_COORDINATE_TYPE_INT
	typedef int coordinate_t;
#else
	typedef double coordinate_t;
#endif // RBE_VALUE_TYPE_coordinate_t

#ifdef _DEBUG
	//! Requires: #include <cassert>
#define rbeAssert(___expression, ___message) (void)((!!(___expression)) || (_wassert(_CRT_WIDE(#___expression) L"\n\n" _CRT_WIDE(___message), _CRT_WIDE(__FILE__), (unsigned)__LINE__), 0))
#else
	//! Requires: #include <cassert>
#define rbeAssert(___expression, ___message)
#endif // _DEBUG


namespace rbeCore {

	enum eAxis {
		U,
		V,
		W
	};

	enum eAxisDistance {
		dAll,
		dU,
		dV,
		dW,
		dUV,
		dUW,
		dVW,
		dVU,
		dWU,
		dWV
	};
}