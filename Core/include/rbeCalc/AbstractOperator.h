/*
 *	File:		AbstractOperator.h
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

// RBE header
#include <rbeCalc/AbstractItem.h>

namespace rbeCalc {

	class RBE_API_EXPORT AbstractOperator : public AbstractItem {
	public:
		AbstractOperator(AbstractItem * _lhv = nullptr, AbstractItem * _rhv = nullptr);
		virtual ~AbstractOperator();

		AbstractItem * left(void) { return m_lhv; }

		AbstractItem * right(void) { return m_rhv; }

		void replaceLeft(AbstractItem * _lhv);

		void replaceRight(AbstractItem * _rhv);

	protected:
		AbstractItem *		m_lhv;
		AbstractItem *		m_rhv;

	private:

		AbstractOperator(AbstractOperator&) = delete;
		AbstractOperator& operator = (AbstractOperator&) = delete;
	};

}