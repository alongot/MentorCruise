#define BOOST_TEST_MODULE StackTests
#include <boost/test/included/unit_test.hpp>
#include "stack.h"

BOOST_AUTO_TEST_CASE(PushPopPeekOperations) {
    Stack s;

    BOOST_TEST(s.isEmpty());
    s.push(10);
    BOOST_TEST(s.peek() == 10);
    s.push(20);
    BOOST_TEST(s.peek() == 20);
    BOOST_TEST(!s.isEmpty());
    s.pop();
    BOOST_TEST(s.peek() == 10);
    s.pop();
    BOOST_TEST(s.isEmpty());
}

BOOST_AUTO_TEST_CASE(EmptyStackOperations) {
    Stack s;

    // Should return -1 and print "Stack is empty"
    BOOST_TEST(s.peek() == -1);  

    // Should not throw, just print "Stack is empty" and do nothing
    BOOST_TEST(s.isEmpty());
    s.pop();  // Should not change state or crash

    // Still empty after pop
    BOOST_TEST(s.isEmpty());
}
