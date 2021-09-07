/*
 *	File:		VariableValue.h
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

#include <rbeCalc/AbstractItem.h>

namespace rbeCalc {

	class RBE_API_EXPORT VariableValue : public AbstractItem {
	public:
		VariableValue() {}
		VariableValue(double _v) : m_value(_v) {}
		virtual ~VariableValue() {}

		virtual double value(void) override { return m_value; }

		void setValue(double _v) { m_value = _v; }

	private:

		double		m_value;

	};

}