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
class TracerTree : public ProxyTracer {
public:
	virtual ~TracerTree();
	TracerTree();
	virtual void Handler();
	virtual void Action();

};


#endif /* GLYPH_TRACERTREE_H_ */
