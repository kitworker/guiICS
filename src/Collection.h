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

    void DeleteCurrent() {
    	curr = contain.erase(curr);
    }

//    Collection* Clone() {
//    	Collection* clon = new Collection();
//    	for(First(); !IsDone(); Next()) {
//    		clon->Append(*CurrentItem());
//    	}
//    	return clon;
//    }
//
//    Collection* Clone() const {
//
//		Contain<TData> containClon(contain);
//		iterator currClone(containClon.begin());
//		Collection* clon = new Collection();
//
//    	for (; !(currClone == containClon.end()); ++currClone) {
//			clon->Append(*(&(*currClone)));
//		}
//		return clon;
//    }
//
//	Collection* Clone() const {
//		Collection* clon = new Collection();
//		for (auto it = contain.begin(); it != contain.end(); ++it) {
//			clon->Append(*it);
//		}
//		return clon;
//	}

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

private:
    Contain<TData> contain;
    iterator  curr;
};



#endif /* SRC_COLLECTION_H_ */
