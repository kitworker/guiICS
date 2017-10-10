/*
 * Proxy.h
 *
 *  Created on: 9 окт. 2017 г.
 *      Author: knik
 */

#ifndef GLYPH_PROXY_H_
#define GLYPH_PROXY_H_


class Proxy {
public:
	void SendParent() = 0;
	void SendChildren() = 0;

protected:
	Proxy() = 0;

};


#endif /* GLYPH_PROXY_H_ */
