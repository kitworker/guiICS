/*
 * Proxy.h
 *
 *  Created on: 9 окт. 2017 г.
 *      Author: knik
 */

#ifndef GLYPH_PROXY_H_
#define GLYPH_PROXY_H_

#include <iostream>
#include <set>

// MyTestSuite1.h
#include <cxxtest/TestSuite.h>

class MyTestSuite1 : public CxxTest::TestSuite
{
public:
    void testAddition(void)
    {
        TS_ASSERT(1 - 1 > 1);
        TS_ASSERT_EQUALS(1 + 1, 2);
    }
};


#endif /* GLYPH_PROXY_H_ */
