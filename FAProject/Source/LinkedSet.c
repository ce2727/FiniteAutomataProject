/*
Based off of Geroge Furgeson's included LinkedList file
Adopts the functionality of a set, yet unlike his IntSet
system, it allows for pointers of the systems to be made
*/

#include "LinkedSet.h"
inline int LinkedSet_contains(LinkedSet *list, int data) {
  for (LinkedSetNode *node=list->first; node != NULL; node=node->next) {
	   if (node->data == data) {
	    return 1;
	}
    }
    return 0;
}

/**
 * Allocate, initialize and return a new (empty) LinkedSet.
 */
 //!!ADDED INLINE HERE BECAUSE OF STATIC REMOVE IN .C FILE!!
inline LinkedSet* LinkedSet_new() {
    LinkedSet *list = (LinkedSet*)malloc(sizeof(LinkedSet));
    list->first = list->last = NULL;
    return list;
}

inline LinkedSetNode * LinkedSetNode_new(int d) {
    LinkedSetNode *node = (LinkedSetNode*)malloc(sizeof(LinkedSetNode));
    if (node == NULL) {
	abort();
    }
    node->data = d;
    node->next = node->prev = NULL;
    return node;
}

inline void LinkedSet_free(LinkedSet *list) {
    // Free the elements
    LinkedSetNode *elt = list->first;
    while (elt != NULL) {
	LinkedSetNode *next = elt->next;
	free(elt);
	elt = next;
    }
    // Free the list itself
    free(list);
}

/**
 * Return true if the given LinkedSet is empty.
 */
inline int LinkedSet_is_empty(const LinkedSet *list) {
    return list->first == NULL;
}


inline void LinkedSet_add_at_end(LinkedSet *list, int data) {
  if (LinkedSet_contains(list, data)) {
    printf("Set already contains %d\n", data);
    return;
    }
    LinkedSetNode *node = LinkedSetNode_new(data);
    node->prev = list->last;
    if (list->last != NULL) {
	list->last->next = node;
    }
    list->last = node;
    if (list->first == NULL) {
	list->first = node;
    }
}

//Union Set operation
//simply adds elements to set 1 that are contained uniquely in set2
inline void LinkedSet_Union(LinkedSet* s1, LinkedSet* s2){
  for (LinkedSetNode *node=s2->first; node != NULL; node=node->next){
    if (LinkedSet_contains(s1,node->data) == 0) {
      LinkedSet_add_at_end(s1,node->data);
    }
  }
}

inline void LinkedSet_print_list(LinkedSet *list) {
    for (LinkedSetNode *node=list->first; node != NULL; node=node->next) {
       printf("%d", node->data);
	     if (node->next != NULL) {
	        printf(" ");
	       }
       }
    printf("\n");
}



inline LinkedSetIterator* LinkedSet_iterator(const LinkedSet* set){
  LinkedSetIterator* iterator = (LinkedSetIterator*)malloc(sizeof(LinkedSetIterator));
  iterator->node = set->first;
  return iterator;
}

inline bool LinkedSetIterator_has_next(const LinkedSetIterator* iterator){
  return iterator != NULL && iterator->node != NULL;
}

inline int LinkedSetIterator_next(LinkedSetIterator* iterator){
  if (iterator == NULL || iterator->node == NULL){
    abort();
  } else {
    int value = iterator->node->data;
    iterator->node = iterator->node->next;
    return value;
  }
}
