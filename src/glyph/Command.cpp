/*
 * Command.cpp
 *
 *  Created on: 25 ???. 2017 ?.
 *      Author: win
 */


#include "Command.h"
// Interface command
template <class TContext>
ICommand<TContext>::~ICommand() {

}
template <class TContext>
ICommand<TContext>::ICommand() {

}

template <class TContext>
void ICommand<TContext>::PrintLog(std::string str) {
	std::cout << str << " \n ";
	log =  str;
}


//MacroCommamd
namespace macroCommand {
	template <class TContext>
	void MacroCommand<TContext>::Execute(TContext context) {
		for(mCmds.First(); !mCmds.IsDone(); mCmds.Next() ){
			//*mCmds.CurrentItem()->Execute(context);
		}
	}
	template<class TContext>
	MacroCommand<TContext>::~MacroCommand() {
		ICommand<TContext>::PrintLog("delete MacroCommand");
	}
	template<class TContext>
	MacroCommand<TContext>::MacroCommand() {
		ICommand<TContext>::PrintLog("create MacroCommand");
	}
	template<class TContext>
	ICommand<TContext>* MacroCommand<TContext>::Clone() {
		ICommand<TContext>* clone = new MacroCommand<TContext>();
		clone = this;
		return clone;
	}
	template<class TContext>
	void MacroCommand<TContext>::Add(ICommand<TContext>* cmd) {
		mCmds.Append(cmd);
	}
}

// Timer client's commands
template <class TContext>
CommandTimer<TContext>::CommandTimer() {

}
template <class TContext>
CommandTimer<TContext>::~CommandTimer() {

}

template <class TContext>
void CommandTimer<TContext>::Execute(TContext proxy) { // or condition
	ICommand<TContext>::PrintLog("command timer");
}

template <class TContext>
void CommandTimer<TContext>::Unexecute(TContext proxy) {
	std::cout << "uncommand timer \n" ;
}

template <class TContext>
ICommand<TContext>* CommandTimer<TContext>::Clone()  {
	// Exist possibility make it as Template Factory Method
	//	ICommand<TContext>* clone = new T<TContext>();
	ICommand<TContext>* clone = new CommandTimer<TContext>();
	clone = this;
	return  clone;
}

template <class TContext>
ICommand<TContext>* CommandUser<TContext>::Clone()  {
	// Exist possibility make it as Template Factory Method
	//	ICommand<TContext>* clone = new T<TContext>();
	ICommand<TContext>* clone = new CommandTimer<TContext>();
	clone = this;
	return  clone;
}

//User's commands
template <class TContext>
CommandUser<TContext>::~CommandUser() {
	std::cout << "deConstructor CommandUser \n";
}
template <class TContext>
CommandUser<TContext>::CommandUser() {
	std::cout << "Constructor CommandUser \n";
}

template <class TContext>
void CommandUser<TContext>::Execute(TContext t) {
	std::cout << " undo command timer \n" ;
}
template <class TContext>
void CommandUser<TContext>::Unexecute(TContext t) {
	std::cout << " undo command timer \n" ;
}


