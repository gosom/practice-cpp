#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "darray.h"

SCENARIO("Dynamic arrays operations", "[darray]") {

    GIVEN("A dynamic array ") {
        ds::DArray<int> v;
        REQUIRE( v.size() == 0 );
        REQUIRE( v.capacity() == 2);

        WHEN("We can push 2 elements without realloc") {
            for(int i=0; i<2; ++i)
                v.append(i);
            REQUIRE( v.size() == 2);
            REQUIRE( v.capacity() == 2);
        }

        WHEN("We can push 4 elements") {
            for(int i=0; i<4; ++i)
                v.append(i);
            REQUIRE( v.size() == 4);
            REQUIRE( v.capacity() == 4);
        }

        WHEN("We can push 10 elements") {
            for(int i=0; i<10; ++i)
                v.append(i);
            REQUIRE( v.size() == 10);
            REQUIRE( v.capacity() == 16);
        }
    }

    GIVEN("A dynamic array with 10 numbers") {
        ds::DArray<int> v;
        for(int i=0; i<10; i++)
            v.append(i);
        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() == 16);

        WHEN("We can insert element in index 0") {
            v.insert(0, 10);
            REQUIRE( v.size() == 11);
            REQUIRE( v.capacity() == 16);
            REQUIRE( v[0] == 10);
            REQUIRE( v[2] == 1);
            REQUIRE( v[10] == 9);
        }
    }

}


