/*
Modified from George Ferguson's "LinkedList.c"
Acts as a linkedlist style set for int
*/

#include <stdio.h>
#include <stdlib.h>
//#include "LinkedSet.h"


typedef struct LinkedSetNode {
    int data;
    struct LinkedSetNode *next;
    struct LinkedSetNode *prev;
} LinkedSetNode;

typedef struct  {
    struct LinkedSetNode *first;
    struct LinkedSetNode *last;
}LinkedSet;

int LinkedSet_contains(LinkedSet *list, int data) {
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
LinkedSet *
LinkedSet_new() {
    LinkedSet *list = (LinkedSet*)malloc(sizeof(LinkedSet));
    list->first = list->last = NULL;
    return list;
}

static LinkedSetNode *
LinkedSetNode_new(int d) {
    LinkedSetNode *node = (LinkedSetNode*)malloc(sizeof(LinkedSetNode));
    if (node == NULL) {
	abort();
    }
    node->data = d;
    node->next = node->prev = NULL;
    return node;
}

void
LinkedSet_free(LinkedSet *list) {
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
int
LinkedSet_is_empty(const LinkedSet *list) {
    return list->first == NULL;
}


void LinkedSet_add_at_end(LinkedSet *list, int data) {
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
void LinkedSet_Union(LinkedSet* s1, LinkedSet* s2){
  for (LinkedSetNode *node=s2->first; node != NULL; node=node->next){
    if (LinkedSet_contains(s1,node->data) == 0) {
      LinkedSet_add_at_end(s1,node->data);
    }
  }
}

void LinkedSet_print_list(LinkedSet *list) {
    for (LinkedSetNode *node=list->first; node != NULL; node=node->next) {
       printf("%d", node->data);
	     if (node->next != NULL) {
	        printf(" ");
	       }
       }
    printf("\n");
}

//
// /**
//  * Remove the given void* value from the given LinkedSet if it is there.
//  * Note that this does not free the data associated with the element.
//  */
// void
// LinkedSet_remove(LinkedSet *list, int data) {
//     for (LinkedSetNode *node=list->first; node != NULL; node=node->next) {
// 	if (node->data == data) {
// 	    if (node == list->first) {
// 		list->first = node->next;
// 	    }
// 	    if (node == list->last) {
// 		list->last = node->prev;
// 	    }
// 	    if (node->prev != NULL) {
// 		node->prev->next = node->next;
// 	    }
// 	    if (node->next != NULL) {
// 		node->next->prev = node->prev;
// 	    }
// 	    free(node);
// 	    return;
// 	}
//     }
// }
//
// /**
//  * Remove and return the first element from the given LinkedSet.
//  * Returns NULL if the list is empty.
//  */
// void *
// LinkedSet_pop(LinkedSet *list) {
//     void *data = LinkedSet_element_at(list, 0);
//     if (data != NULL) {
// 	LinkedSet_remove(list, data); // Removes first occurrence
//     }
//     return data;
// }
//
// /**
//  * Call the given function on each element of given LinkedSet, passing the
//  * void* value to the function.
//  */
// void
// LinkedSet_iterate(const LinkedSet *list, void (*func)(void *)) {
//     for (LinkedSetNode *node=list->first; node != NULL; node=node->next) {
// 	func(node->data);
//     }
// }
//
// /**
//  * Return an LinkedSetIterator for the given LinkedSet.
//  * Don't forget to free() this when you're done iterating.
//  */
// LinkedSetIterator *
// LinkedSet_iterator(const LinkedSet *list) {
//     LinkedSetIterator *iterator = (LinkedSetIterator*)malloc(sizeof(LinkedSetIterator));
//     *iterator = list->first;
//     return iterator;
// }
//
// /**
//  * Return true if the given LinkedSetIterator will return another element
//  * if LinkedSetIterator_next() is called.
//  */
// bool
// LinkedSetIterator_has_next(const LinkedSetIterator *iterator) {
//     return iterator != NULL && *iterator != NULL;
// }
//
// /**
//  * Return the next value from the given LinkedSetIterator and increment it
//  * to point to the next element.
//  * Will return NULL if there is no such element.
//  * This means that you can't store NULL in a LinkedSet. C'est la vie.
//  * It would be easy to allow it and signal `no such element' some other way...
//  */
// void *
// LinkedSetIterator_next(LinkedSetIterator *iterator) {
//     if (iterator == NULL || *iterator == NULL) {
// 	return NULL;
//     } else {
// 	void *data = (*iterator)->data;
// 	*iterator = (*iterator)->next;
// 	return data;
//     }
// }
//
// /**
//  * Print the given LinkedSet to stdout, assuming that the values are
//  * all null-terminated strings.
//  */
// void
