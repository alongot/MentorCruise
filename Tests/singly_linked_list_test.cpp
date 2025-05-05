#define BOOST_TEST_MODULE Singly_Linked_List_Tests
#include <boost/test/included/unit_test.hpp>
#include "../Data_Structures/singly_linked_list.h"
#include <iostream>

using namespace std;

// Test case for checking if the list is initially empty
BOOST_AUTO_TEST_CASE(ListInitiallyEmpty) {
    SinglyLinkedList<int> list;
    cout << "Checking if list is initially empty..." << endl;
    BOOST_TEST(list.IsEmpty());
}

// Test case for appending multiple values to the list
BOOST_AUTO_TEST_CASE(AppendingMultipleElements) {
    SinglyLinkedList<int> list;
    cout << "Appending values 1, 2, 3 to the list..." << endl;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    auto temp = list.GetTop();
    BOOST_TEST(temp != nullptr);
    cout << "First node data: " << temp->data << endl;
    BOOST_TEST(temp->data == 1);

    temp = temp->next;
    BOOST_TEST(temp != nullptr);
    cout << "Second node data: " << temp->data << endl;
    BOOST_TEST(temp->data == 2);

    temp = temp->next;
    BOOST_TEST(temp != nullptr);
    cout << "Third node data: " << temp->data << endl;
    BOOST_TEST(temp->data == 3);

    BOOST_TEST(temp->next == nullptr); // End of the list
}

// Test case for accessing the top element after multiple appends
BOOST_AUTO_TEST_CASE(TopElementAfterAppend) {
    SinglyLinkedList <int> list;
    list.Append(10);
    list.Append(20);
    list.Append(30);

    auto temp = list.GetTop();
    BOOST_TEST(temp != nullptr);
    cout << "Top node data: " << temp->data << endl;
    BOOST_TEST(temp->data == 10);
}

// Test case for verifying the correct behavior when accessing an empty list
BOOST_AUTO_TEST_CASE(AccessingEmptyList) {
    SinglyLinkedList <int> list;
    cout << "Attempting to access top node of an empty list..." << endl;
    auto temp = list.GetTop();
    BOOST_TEST(temp == nullptr);
}
