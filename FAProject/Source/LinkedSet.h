#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedSetNode {
    int data;
    struct LinkedSetNode *next;
    struct LinkedSetNode *prev;
} LinkedSetNode;

typedef struct  {
    struct LinkedSetNode *first;
    struct LinkedSetNode *last;
}LinkedSet;

typedef struct LinkedSetIterator {
  LinkedSetNode* node;
}LinkedSetIterator;

/*
*Checks to see if the linkedset contains a piece of data
*/
extern int LinkedSet_contains(LinkedSet *list, int data);
/*
*Allocates and returns a new linkedset pointer
*/
extern LinkedSet* LinkedSet_new();
/*
*Allocates and returns a new linkedsetnode pointer
*/
extern LinkedSetNode * LinkedSetNode_new(int d);
/*
*Frees the linkedset from memory
*/
extern void LinkedSet_free(LinkedSet *list);
/**
 * Return true if the given LinkedSet is empty.
 */
extern int LinkedSet_is_empty(const LinkedSet *list);
/*
*Adds a new node at the end
*/
extern void LinkedSet_add_at_end(LinkedSet *list, int data);
/*
*Union Set operation simply adds elements to set 1 that are contained uniquely in set2
*/
extern void LinkedSet_Union(LinkedSet* s1, LinkedSet* s2);
/*
*Allocates and returns a new linkedset pointer
*/
extern void LinkedSet_print_list(LinkedSet *list);
/*
*Creates a linked set iterator
*/
extern LinkedSetIterator* LinkedSet_iterator(const LinkedSet* set);
/*
*Gets checks if iterator has a next value
*/
extern bool LinkedSetIterator_has_next(const LinkedSetIterator* iterator);
/*
*Pops and returns next value
*/
extern int LinkedSetIterator_next(LinkedSetIterator* iterator);
