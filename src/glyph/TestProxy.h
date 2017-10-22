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

        TS_ASSERT_THROWS_NOTHING( proxy = new Proxy(id));


        TS_ASSERT_THROWS_NOTHING(delete proxy);


        TS_TRACE("Finishing created Glyph test");
    }

     void testBad(void)
    {
        TS_TRACE("Created point Glyph");
        int id = 1;
        Proxy* proxy;

        TS_ASSERT_THROWS_NOTHING( proxy = new Proxy(id));

        TS_ASSERT_THROWS_NOTHING(Proxy * p = new Proxy(id));


        TS_ASSERT_THROWS_NOTHING(delete proxy);


        TS_TRACE("Finishing created Glyph test");
    }




};





#endif /* SRC_GLYPH_TESTPROXY_H_ */
