#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"


TEST_CASE( "testing push and pop front", "[deque]" ) 
{
    Deque<int> b;
    for(int i = 0; i < 10; i++)
    {
        b.pushFront(i);
    }
    for(int i = 9; i >= 0; i--)
    {
        REQUIRE(b.front() == i);
        b.popFront();
    }

    for(int i = 0; i < 10; i++)
    {
        b.pushFront(i);
    }
    b.popFront();
    b.popFront();
    b.pushFront(8);
    b.pushFront(9);
    b.pushFront(10);
    b.pushFront(11);
    for(int i = 11; i >= 0; i--)
    {
        REQUIRE(b.front() == i);
        b.popFront();
    }

}

TEST_CASE( "testing push and pop back", "[deque]" ) 
{
    Deque<int> b;
    for(int i = 0; i < 10; i++)
    {
        b.pushBack(i);
    }
    for(int i = 9; i >= 0; i--)
    {
        REQUIRE(b.back() == i);
        b.popBack();
    }

    REQUIRE(b.isEmpty());
    for(int i = 0; i < 10; i++)
    {
        b.pushBack(i);
    }
    b.popBack();
    b.popBack();
    b.pushBack(8);
    b.pushBack(9);

    for(int i = 9; i >= 0; i--)
    {
        REQUIRE(b.back() == i);
        b.popBack();
    }

}  
TEST_CASE( "testing mixing", "[deque]" ) 
{
    Deque<int> b;
    for(int i = 0; i < 10; i++)
    {
        b.pushFront(i);
    }
    REQUIRE(b.back() == 0);
    b.popBack();
    REQUIRE(b.back() == 1);

    for(int i = 10; i < 50; i++)
    {
        b.pushFront(i);
    }
    REQUIRE(b.back() == 1);

    for(int i = 1; i < 50; i++)
    {
        REQUIRE(b.back() == i);
        b.popBack();
    }

}  

