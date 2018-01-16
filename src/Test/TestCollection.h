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

	void test5_1CloneOnHeap(void) {
		TS_TRACE("Test cloning collection in heap ");
		clonColl = new SharedMyColl( (*coll)->Clone() );
//		delete & (*clonColl);
		// TODO That is deleted?
		SharedMyColl* locaClonColl = new SharedMyColl( (*coll)->Clone() );
		TS_TRACE("Finishing  test cloning collection in heap ");
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

		//  TODO That is show, if SharedMyColl* locaClonColl exit?
		MyForeach(*clonColl);
		TS_TRACE(" after delete element");
		//(*clonColl)->DeleteCurrent();

		TS_TRACE("Finishing Test delete element collection");
	}
	/*********************************/

	void test8CreateSempleColl(void) {
		TS_TRACE(" Test create collection less shared_ptr");
		// old
		myColl* smpColl = new myColl();
		MyClass* m0 = new MyClass(0, 0);
		smpColl->Append(*m0);
		TS_TRACE("Finishing Test create collection less shared_ptr");
	}

	void test8_1CreateSempleColl(void) {
		TS_TRACE(" Test create collection with shared_ptr");
		//new using shared_ptr
		SharedMyColl alisSharColl;
		alisSharColl = std::make_shared<myColl>();
		MyClass* m0 = new MyClass(0, 0);
		alisSharColl->Append(*m0);
		TS_TRACE("Finishing Test create collection with shared_ptr");
	}

	void test9Clone(void) {
		TS_TRACE(" Test 9 ");
		SharedMyColl alisSharColl;
		alisSharColl = std::make_shared<myColl>();
		AddItemTo(alisSharColl, 1);

		SharedMyColl clonSharColl( alisSharColl->Clone() );
		AddItemTo(clonSharColl, 2);
	}
//
	void test10DeleteForSempleColl(void) {  // less a shared_ptr, because need delete m0
		myColl* smpColl = new myColl();
		MyClass* m0 = new MyClass(0, 1);
		smpColl->Append(*m0);
		delete m0; // because was occur copy the object to container
		smpColl->Append( MyClass(1, 1));
		smpColl->Append( MyClass(2, 1));
		smpColl->First();
		smpColl->DeleteCurrent();
	//	smpColl->Next(); // jump over object 1
		smpColl->DeleteCurrent();
		smpColl->DeleteCurrent();
		smpColl->DeleteCurrent();

		for ( smpColl->First(); !smpColl->IsDone(); smpColl->Next()) {
				MyClass* m = smpColl->CurrentItem();
				std::cout << m->GetNumber() << "\n";
		}
	}

	void test11RevertIterator(void) {  // less a shared_ptr, because need delete m0
		myColl* smpColl = new myColl();
		MyClass* m0 = new MyClass(0, 1);
		smpColl->Append(*m0);
		delete m0; // because was occur copy the object to container
		smpColl->Append( MyClass(1, 1));
		smpColl->Append( MyClass(2, 1));
		smpColl->First();
		smpColl->DeleteCurrent();
	//	smpColl->Next(); // jump over object 1
		smpColl->DeleteCurrent();
		smpColl->DeleteCurrent();
		smpColl->DeleteCurrent();

		smpColl->End();

//		for ( smpColl->End(); !smpColl->IsHead(); smpColl->Prev()) {
//				MyClass* m = smpColl->CurrentItem();
//				std::cout << m->GetNumber() << "\n";
//		}
	}


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

private:
	SharedMyColl* coll;
	SharedMyColl* clonColl;
	int test;


};

#endif /* SRC_TEST_TESTCOLLECTION_H_ */
