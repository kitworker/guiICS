/*
 * TracerTree.h
 *
 *  Created on: 9 окт. 2017 г.
 *      Author: knik
 */

#ifndef GLYPH_TRACERTREE_H_
#define GLYPH_TRACERTREE_H_

#include "ProxyTracer.h"

// Interface strategy tracking
class Pesenter : public ProxyTracer {
public:
	virtual ~Pesenter();
	Pesenter();
	virtual void Handler();
	virtual void Action();

	// TODO need relies
	//! Any commands  correpondetion own strategies



};


#endif /* GLYPH_TRACERTREE_H_ */
