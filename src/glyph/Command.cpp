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
char* ICommand<TContext>::PrintLog(const char* str) {

	return str;
}

template <class TContext>
MacroCommand<TContext>::MacroCommand(){

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


	std::cout << "command timer \n" ;


}
template <class TContext>
void CommandTimer<TContext>::Unexecute(TContext proxy) {
	std::cout << "uncommand timer \n" ;
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



