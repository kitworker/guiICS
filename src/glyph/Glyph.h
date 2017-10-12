/*
 * Glyph.h
 *
 *  Created on: 9 окт. 2017 г.
 *      Author: knik
 */

#ifndef GLYPH_GLYPH_H_
#define GLYPH_GLYPH_H_

#include <iostream>
#include <list>

class Glyph {
public:
	virtual ~Glyph();
	virtual void Insert(Glyph*);

protected:
	Glyph(int proxy);
private:
	std::list<Glyph*> glyphes;
};

class Frame : public Glyph{
public:
	Frame(int proxy);

};




#endif /* GLYPH_GLYPH_H_ */
