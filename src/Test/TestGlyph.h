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
#include <list>

#include "../glyph/Glyph.h"
#include "../glyph/Glyph.cpp"
// MyTestProxy.h
#include <cxxtest/TestSuite.h>

class MyTestGlyph : public CxxTest::TestSuite
{
public:
    void testCreate(void)
    {
        TS_TRACE("Created point Glyph");
        int id = 1;
        Glyph* glyph;

        TS_ASSERT_THROWS_NOTHING( glyph = new Frame(id));

        TS_ASSERT_THROWS_NOTHING(delete glyph);


        TS_TRACE("Finishing created Glyph test");
    }
};


#endif /* GLYPH_PROXY_H_ */
