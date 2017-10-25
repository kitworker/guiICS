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


#include "../Exception.h"


#include "Command.h"

enum IdGlyph {
	// Static >= 0  /* it comfortable for ABN_ of Photon */

	// Dynamic  < 0
};



/*
 * The class represent the wrapper for macro-commands
 * as pattern state
 */
class BrenchMsg {
	// state -2 -1 0 1 2 ...

	// Direction:
	/*
	 *\param formChild
	 *\param fromParent
	 */
private:
	// Commands
	/*
	 * Commands have mast run execute and unexecute for test
	 */


	//
	// Template parameter for data
	// and need Don't forget of Leaf item in composition


};
//
class ProxyTracer {
public:
	virtual ~ProxyTracer();
	void SendParent(/* BrenchMsg * */);
	void SendChildren(/*-2 -1 0 1 2*/);


	ProxyTracer(int id)  throw( Exception & ) ;

protected:
// it's comment about there  duplicated  function Handler() of presenter
//	virtual void DoFormParent(/* BrenchMsg * */);
//	virtual void DoFormChildren(/*-2 -1 0 1 2*/);

private:
	int mId;
	ProxyTracer* parent;
	ProxyTracer* children;

	// test uniqueness id
	static std::set<int> pullId;
 	static bool IsUniquenessId(int id);
};

std::set<int> ProxyTracer::pullId;

#endif /* GLYPH_PROXY_H_ */
