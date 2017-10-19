/*
 * Glyph.cpp
 *
 *  Created on: 12 окт. 2017 г.
 *      Author: knik
 */
#include <iostream>
#include "Glyph.h"

Glyph::~Glyph(){
	std::cout << "destructor: Glyph \n";
}

Glyph::Glyph(int proxy){
	std::cout << "constructor: Glyph \n";
}

void Glyph::Insert(Glyph* glyph) {

}


Frame::Frame(int proxy) :Glyph(proxy) {
	std::cout << "constructor: Frame \n";
}


TestTest::TestTest() {
	std::cout << "created testtest " << 1  << "\n";
}
