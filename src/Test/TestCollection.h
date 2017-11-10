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
	MyClass(const int numIter) :
			iterator(numIter), log(" ") {
		log = "Creating MyClass object " + std::to_string(iterator);
		cout << log << endl;
	}
	virtual ~MyClass() {
		log = "Destroying MyClass object  " + std::to_string(iterator);
		cout << log << endl;
	}
	void method() {
		log = "Called method of MyClass object";
		cout << log << endl;
	}
	int GetItertor(void) {
		return iterator;
	}

private:
	int iterator;
	std::string log;
};


class TestCollection: public CxxTest::TestSuite {
public:


	typedef typename std::shared_ptr<MyClass> SharedMyClass;
	void test1Create(void) {
		TS_TRACE("Create Collection");

		TS_ASSERT_THROWS_NOTHING((coll = new Collection<SharedMyClass, std::list> ));
		TS_ASSERT_THROWS_NOTHING((new Collection<SharedMyClass, std::vector> ));

		TS_TRACE("Finishing test created Collection");
	}

	void test2Add(void) {
		TS_TRACE("Create Collection");

		AddItemTo(coll);
		AddItemTo(coll);
		AddItemTo(coll);

		TS_TRACE("Finishing test created Collection");
	}

	void test3Iteration(void) {
		TS_TRACE("Test iterator");

		MyForeach(coll);

		TS_TRACE("Finishing iterator");
	}

	void test4Clone() {
		TS_TRACE("Test clone the collection");
		Collection<SharedMyClass, std::list>* clon = coll->Clone();

		AddItemTo(clon);
		AddItemTo(clon);
		AddItemTo(clon);


		test3Iteration();
//		delete(coll);
//		TS_ASSERT_THROWS_ANYTHING ( test3Iteration() );

		MyForeach(clon);
		delete clon;

		TS_TRACE("Finishing clone the collection");
	}

	void test5DeletColl(void) {
		TS_TRACE("Test delete collection");
		delete coll;

	//	MyForeach(coll);

		TS_TRACE("Finishing Test delete collection");
	}

	void test6LocalColl(void) {
		TS_TRACE(" Test work shared_ptr local collection");

		Collection<SharedMyClass, std::list>* loc = new Collection<
				   SharedMyClass, std::list>();

		AddItemTo(loc);
		AddItemTo(loc);
		AddItemTo(loc);

		TS_TRACE("Finishing Test work shared_ptr local collection");
	}

private:
	Collection<SharedMyClass, std::list>* coll;
	int test;

	void MyForeach(Collection<SharedMyClass, std::list> *coll){
		int finish = 0;
		for (coll->First(); !coll->IsDone(); coll->Next()) {
			SharedMyClass *m = coll->CurrentItem();
			std::cout << (*m)->GetItertor() << "\n";
			TS_ASSERT_EQUALS((*m)->GetItertor(), ++finish);
		}
	}

	void AddItemTo(Collection<SharedMyClass, std::list> *coll){
		SharedMyClass m1(new MyClass(++test) );
		coll->Append(m1);
	}
};

#endif /* SRC_TEST_TESTCOLLECTION_H_ */
