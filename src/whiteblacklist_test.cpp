//============================================================================
// Name        : white-black-list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <assert.h>
#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include "whiteblacklist.h"
using namespace std;

#define TEST_QUERY(__start, __end, __exp) \
    do{\
        for(uint64_t i=__start; i<=__end; i++) \
            CHECK_EQUAL(wblist.query(i), whiteblacklist::__exp);\
    }while(0)

#define TEST_ADD(__start, __end, __type, __exp) \
    do{\
        cout<<endl<<"Try to add segment ["<<__start<<", "<<__end<<"] "<<#__type<<endl; \
        cout<<"before:"<<endl;\
        wblist.print_all_segments();\
        CHECK_EQUAL(wblist.add(__start, __end, whiteblacklist::__type), whiteblacklist::__exp);\
        cout<<"after:"<<endl;\
        wblist.print_all_segments();\
        cout<<endl;\
        if(whiteblacklist::__exp == whiteblacklist::SEG_ADDED) \
            TEST_QUERY(__start, __end, IN_##__type##_LIST);\
    }while(0)

#define TEST_REMOVE(__start, __end,__exp) \
    do{ \
        cout<<endl<<"Try to remove segment ["<<__start<<", ?]"<<endl; \
        cout<<"before:"<<endl;\
        wblist.print_all_segments();\
        CHECK_EQUAL(wblist.remove(__start), whiteblacklist::__exp);\
        if(whiteblacklist::__exp == whiteblacklist::SEG_REMOVED) \
            TEST_QUERY(__start, __end, NOT_FOUND);\
        cout<<"after:"<<endl;\
        wblist.print_all_segments();\
        cout<<endl;\
    }while(0)



TEST(abnormal){
    whiteblacklist wblist;
    TEST_ADD(14, 16, WHITE, SEG_ADDED);
    TEST_ADD(15, 15, BLACK, SEG_ADDED);
    wblist.query(15);
    TEST_ADD(2, 2, BLACK, SEG_ADDED);
    TEST_ADD(2, 2, BLACK, SEG_ADDED);

    TEST_ADD(0, 2, WHITE, SEG_INVALIED);
    TEST_QUERY(2, 2, IN_BLACK_LIST);

    TEST_ADD(2, 0, WHITE, SEG_INVALIED);
    TEST_QUERY(2, 2, IN_BLACK_LIST);

    TEST_ADD(2, 1, WHITE, SEG_INVALIED);
    TEST_QUERY(2, 2, IN_BLACK_LIST);
}

TEST(remove){
    whiteblacklist wblist;
    TEST_REMOVE(1, 1, NOT_FOUND);
    TEST_ADD(1, 10, WHITE, SEG_ADDED);
    TEST_REMOVE(1, 10, SEG_REMOVED);
    TEST_REMOVE(1, 10, NOT_FOUND);

    TEST_ADD(10, 10, WHITE, SEG_ADDED);
    TEST_REMOVE(10, 10, SEG_REMOVED);
    TEST_REMOVE(10, 10, NOT_FOUND);
}

TEST(normal){
    whiteblacklist wblist;
    TEST_ADD(1, 2, WHITE, SEG_ADDED);
    TEST_QUERY(3, 4, NOT_FOUND);
    TEST_ADD(10, 30, BLACK, SEG_ADDED);
    TEST_ADD(15, 15, BLACK, SEG_ADDED);
    TEST_REMOVE(15, 15, NOT_FOUND);
    TEST_REMOVE(10, 30, SEG_REMOVED);
    TEST_ADD(10, 30, BLACK, SEG_ADDED);
    TEST_ADD(15, 15, WHITE, SEG_ADDED);
    TEST_QUERY(10, 14, IN_BLACK_LIST);
    TEST_QUERY(15, 15, IN_WHITE_LIST);
    TEST_QUERY(16, 30, IN_BLACK_LIST);

    TEST_QUERY(1, 2, IN_WHITE_LIST);
    TEST_QUERY(3, 3, NOT_FOUND);

    TEST_ADD(22, 23, WHITE, SEG_ADDED);
    TEST_ADD(23, 26, WHITE, SEG_ADDED);
    TEST_ADD(25, 39, BLACK, SEG_ADDED);
    TEST_ADD(20, 40, WHITE, SEG_ADDED);

    TEST_ADD(45, 45, WHITE, SEG_ADDED);
    TEST_ADD(1, 50, BLACK, SEG_ADDED);
}

int main() {
    return UnitTest::RunAllTests();
}
