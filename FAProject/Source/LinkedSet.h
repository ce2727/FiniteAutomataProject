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
*
*/
extern int LinkedSet_contains(LinkedSet *list, int data);
//!!SET EXTERN AND REMOVED STATIC FOR TESTING!!
extern LinkedSet* LinkedSet_new();

extern LinkedSetNode * LinkedSetNode_new(int d);

extern void LinkedSet_free(LinkedSet *list);

/**
 * Return true if the given LinkedSet is empty.
 */
extern int LinkedSet_is_empty(const LinkedSet *list);

extern void LinkedSet_add_at_end(LinkedSet *list, int data);

//Union Set operation
//simply adds elements to set 1 that are contained uniquely in set2
extern void LinkedSet_Union(LinkedSet* s1, LinkedSet* s2);

extern void LinkedSet_print_list(LinkedSet *list);

extern LinkedSetIterator* LinkedSet_iterator(const LinkedSet* set);

extern bool LinkedSetIterator_has_next(const LinkedSetIterator* iterator);

extern int LinkedSetIterator_next(LinkedSetIterator* iterator);
