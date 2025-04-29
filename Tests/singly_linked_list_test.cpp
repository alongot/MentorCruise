#define BOOST_TEST_MODULE Singly_Linked_List_Tests
#include <boost/test/included/unit_test.hpp>
#include "../Data_Structures/singly_linked_list.h"
#include <iostream>

using namespace std;

// Test case for checking if the list is initially empty
BOOST_AUTO_TEST_CASE(ListInitiallyEmpty) {
    Singly_Linked_List list;
    cout << "Checking if list is initially empty..." << endl;
    BOOST_TEST(list.isEmpty());
}

// Test case for appending multiple values to the list
BOOST_AUTO_TEST_CASE(AppendingMultipleElements) {
    Singly_Linked_List list;
    cout << "Appending values 1, 2, 3 to the list..." << endl;
    list.append(1);
    list.append(2);
    list.append(3);

    auto temp = list.getTop();
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
    Singly_Linked_List list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    auto temp = list.getTop();
    BOOST_TEST(temp != nullptr);
    cout << "Top node data: " << temp->data << endl;
    BOOST_TEST(temp->data == 10);
}

// Test case for verifying the correct behavior when accessing an empty list
BOOST_AUTO_TEST_CASE(AccessingEmptyList) {
    Singly_Linked_List list;
    cout << "Attempting to access top node of an empty list..." << endl;
    auto temp = list.getTop();
    BOOST_TEST(temp == nullptr);
}
