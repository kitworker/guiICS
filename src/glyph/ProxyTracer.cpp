/*
 * Proxy.cpp
 *
 *  Created on: 13 окт. 2017 г.
 *      Author: knik
 */

#include "ProxyTracer.h"

#include <assert.h>

#include "../Exception.h"


ProxyTracer::~ProxyTracer()  {
	std::cout << "Destructor: Proxy  id = " << mId << "\n ";
	//TODO maybe delete form set  pullId.erase(mId);? when not ready not using id

}

ProxyTracer::ProxyTracer(int id) throw( Exception & )  {

	// need add test on unique id
	if(IsUniquenessId(id)) {
		mId = id;
		pullId.insert(mId);

	} else {
		std::cout << " double id of proxy" << "\n";
		throw ( Exception("double") );

	}
	parent = 0;
	children = 0;

	std::cout << "\nConstructor: Proxy  id = " << id << "\n ";
}

void ProxyTracer::SendChildren() {
	if(children != 0){
		children->SendChildren();
		//old make template method ...
		//DoFormChildren();

		// need object Presenter

	}
}

bool ProxyTracer::IsUniquenessId(int id) {
	return  pullId.find(id) == pullId.end();
}


