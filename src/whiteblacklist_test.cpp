//============================================================================
// Name        : white-black-list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<assert.h>
#include "whiteblacklist.h"
int main() {
    whiteblacklist_t wblist;
    wblist.add_to_list(1, 2, true);
    assert(wblist.is_in_whitelist(1) == true);
    wblist.add_to_list(10, 30, false);
    wblist.add_to_list(15, 15, false);
    wblist.add_to_list(15, 15, true);
    assert(wblist.is_in_whitelist(1) == true);
    assert(wblist.is_in_whitelist(3) == false);
    assert(wblist.is_in_whitelist(10) == false);
    assert(wblist.is_in_whitelist(30) == false);
    wblist.add_to_list(22, 23, true);
    wblist.add_to_list(38, 39, true);
    wblist.add_to_list(45, 45, true);
    wblist.add_to_list(1, 20, false);
    assert(wblist.is_in_whitelist(1) == false);
    assert(wblist.is_in_whitelist(20) == false);
    wblist.add_to_list(1, 19, true);
    assert(wblist.is_in_whitelist(1) == true);
    assert(wblist.is_in_whitelist(19) == true);
    assert(wblist.is_in_whitelist(20) == false);
    wblist.add_to_list(1, 18, false);
    assert(wblist.is_in_whitelist(1) == false);
    assert(wblist.is_in_whitelist(18) == false);
    assert(wblist.is_in_whitelist(19) == true);
    for(uint64_t i = 0; i<46; i++)
        wblist.is_in_whitelist(i);
    wblist.add_to_list(46, 50, true);
    wblist.add_to_list(1, 50, false);
    for(uint64_t i = 0; i<46; i++)
        assert(wblist.is_in_whitelist(i) == false);
	return 0;
}
