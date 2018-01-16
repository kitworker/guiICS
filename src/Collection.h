/*
 * Collection.h
 *
 *  Created on: 25 ???. 2017 ?.
 *      Author: win
 */

#ifndef SRC_COLLECTION_H_
#define SRC_COLLECTION_H_

// ÐšÐ¾Ð¼Ð¿Ð¸Ð»Ð¸Ñ€ÑƒÐµÑ‚Ñ�Ñ�

#include <cstddef>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template< typename TData, template<typename, typename Alloc = allocator<TData> > class Contain >  //
class Collection {
public:
    typedef typename Contain<TData>::iterator iterator;
    typedef typename Contain<TData>::const_iterator const_iterator;
    typedef typename Contain<TData>::reverse_iterator reverse_iterator;
    Collection() :
        contain(), curr(begin()), rCurr( begin() ) {
    }

    void Append(const TData& t) {
        contain.push_back(t);
    }

    void First() {
        curr = begin();
    }

    void End() {
    	rCurr = rbegin();
    }


    void Next() {
        ++curr;
    }

    void Prev() {
    	--curr;
    }


    bool IsDone() {
        return curr == end();
    }

    bool IsHead() {
    	return curr == rend();
    }


    TData * CurrentItem() {
        return &(*curr);
    }

    void DeleteCurrent() {
    	if(!IsDone()) {
    		curr = contain.erase(curr);
    	}
    }

	Collection* Clone() const {
		Collection* clon = new Collection();
		for (const_iterator it = contain.begin(); it != contain.end(); ++it) {
			clon->Append(*it);
		}
		return clon;
	}


    void  Print() {
    	for(First(); !IsDone(); Next()) {
    		cout << *CurrentItem()<< " \t";
    	}
    }


private:
    iterator begin() {
        return contain.begin();
    }
    iterator end() {
        return contain.end();
    }
    reverse_iterator rbegin() {
        return contain.rbegin();
    }
    reverse_iterator rend()  {
        return contain.rend();
    }


private:
    Contain<TData> contain;
    iterator  curr;
    reverse_iterator  rCurr;
};



#endif /* SRC_COLLECTION_H_ */
