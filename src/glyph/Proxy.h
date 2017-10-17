/*
 * Proxy.h
 *
 *  Created on: 9 окт. 2017 г.
 *      Author: knik
 */

#ifndef GLYPH_PROXY_H_
#define GLYPH_PROXY_H_

#include <iostream>
#include <set>

enum IdGlyph {
	// Static >= 0  /* it comfortable for ABN_ of Photon */

	// Dynamic  < 0
};


class BrenchMsg {
	// state -2 -1 0 1 2 ...
	// Direction
	// Template parameter for data
	// and need Don't forget of Leaf item in composition

	// Maybe will  need
};

class Proxy {
public:
	virtual ~Proxy();
	void SendParent();
	void SendChildren();


	virtual void DoFormParent(/* BrenchMsg * */) = 0;
	virtual void DoFormChildren(/*-2 -1 0 1 2*/) = 0;


private:
	Proxy(int id) ;
	int mId;
	Proxy* parent;
	Proxy* children;

	// test uniqueness id
	std::set<int> pullId;
	bool IsUniquenessId(int id);
};


#endif /* GLYPH_PROXY_H_ */
