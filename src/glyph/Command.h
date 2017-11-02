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
	virtual char* PrintLog(const char*);
	//virtual ICommand* ICommand() = 0;

protected:
	ICommand();
};

template <class TContext>
class CommandTimer : public ICommand<TContext> {
public:
	virtual ~CommandTimer();

	CommandTimer();
	virtual void Execute(TContext);
	virtual void Unexecute(TContext);
};


template <class TContext>
class CommandUser: public ICommand<TContext> {
public:
	virtual ~CommandUser();
	CommandUser();
	virtual void Execute(TContext);
	virtual void Unexecute(TContext);
};

/* Use this class object as a branch messages parameter
 * Object command as a strategy
 *
 *
 * Execute/Unexecute Ð¿Ñ€ÐµÐ´Ð¾Ñ�Ñ‚Ð°Ð»Ñ�ÐµÑ‚ Ð´Ð¾Ñ�Ñ‚ÑƒÐ¿ ÐºÐ¾ Ð²Ñ�ÐµÐ¼ Ñ�Ð¾Ð¼Ð°Ð½Ð´Ð°Ð¼
 * Ð½Ð¾ Ð±ÑƒÐ´ÑƒÑ‚ Ð»Ð¸ Ð¾Ð½Ð¸ Ð²Ñ‹Ð¿Ð¾Ð»Ð½ÐµÐ½Ñ‹ Ñ€ÐµÑˆÐ°ÐµÑ‚ ÐºÐ¾Ð½Ñ‚ÐµÐºÑ�Ñ‚(proxy)
 *
 */
template <class TContext>
class MacroCommand : ICommand<TContext> {
public: MacroCommand();
	virtual ~MacroCommand();
	// TODO Add()... Remove()...
	virtual void Execute(TContext proxy) ;
	virtual void Unexecute(TContext);
private:
	// The collection contains the history of the commands any client
	Collection<ICommand<TContext>, std::list> mCmd;
};



#endif /* SRC_GLYPH_COMMAND_H_ */