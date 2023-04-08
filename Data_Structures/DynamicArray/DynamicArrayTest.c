/**
 * @file DynamicArrayTest.c
 * @author Kevin Pluas (kpluas21@gmail.com)
 * @brief Program used to test the functions of DynamicArray.h
 * @version 0.1
 * @date 2023-04-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>
#include"DynamicArray.h"

double rand_from(double min, double max);
void DynamicArrayTest_print_all_debug(DynamicArray **arrayOfVectors);
void DynamicArrayTest_empty_all(DynamicArray **arrayOfVectors);

/**
 * @brief Our main test function.
 * I'll try to split testing into several parts. Each part will involve the four different data types : int, char, double & float.
 * 1)Initialization
 * 2)Appending
 * 3)Printing
 * 4)Finding
 * 5)Getting
 * 6)Removing
 * 7)Resizing
 * 
 */
int main(void) {
    int intArray[5] = {1, 2, 3, 4, 5};

    DynamicArray *vector = DynamicArray_init(INT, intArray, 5);
    DynamicArray_print(vector);
    DynamicArray_debug_info(vector);

    int l = 11;
    int r = 22;
    int e = 33;

    DynamicArray_insert(vector, &l, 0);
    DynamicArray_insert(vector, &r, 5);
    DynamicArray_insert(vector, &e, vector->size);
    DynamicArray_print(vector);
    
    DynamicArray_delete(vector);
    return 0;
}

double rand_from(double min, double max) {
    double range = max - min;
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void DynamicArrayTest_print_all_debug(DynamicArray **arrayOfVectors) {
    for (size_t i = 0; i < 4; i++) {
        DynamicArray_debug_info(arrayOfVectors[i]);
    }
    
}

void DynamicArrayTest_empty_all(DynamicArray **arrayOfVectors) {
    for (size_t i = 0; i < 4; i++) {
        DynamicArray_empty(arrayOfVectors[i]);
    }
    
}
