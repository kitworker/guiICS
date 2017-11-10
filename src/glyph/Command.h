/*
 * Command.h
 *
 *  Created on: 25 ???. 2017 ?.
 *      Author: win
 */

#ifndef SRC_GLYPH_COMMAND_H_
#define SRC_GLYPH_COMMAND_H_

#include "../Collection.h"
#include <string>
// Unwanted using virtual function in template class
// 1) Template template <class TContext> replace on Bridge
//  ) Command as Prototype
template <class TContext>
class ICommand {
public:
	virtual ~ICommand();
	virtual void Execute(TContext) = 0;
	virtual void Unexecute(TContext) = 0;
	void PrintLog(std::string);
	virtual ICommand* Clone() = 0;
	//virtual ICommand* ICommand() = 0;

protected:
	ICommand();
private:
	std::string log;
};


template <class TContext>
class CommandTimer : public ICommand<TContext> {
public:
	virtual ~CommandTimer();

	CommandTimer();
	virtual void Execute(TContext);
	virtual void Unexecute(TContext);
	virtual ICommand<TContext>* Clone();
};


template <class TContext>
class CommandUser: public ICommand<TContext> {
public:
	virtual ~CommandUser();
	CommandUser();
	virtual void Execute(TContext);
	virtual void Unexecute(TContext);
	virtual ICommand<TContext>* Clone();
};

namespace macroCommand {
/* Use this class object as a branch messages parameter
 * Object command as a strategy
 *
 *
 * Execute/Unexecute Ã�Â¿Ã‘â‚¬Ã�ÂµÃ�Â´Ã�Â¾Ã‘ï¿½Ã‘â€šÃ�Â°Ã�Â»Ã‘ï¿½Ã�ÂµÃ‘â€š Ã�Â´Ã�Â¾Ã‘ï¿½Ã‘â€šÃ‘Æ’Ã�Â¿ Ã�ÂºÃ�Â¾ Ã�Â²Ã‘ï¿½Ã�ÂµÃ�Â¼ Ã‘ï¿½Ã�Â¾Ã�Â¼Ã�Â°Ã�Â½Ã�Â´Ã�Â°Ã�Â¼
 * Ã�Â½Ã�Â¾ Ã�Â±Ã‘Æ’Ã�Â´Ã‘Æ’Ã‘â€š Ã�Â»Ã�Â¸ Ã�Â¾Ã�Â½Ã�Â¸ Ã�Â²Ã‘â€¹Ã�Â¿Ã�Â¾Ã�Â»Ã�Â½Ã�ÂµÃ�Â½Ã‘â€¹ Ã‘â‚¬Ã�ÂµÃ‘Ë†Ã�Â°Ã�ÂµÃ‘â€š Ã�ÂºÃ�Â¾Ã�Â½Ã‘â€šÃ�ÂµÃ�ÂºÃ‘ï¿½Ã‘â€š(proxy)
 *
 */
template<class TContext>
class MacroCommand: ICommand<TContext> {
public:
	virtual ~MacroCommand();
	MacroCommand();
	virtual void Execute(TContext proxy);
	virtual void Unexecute(TContext);
	virtual ICommand<TContext>* Clone();
	virtual void Add(ICommand<TContext> *);
private:
	// The collection contains the history of the commands any client
	Collection<ICommand<TContext>*, std::list> mCmds;
};
}


#endif /* SRC_GLYPH_COMMAND_H_ */
