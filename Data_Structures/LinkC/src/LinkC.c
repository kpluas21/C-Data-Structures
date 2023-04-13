/**
 * @file LinkC.c
 * @author Kevin Pluas (kpluas21@gmail.com)
 * @brief Implementation of LinkC
 * @version 0.1
 * @date 2023-04-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"LinkC.h"

LinkC *LinkC_init(size_t dataSize, void *data) {
    LinkC *list = malloc(sizeof(LinkC));
    LinkCNode *head = malloc(sizeof(LinkCNode));

    if(list == NULL || head == NULL) {
        return NULL;
    }

    head->data = malloc(dataSize);

    if(head->data == NULL) {
        return NULL;
    }
    memcpy(head->data, data, dataSize);

    list->dataSize = dataSize;
    list->alloc_Data = dataSize;

    list->head = head;
    list->tail = head;
    head->prev = NULL;
    head->next = NULL;
    
    return list;
}

size_t LinkC_size(LinkC *list) {
    return list->alloc_Data / list->dataSize;
}

void LinkC_append(LinkC *list, void* data) {
    LinkCNode *current = list->tail;

    LinkCNode *newNode = malloc(sizeof(LinkCNode));
    if(newNode == NULL) {
        return;
    }

    newNode->data = malloc(list->dataSize);
    if(newNode->data == NULL) {
        free(newNode);
        return;
    }
    
    memcpy(newNode->data, data, list->dataSize);

    current->next = newNode;
    newNode->prev = current;
    newNode->next = NULL;
    list->tail = newNode;

    list->alloc_Data += list->dataSize;
    
}

void *LinkC_get(LinkC *list, int indexOfElem) {
    LinkCNode *current = list->head;
    int currentIndex = 0;

    while(current != NULL) {
        if(currentIndex == indexOfElem) {
            return current->data;
        }
        currentIndex++;
        current = current->next;
    }
    return NULL;
}

int LinkC_find(LinkC *list, void *data) {
    LinkCNode *current = list->head;
    int index = 0;

    while(current != NULL) {
        if(memcmp(current->data, data, list->dataSize) == 0) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void LinkC_delete(LinkC **list) {
    if(list == NULL || (*list) == NULL) {
        return; //Prevents double free's
    }
    
    LinkCNode *current = (*list)->head;
    LinkCNode *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    free(*list);
    (*list) = NULL;
    
}

void LinkC_insert_at_index(LinkC *list, void *data, int index) {
    LinkCNode *current = list->head;

    LinkCNode *newNode = malloc(sizeof(LinkCNode));
    if(newNode == NULL) {
        return;
    }

    newNode->data = malloc(list->dataSize);
    if(newNode->data == NULL) {
        free(newNode);
        return;
    }

    int currentIndex = 0;
    while(current != NULL) {
        if(currentIndex == index) {
            
        }
    }


}