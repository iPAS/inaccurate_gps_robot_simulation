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
}

void test_operator_equal(void) {
}

void test_operator_self_addition(void) {

}

void test_operator_self_assignment(void) {

}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_operator_type_casting);
    RUN_TEST(test_operator_equal);
    RUN_TEST(test_operator_self_addition);
    RUN_TEST(test_operator_self_assignment);
    return UNITY_END();
}
