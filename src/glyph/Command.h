/*
 * Command.h
 *
 *  Created on: 25 ???. 2017 ?.
 *      Author: win
 */

#ifndef SRC_GLYPH_COMMAND_H_
#define SRC_GLYPH_COMMAND_H_

#include "../Collection.h"

template <class TContext>
class ICommand {
public:
	virtual ~ICommand();
	virtual void Execute(TContext) = 0;
	virtual void Unexecute(TContext) = 0;

protected:
	ICommand();
};

template <class TContext>
class CommandTimer {

};

/* Use this class object as a branch messages parameter
 * Object command as a strategy
 */
template <class TContext>
class MacroCommand : ICommand<TContext> {
public: MacroCommand();
	virtual ~MacroCommand();
	virtual void Execute(TContext) ;
	virtual void Unexecute(TContext);
private:
	// The collection contains the history of the commands any client
	Collection<ICommand<TContext>, std::list> mCmd;

};



#endif /* SRC_GLYPH_COMMAND_H_ */
