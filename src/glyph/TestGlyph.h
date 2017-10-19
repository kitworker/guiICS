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

#include "Glyph.h"
#include "Glyph.cpp"
// MyTestProxy.h
#include <cxxtest/TestSuite.h>

class MyTestGlyph : public CxxTest::TestSuite
{
public:
    void testAddition(void)
    {
        TS_ASSERT(3 - 1 > 1);
        TS_ASSERT_EQUALS(1 + 1, 2);
    }

    void testCreate(void)
    {
        TS_TRACE("Created point Glyph");
        int id = 1;
        Glyph* glyph = new Frame(id);

        glyph->Insert(glyph);

   //   TS_TRACE("Next");



        TS_ASSERT_EQUALS(2 * 2, 5);
        TS_TRACE("Finishing multiplication test");
    }

};


#endif /* GLYPH_PROXY_H_ */
