/*
 * Proto.h
 *
 *  Created on: 9 окт. 2017 г.
 *      Author: knik
 */

#ifndef GLYPH_PROTO_H_
#define GLYPH_PROTO_H_

#include "Glyph.h"
#include "Builder.h"

class Proto {
public:
	Proto();

	Glyph* Clone()=0;
	void Init();
	Builder* GetBuilder()=0;


};



#endif /* GLYPH_PROTO_H_ */
