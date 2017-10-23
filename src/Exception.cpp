/*
 * Exception.cpp
 *
 *  Created on: 23 ???. 2017 ?.
 *      Author: win
 */


#include "Exception.h"

Exception::Exception(std::string what)
{
	_what = what;
}

Exception::~Exception() throw()
{
}

const char *Exception::what() const throw()
{
	return _what.c_str();
}

