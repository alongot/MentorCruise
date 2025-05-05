#define BOOST_TEST_MODULE QueueTests
#include <boost/test/included/unit_test.hpp>
#include "../Data_Structures/queue.h"
#include <iostream>

using namespace std;

// Test that a newly created queue is empty
BOOST_AUTO_TEST_CASE(QueueInitiallyEmpty) {
    Queue <int> q;
    cout << "Testing if new queue is initially empty." << endl;
    BOOST_TEST(q.isEmpty());
}

// Test enqueueing one element
BOOST_AUTO_TEST_CASE(EnqueueOneElement) {
    Queue <int> q;
    q.Enqueue(5);
    cout << "Enqueued 5." << endl;
    BOOST_TEST(!q.isEmpty());
    BOOST_TEST(q.GetFront().get() == 5);
    BOOST_TEST(q.GetRear().get() == 5);
}

// Test enqueueing multiple elements (order preservation)
BOOST_AUTO_TEST_CASE(EnqueueMultipleElements) {
    Queue <int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    cout << "Enqueued 10, 20, 30." << endl;
    BOOST_TEST(q.GetFront().get() == 10);
    BOOST_TEST(q.GetRear().get() == 30);
}

// Test dequeue removes elements in FIFO order
BOOST_AUTO_TEST_CASE(DequeueFIFOOrder) {
    Queue <int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    cout << "Dequeuing in FIFO order." << endl;
    BOOST_TEST(q.GetFront().get() == 1);

    q.Dequeue();
    cout << "Dequeued once." << endl;
   BOOST_TEST(q.GetFront().get() == 2);

    q.Dequeue();
    cout << "Dequeued twice." << endl;
    BOOST_TEST(q.GetFront().get() == 3);

    q.Dequeue();
    cout << "Dequeued third time." << endl;
    BOOST_TEST(q.isEmpty());
}

//Test dequeue on empty queue
BOOST_AUTO_TEST_CASE(DequeueOnEmptyQueue) {
    BOOST_TEST_MESSAGE("Testing: Dequeue on empty queue should throw an exception.");
    Queue <int> q;
    std::cout << "Attempting dequeue on empty queue..." << std::endl;
    BOOST_CHECK_THROW(q.Dequeue(), std::underflow_error);
}
// Test Top function on non-empty and empty queue
BOOST_AUTO_TEST_CASE(TopFunctionTest) {
    Queue  <int> q;
    cout << "Testing Top() with one element." << endl;
    q.Enqueue(99);
    q.Top();  // Should print 99
    BOOST_TEST(q.GetFront().get() == 99);

    cout << "Testing Top() on empty queue." << endl;
    q.Dequeue(); // Now it's empty
    q.Top();     // Should print warning
    BOOST_TEST(q.isEmpty());
}

// Test Display output manually (for visual debugging)
BOOST_AUTO_TEST_CASE(DisplayQueueContents) {
    Queue <int> q;
    q.Enqueue(100);
    q.Enqueue(200);
    cout << "Displaying queue contents:" << endl;
    q.Display();  // Should print 100 and 200
    BOOST_TEST(q.GetFront().get() == 100);
    BOOST_TEST(q.GetRear().get() == 200);
}
