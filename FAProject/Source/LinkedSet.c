/*
Based off of Geroge Furgeson's included LinkedList file
Adopts the functionality of a set, yet unlike his IntSet
system, it allows for pointers of the systems to be made
*/

#include <stdio.h>
#include <stdlib.h>

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
