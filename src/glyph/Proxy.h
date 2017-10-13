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

class Proxy {
public:
	virtual ~Proxy();
	void SendParent();
	void SendChildren();


	virtual void DoFormParent(/*-2 -1 0 1 2*/) = 0;
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
