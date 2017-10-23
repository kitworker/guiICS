/*
 * Exception.h
 *
 *  Created on: 23 ???. 2017 ?.
 *      Author: win
 */

#ifndef SRC_EXCEPTION_H_
#define SRC_EXCEPTION_H_

#include <exception>
#include <string>

class Exception : public std::exception
{
public:
	Exception(std::string what);
	~Exception() throw();
	virtual const char *what() const throw();
private:
	std::string _what;
};



#endif /* SRC_EXCEPTION_H_ */
