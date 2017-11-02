/*
 * TestCollection.h
 *
 *  Created on: 25 ???. 2017 ?.
 *      Author: win
 */

#ifndef SRC_TEST_TESTCOLLECTION_H_
#define SRC_TEST_TESTCOLLECTION_H_

#include <cxxtest/TestSuite.h>

#include "../Exception.h"
#include "../Collection.h"

class TestCollection: public CxxTest::TestSuite {
public:
	void testCreate(void){
		TS_TRACE("Create Collection");


		TS_ASSERT_THROWS_NOTHING( (coll = new Collection<int, std::list>) );
		TS_ASSERT_THROWS_NOTHING( (new  Collection<int, std::vector>) );

		TS_TRACE("Finishing test created Collection");
	}

	void testAdd(void) {
		TS_TRACE("Create Collection");
		coll->Append(1);
		coll->Append(2);
		coll->Append(3);
		TS_TRACE("Finishing test created Collection");
	}

	void testIteration(void) {

		int finish = -1;
		for (coll->First(); !coll->IsDone(); coll->Next()) {
			finish = *coll->CurrentItem();
		}
		TS_ASSERT_EQUALS(finish, 3);
	}

	void testClone(void) {
		TS_TRACE("Test clone collection");

		TS_ASSERT_THROWS_NOTHING( cloneColl = coll->Clone() );

		cloneColl->Append(4);
		cloneColl->Append(5);
		cloneColl->Append(6);

//		coll->Append(-1); // test of test

		testIteration();
		TS_TRACE("Finishing test clone collection");
	}

	void test5IterCloneColl(void) {

		int finish = -1;

		coll->First();

		TS_ASSERT_EQUALS(  *coll->CurrentItem(), 1 );

		for (; !coll->IsDone(); coll->Next()) {
			finish = *coll->CurrentItem();
		}

		TS_ASSERT_EQUALS(finish, 6);
	}

private:
	Collection<int, std:: list> *coll;
	Collection<int, std:: list> *cloneColl;


};

#endif /* SRC_TEST_TESTCOLLECTION_H_ */
