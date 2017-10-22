/*
 * Proxy.cpp
 *
 *  Created on: 13 окт. 2017 г.
 *      Author: knik
 */

#include "Proxy.h"
#include <assert.h>

Proxy::~Proxy() {
	std::cout << "Destructor: Proxy  id = " << mId << "\n ";
}

Proxy::Proxy(int id) {

	// need add test on unique id
	if(IsUniquenessId(id)) {
		mId = id;
		pullId.insert(mId);

	} else {
		std::cout << " double id of proxy" << "\n";
		assert(! "not uniqueness id of Proxy" );
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
