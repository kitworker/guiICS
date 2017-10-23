/*
 * Proxy.cpp
 *
 *  Created on: 13 окт. 2017 г.
 *      Author: knik
 */

#include <assert.h>

#include "Proxy.h"
#include "../Exception.h"


Proxy::~Proxy()  {
	std::cout << "Destructor: Proxy  id = " << mId << "\n ";
}

Proxy::Proxy(int id) throw( Exception & )  {

	// need add test on unique id
	if(IsUniquenessId(id)) {
		mId = id;
		pullId.insert(mId);

	} else {
		std::cout << " double id of proxy" << "\n";
		throw ( Exception( "double" ) );

	}
	parent = 0;
	children = 0;


	std::cout << "Constructor: Proxy  id = " << id << "\n ";
}

void Proxy::SendChildren() {
	if(children != 0){
		children->SendChildren();
		// make template method ...
		DoFormChildren();

	}
}

bool Proxy::IsUniquenessId(int id) {
	return  pullId.find(id) == pullId.end();
}

void Proxy::DoFormParent() {
	//assert(! && "it bibb of Proxy");
}

void Proxy::DoFormChildren() {
	//assert(! && "it bibb of Proxy");
}
