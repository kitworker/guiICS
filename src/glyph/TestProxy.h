/*
 * TestProxy.h
 *
 *  Created on: 20 окт. 2017 г.
 *      Author: knik
 */

#ifndef SRC_GLYPH_TESTPROXY_H_
#define SRC_GLYPH_TESTPROXY_H_

#include "Proxy.h"
#include "Proxy.cpp"
#include "../Exception.cpp"
// MyTestProxy.h
#include <cxxtest/TestSuite.h>

class MyTestProxy : public CxxTest::TestSuite
{
public:
    void testCreate(void)
    {
        TS_TRACE("Created point Glyph");
        int id = 1;
        Proxy* proxy;

        TS_ASSERT_THROWS_NOTHING( proxy = new Proxy(id));
        TS_ASSERT_THROWS_NOTHING(delete proxy);


        TS_TRACE("Finishing created Glyph test");
    }


    void testUnicId(void)
    {
        TS_TRACE("Created point Glyph");
        int id = 1;
        Proxy* proxy;


        TS_ASSERT_THROWS( ( new Proxy(id)), Exception &);


        TS_ASSERT_THROWS_EQUALS( ( new Proxy(id)), const Exception & e, e.what(), "double");


        TS_ASSERT_THROWS_NOTHING(delete proxy);


        TS_TRACE("Finishing created Glyph test");
    }

};





#endif /* SRC_GLYPH_TESTPROXY_H_ */
