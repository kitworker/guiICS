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
	void test1Create(void) {
		TS_TRACE("Test command timer \n");

		TS_ASSERT_THROWS_NOTHING(cmdTimer = new CommandTimer<int>());

		int proxy;
//		TS_ASSERT_THROWS_ASSERT()
		cmdTimer->Execute(1);

		TS_TRACE("Finish tested command \n");
	}

	void test2Clone(void) {
		TS_TRACE("Test clone command");
		ICommand<int>* clone = cmdTimer->Clone();
		TS_ASSERT_THROWS_NOTHING(cmdTimer->Execute(2));
		TS_TRACE("Finish clone command");
	}

	void test3MacroCmd(void) {
		TS_TRACE("Test create MacroCommand");

		macro = new macroCommand::MacroCommand<int>();
		macro->Execute(3);

		TS_TRACE("Finishing create MacroCommand");
	}

	void test4AddToMacroCmd(void) {
		TS_TRACE("Test function Add of Macrocommand");
		macro->Add(cmdTimer);
		macro->Execute(4);
		TS_TRACE("Finishing test function Add of Macrocommand");

	}

private:
	CommandTimer<int>* cmdTimer;
	macroCommand::MacroCommand<int>* macro;
};

#endif /* SRC_TEST_TESTCOMMAND_H_ */
