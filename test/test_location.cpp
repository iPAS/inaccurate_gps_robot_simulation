// https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md
#include "unity.h"
#include "location.h"

#include <iostream>
using namespace std;


Location * pLoc;

void setUp(void) {
    // set stuff up here
    pLoc = new Location();
}

void tearDown(void) {
    // clean stuff up here
    delete pLoc;
}

void test_operator_type_casting(void) {
    TEST_ASSERT_EQUAL_STRING_MESSAGE("(0, 0)", *pLoc, "Type casting of Location object wrong!");
}

void test_operator_equal(void) {
    Location l1(0, 0);
    Location l2(0, 1);
    TEST_ASSERT_TRUE(*pLoc == l1);
    TEST_ASSERT_FALSE(*pLoc == l2);
}

void test_operator_self_addition(void) {
    *pLoc += Location(1, 1);
    TEST_ASSERT_TRUE(*pLoc == Location(1, 1));
    *pLoc += Location(-10, 5);
    TEST_ASSERT_TRUE(*pLoc == Location(-9, 6));
    *pLoc += Location(9, -6);
    TEST_ASSERT_TRUE(*pLoc == Location(0, 0));
}

void test_operator_self_assignment(void) {
    *pLoc = Location(100, -100);
    TEST_ASSERT_TRUE(*pLoc == Location(100, -100));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_operator_type_casting);
    RUN_TEST(test_operator_equal);
    RUN_TEST(test_operator_self_addition);
    RUN_TEST(test_operator_self_assignment);
    return UNITY_END();
}
