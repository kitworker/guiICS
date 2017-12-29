/*
 * TestCollection.h
 *
 *  Created on: 25 ???. 2017 ?.
 *      Author: win
 */

#ifndef SRC_TEST_TESTCOLLECTION_H_
#define SRC_TEST_TESTCOLLECTION_H_

#include <cxxtest/TestSuite.h>

#include <memory>

#include "../Exception.h"
#include "../Collection.h"

class MyClass {
public:
	MyClass(const int numIter, int const idColl) :
			numObj(numIter), log(" "), mIdColl(idColl) {
		log = "Creating MyClass object " + std::to_string(numObj)
				+ " of collection " + std::to_string(idColl);
		cout << log << endl;
	}
	virtual ~MyClass() {
		log = "Destroying MyClass object  " + std::to_string(numObj)
				+ " of collection " + std::to_string(mIdColl);
		cout << log << endl;
	}
	void method() {
		log = "Called method of MyClass object";
		cout << log << endl;
		numObj *= 10;
	}
	int GetNumber(void) {
		return numObj;
	}

private:
	int numObj;
	std::string log;
	int mIdColl;
};

class TestCollection: public CxxTest::TestSuite {
public:


	//typedef typename std::shared_ptr<MyClass> SharedMyClass;
	typedef Collection<MyClass, list> myColl;
	typedef typename std::shared_ptr<myColl> SharedMyColl;

	void test1Create(void) {
		TS_TRACE("Create Collection");

		TS_ASSERT_THROWS_NOTHING( coll = new SharedMyColl( new myColl()) );
		TS_ASSERT_THROWS_NOTHING(new myColl() );

		TS_TRACE("Finishing test created Collection");
	}

	void test2Add(void) {
		TS_TRACE("Create Collection");

		AddItemTo(*coll, 1);
		AddItemTo(*coll, 1);
		AddItemTo(*coll, 1);

		TS_TRACE("Finishing test created Collection");
	}

	void test3Iteration(void) {
		TS_TRACE("Test iterator");

		MyForeach(*coll);

		TS_TRACE("Finishing iterator");
	}

	void test4Clone() {
		TS_TRACE("Test clone the collection");
		// clone
		SharedMyColl clon((*coll)->Clone());

		//ActionChange(*coll); // when will be changed global pointer coll, and over tests retinue errors
		AddItemTo(clon, 2);
		MyForeach(clon);

		// clone of clone
		SharedMyColl clonClon(clon->Clone());
		ActionChange(clon);
		AddItemTo(clonClon, 3);
		MyForeach(clonClon);

		test3Iteration();

		//MyForeach(clon); // is changed

		TS_TRACE("Finishing clone the collection");
	}

	void test5DeletColl(void) {
		TS_TRACE("Test delete collection");

		delete &(*coll);	// very impotent
		//MyForeach(*coll);	// bad test

		TS_TRACE("Finishing Test delete collection");
	}

	void test6LocalColl(void) {
		TS_TRACE(" Test work shared_ptr local collection");

		SharedMyColl loc(new myColl());
		AddItemTo(loc, 3);
		AddItemTo(loc, 3);
		AddItemTo(loc, 3);

		TS_TRACE("Finishing Test work shared_ptr local collection");
	}

	void test7DeleteElementColl(void) {
		TS_TRACE(" Test delete element collection");

		SharedMyColl loc(new myColl());
		AddItemTo(loc, 4);
		AddItemTo(loc, 4);
		AddItemTo(loc, 4);
	//	loc->DeleteCurrent();
		MyForeach(loc);

		TS_TRACE("Finishing Test delete element collection");
	}

private:
	SharedMyColl* coll;
	int test;

	void MyForeach(SharedMyColl coll) {
		int finish = 0;
		for (coll->First(); !coll->IsDone(); coll->Next()) {
			MyClass *m = coll->CurrentItem();
			std::cout << m->GetNumber() << "\n";
			TS_ASSERT_EQUALS(m->GetNumber(), ++finish);
		}
	}

	void AddItemTo(SharedMyColl coll, int const idColl) {
		MyClass* m1 = new MyClass(++test, idColl); //TODO this memory interested
		coll->Append(*m1);
	}

	void ActionChange(SharedMyColl coll) {
		for (coll->First(); !coll->IsDone(); coll->Next()) {
			MyClass* m = coll->CurrentItem();
			m->method();
		}
	}

};

#endif /* SRC_TEST_TESTCOLLECTION_H_ */
