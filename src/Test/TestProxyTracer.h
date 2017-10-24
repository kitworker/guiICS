/*
 * TestProxy.h
 *
 *  Created on: 20 окт. 2017 г.
 *      Author: knik
 */

#ifndef SRC_GLYPH_TESTPROXY_H_
#define SRC_GLYPH_TESTPROXY_H_

#include "../Exception.cpp"
// MyTestProxy.h
#include <cxxtest/TestSuite.h>
#include "../glyph/ProxyTracer.cpp"
#include "../glyph/ProxyTracer.h"

class MyTestProxy : public CxxTest::TestSuite
{
public:
    void testCreate(void)
    {
        TS_TRACE("Created point Glyph");
        int id = 1;
        ProxyTracer* proxy;

        TS_ASSERT_THROWS_NOTHING( proxy = new ProxyTracer(id));
        TS_ASSERT_THROWS_NOTHING(delete proxy);

        TS_ASSERT_THROWS_NOTHING( ProxyTracer(++id));



        TS_TRACE("Finishing created Glyph test");
    }


    void testUnicId(void)
    {
        TS_TRACE("Created point Glyph");
        int id = 1;
        ProxyTracer* proxy;


        TS_ASSERT_THROWS( ( new ProxyTracer(id)), Exception &);


        TS_ASSERT_THROWS_EQUALS( ( new ProxyTracer(id)), const Exception & e, e.what(), "double");


        TS_ASSERT_THROWS_NOTHING(delete proxy);


        TS_TRACE("Finishing created Glyph test");
    }

};





#endif /* SRC_GLYPH_TESTPROXY_H_ */
