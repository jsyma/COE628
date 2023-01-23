#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Jma
 */
void PQ_insert(int priority, char * data) {
 //FIX THIS
    Node_t *point;
    point = (Node_t*)malloc(sizeof(Node_t));
    point -> priority = priority;
    point -> data = data;
    point -> next = NULL;
        
    if (head == NULL || PQ_get_size() == 0 || head -> priority < priority){
        point -> next = head;
        head = point;
    }
    else{
        Node_t *temp;
        temp = (Node_t*)malloc(sizeof(Node_t));
        temp = head;
        while (temp -> next != NULL && temp -> next -> priority >= priority){
            temp = temp -> next;
        }
        point -> next = temp -> next;
        temp -> next = point;
    }
}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
  //FIX THIS
    Node_t *new;
    new =
         (Node_t*)malloc(sizeof(Node_t));
    if (head != NULL){
        new = head;
        head = head -> next;
        return new;
    }
    else{
        return NULL;
    }
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}


