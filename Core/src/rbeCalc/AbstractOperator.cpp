/*
 *	File:		AbstractOperator.cpp
 *	Package:	rbeCalc
 *
 *  Created on: September 07, 2021
 *	Author: Alexander Kuester
 *  Copyright (c) 2021 Alexander Kuester
 *	This file is part of the RubberbandEngine package.
 *	This file is subject to the terms and conditions defined in
 *	file 'LICENSE', which is part of this source code package.
 */

// RBE header
#include <rbeCalc/AbstractOperator.h>

using namespace rbeCalc;

AbstractOperator::AbstractOperator(AbstractItem * _lhv, AbstractItem * _rhv) : m_lhv(_lhv), m_rhv(_rhv) {}

AbstractOperator::~AbstractOperator() {
	if (m_lhv) delete m_lhv;
	if (m_rhv) delete m_rhv;
}

void AbstractOperator::replaceLeft(AbstractItem * _lhv) {
	if (m_lhv) delete m_lhv;
	m_lhv = _lhv;
}

void AbstractOperator::replaceRight(AbstractItem * _rhv) {
	if (m_rhv) delete m_rhv;
	m_rhv = _rhv;
}