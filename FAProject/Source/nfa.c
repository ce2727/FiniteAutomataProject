#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#define FALSE 0
#define TRUE 1
#define ASCII_Chars 128
#define NFA_NoTransition IntSet_new();

typedef struct{
  int accepts;
  IntSet transitions[ASCII_Chars];
  int stateNumber;
}NFA_State;

typedef struct {
  int states;
  NFA_State *state_array;
  IntSet currentState;

}NFA;


NFA* initialize_NFA(int numStates) {
	NFA* n = (NFA*)malloc(sizeof(NFA));
	n->states = numStates;
	n->state_array = (NFA_State*)malloc(numStates * sizeof(NFA_State));
	n->currentState = IntSet_new();
	IntSet_add(n->currentState,0);//Add new IntSet as current state and add it as to 0

	for (int i = 0; i < numStates; i++) {
		n->state_array[i].accepts = FALSE;
    n->state_array[i].stateNumber = i;
		for (int j = 0; j < ASCII_Chars; j++) {
			n->state_array[i].transitions[j] = IntSet_new(); //Set it to have no transitions
		}
	}

	return n;
}

void NFA_set_transition(NFA* nfa, int stateNumber, char inputChar, int destination)
{
    IntSet_add(nfa->state_array[stateNumber].transitions[(int)inputChar],destination);//Passing in char to array index translates it to ascii value
}

IntSet NFA_get_transition(NFA* nfa, int stateNumber, char inputChar)
{
    return nfa->state_array[stateNumber].transitions[(int)inputChar];
}

int main(){
    printf("Automaton testing for string 'ab'\n");

}
