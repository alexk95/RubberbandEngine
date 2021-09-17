/*
 *	File:		CircleConnection.cpp
 *	Package:	rbeCore
 *
 *  Created on: September 15, 2021
 *	Author: Alexander Kuester
 *  Copyright (c) 2021 Alexander Kuester
 *	This file is part of the RubberbandEngine package.
 *	This file is subject to the terms and conditions defined in
 *	file 'LICENSE', which is part of this source code package.
 */

// RBE header
#include <rbeCore/CircleConnection.h>
#include <rbeCore/jsonMember.h>

rbeCore::CircleConnection::CircleConnection()
	: AbstractConnection(ctCircle)
{

}

rbeCore::CircleConnection::~CircleConnection() {

}

// ###############################################################################

// Base class functions

std::string rbeCore::CircleConnection::debugInformation(const std::string& _prefix) {
	std::string ret{ "{\n" };
	ret.append(_prefix).append("\t\"" RBE_JSON_CONNECTION_Type "\": \"" RBE_JSON_VALUE_ConnectionType_Circle "\"");



	ret.append("\n").append(_prefix).append("}");
	return ret;
}

void rbeCore::CircleConnection::addToJsonArray(RubberbandEngine * _engine, std::stringstream& _array, bool& _first) {
	if (_first) { _first = false; }
	else { _array << ","; }
	_array << "{\"" RBE_JSON_CONNECTION_Type "\":\"" RBE_JSON_VALUE_ConnectionType_Circle "\"";
	
	_array << "}";
}