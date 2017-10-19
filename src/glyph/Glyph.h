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

// for strategyComposer push to container
// for strategyLeaf make algorithm of BreachMsg ( ProcessStateOfMsg -2 -1 0 1 2) That call it?
class Glyph {
public:
	virtual ~Glyph();
	virtual void Insert(Glyph*);  // make like strategyComposer->insert  / strategyLeaf->insert() (generation exception???), but it strategies
								  // should make as orthogonality

protected:
	Glyph(int proxy);			  // when we can using Glyph(int proxy, strategy = strategyLeaf  )  for default
private:
	std::list<Glyph*> glyphes;
};

class Frame : public Glyph{
public:
	Frame(int proxy);

};

class TestTest {
public:
	TestTest();
};



#endif /* GLYPH_GLYPH_H_ */
