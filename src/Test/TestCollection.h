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
	void test1Create(void) {
		TS_TRACE("Create Collection");

		TS_ASSERT_THROWS_NOTHING((coll = new Collection<int, std::list> ));
		TS_ASSERT_THROWS_NOTHING((new Collection<int, std::vector> ));

		TS_TRACE("Finishing test created Collection");
	}

	void test2Add(void) {
		TS_TRACE("Create Collection");
		test = 0;
		coll->Append(++test);
		coll->Append(++test);
		coll->Append(++test);
		TS_TRACE("Finishing test created Collection");
	}

	void test3Iteration(void) {
		TS_TRACE("Test iterator");

		int finish = 0;
		for (coll->First(); !coll->IsDone(); coll->Next()) {
			TS_ASSERT_EQUALS(*coll->CurrentItem(), ++finish);
		}
		TS_TRACE("Finishing iterator");
	}

	void test4Clone() {
		TS_TRACE("Test clone");
		Collection<int, std::list>* clon = coll->Clone();
		clon->Append(++test);
		clon->Append(++test);
		clon->Append(++test);

		test3Iteration();
		delete(coll);

		TS_ASSERT_THROWS_ANYTHING ( test3Iteration() );

		int finish = 0;
		for (clon->First(); !clon->IsDone(); clon->Next()) {
			TS_ASSERT_EQUALS(*clon->CurrentItem(), ++finish);
		}

		TS_TRACE("Finishing clone");
	}

private:
	int test;
	Collection<int, std::list>* coll;

};

#endif /* SRC_TEST_TESTCOLLECTION_H_ */
