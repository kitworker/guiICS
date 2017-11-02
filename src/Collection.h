/*
 * Collection.h
 *
 *  Created on: 25 ???. 2017 ?.
 *      Author: win
 */

#ifndef SRC_COLLECTION_H_
#define SRC_COLLECTION_H_

// Компилируется

#include <cstddef>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template< typename TData, template<typename, typename Alloc = allocator<TData> > class Contain >  //
class Collection {
public:
    typedef typename Contain<TData>::iterator iterator;
    Collection() :
        contain(), curr(begin()) {
    }

    void Append(const TData& t) {
        contain.push_back(t);
    }

    void First() {
        curr = begin();
    }

    void Next() {
        ++curr;
    }

    bool IsDone() {
        return curr == end();
    }

    TData * CurrentItem() {
        return &(*curr);
    }

    Collection* Clone() {
    	Collection* coll = new Collection();
    	coll->contain = contain;
    	  int n = 0;

    	  for (int i = 0; i < coll->contain.size(); i++)
    		  coll->contain[n++] =  coll->contain[i];

    	return coll;
    }

private:
    iterator begin() {
        return contain.begin();
    }
    iterator end() {
        return contain.end();
    }

private:
    Contain<TData> contain;
    iterator  curr;
};



#endif /* SRC_COLLECTION_H_ */