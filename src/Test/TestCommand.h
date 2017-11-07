/*
 * TestCommand.h
 *
 *  Created on: 28 окт. 2017 г.
 *      Author: knik
 */

#ifndef SRC_TEST_TESTCOMMAND_H_
#define SRC_TEST_TESTCOMMAND_H_

#include "../Exception.cpp"
#include <cxxtest/TestSuite.h>
#include "../glyph/Command.h"
#include "../glyph/Command.cpp"


class TestCommand: public CxxTest::TestSuite {
public:
	void testCreate(void) {
		TS_TRACE("Test command timer \n");

		CommandTimer<int>* cmdTimer ;

		TS_ASSERT_THROWS_NOTHING(cmdTimer = new CommandTimer<int>());

		int proxy;
//		TS_ASSERT_THROWS_ASSERT()
		cmdTimer->Execute(1);

		TS_TRACE("Finish tested command \n");
	}


};


#endif /* SRC_TEST_TESTCOMMAND_H_ */
