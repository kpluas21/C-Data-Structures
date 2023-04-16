/**
 * @file DynamiC.c
 * @author your name (you@domain.com)
 * @brief Implementation of DynamiC
 * @version 0.0.2
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include"DynamiC.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/**
 * @brief Global epsilons to be used when comparing floating-point values. If you need to change
 * how precise the comparisons should be, change it here.
 * Used in the following functions
 * _find()
 * _cmp()
 * 
 */
#define FLTEPSILON 0.001
#define DBEPSILON 0.000001

DynamiC *DynamiC_init(void *data, size_t data_size, size_t num_elems) {
    DynamiC *newList = malloc(sizeof(DynamiC));
    if(newList == NULL) {
        return NULL;
    }

    newList->alloc_data = data_size * num_elems;

    if(num_elems == 0) {
        newList->capacity = data_size;
    }
    else {
        newList->capacity = newList->alloc_data * 2;
    }


    newList->data = malloc(newList->capacity);
    if(newList->data == NULL) {
        free(newList);
        return NULL;
    }

    memcpy(newList->data, data, data_size * num_elems);

    newList->data_size = data_size;
    return newList;
}

void *DynamiC_get(DynamiC *array, size_t index) {    
    if(index >= DynamiC_size(array)) {
        printf("Out of bounds\n");

        return NULL;
    }
    char *indexPtr = array->data;
    return indexPtr + (array->data_size * index);
}

void DynamiC_resize(DynamiC *array) {
    array->capacity *= 2;
    array->data = realloc(array->data, array->capacity);
    if(array->data == NULL) {
        return; 
    }
}

size_t DynamiC_size(DynamiC *array) {
    return array->alloc_data / array->data_size;
}

void DynamiC_append(DynamiC *array, void *elem) {
    if(array->alloc_data == array->capacity) {
        DynamiC_resize(array);
    }

    char *indexPtr = array->data;

    indexPtr += array->alloc_data;
    memcpy(indexPtr, elem, array->data_size);

    array->alloc_data += array->data_size;
    
}

void DynamiC_delete(DynamiC **array) {
    if(array == NULL || *array == NULL) {
        return; //Prevents double frees
    }

    free((*array)->data);    
    free(*array);
    (*array) = NULL;
}

void DynamiC_empty(DynamiC *array) {
    free(array->data);

    array->data = calloc(array->capacity, array->data_size);
    if(array->data == NULL) {
        printf("ERROR\n");
    }
}
