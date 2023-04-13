/**
 * @file LinkCTest.c
 * @author Kevin Pluas (kpluas21@gmail.com)
 * @brief Unit testing for LinkC.h
 * @version 0.1
 * @date 2023-04-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include<stdio.h>
#include<stdlib.h>

#include"../src/LinkC.h"

#include"../../lib/unity.h"


void test_LinkC_init(void);

void test_LinkC_get(void);

void test_LinkC_append(void);

void test_LinkC_find(void);

void setUp(void);
void tearDown(void);

/**
 * @brief Static globals for our tests
 * 
 */
static LinkC *intList;

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_LinkC_init);
    RUN_TEST(test_LinkC_get);
    RUN_TEST(test_LinkC_append);
    RUN_TEST(test_LinkC_find);
    return UNITY_END();
}

void test_LinkC_init(void) {
    TEST_ASSERT_NOT_NULL(intList);
}

void test_LinkC_get(void) {
    //Correct inputs
    TEST_ASSERT_EQUAL_INT(1, *(int*)LinkC_get(intList, 0));

    //Incorrect inputs
    TEST_ASSERT_NULL(LinkC_get(intList, 5));
}

void test_LinkC_append(void) {
    for (int i = 2; i < 101; i++) {
        LinkC_append(intList, &i);
    }
    
    TEST_ASSERT_EQUAL_size_t(100, LinkC_size(intList));
}

void test_LinkC_find(void) {
    for (int i = 2; i < 101; i++) {
        LinkC_append(intList, &i);
    }
    
    //Correct input
    int i = 35;
    TEST_ASSERT_EQUAL_INT(34, LinkC_find(intList, &i));

    i = 200;
    //Incorrect
    TEST_ASSERT_EQUAL_INT(-1, LinkC_find(intList, &i));
}

void setUp(void) {
    int i = 1;

    intList = LinkC_init(sizeof(int), &i);

}

void tearDown(void) {
    LinkC_delete(&intList);
}


