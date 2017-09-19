#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedSet.h"

#define FALSE 0
#define TRUE 1
#define ASCII_Chars 128

/**
*NFA State node structure
*/
typedef struct{
  int accepts;
  LinkedSet* transitions[ASCII_Chars];
  int stateNumber;
}NFA_State;

/**
*NFA implementation
*/
typedef struct {
  int states;
  NFA_State *state_array;
  LinkedSet* currentStates;
}NFA;


extern NFA* initialize_NFA(int numStates);

extern void NFA_set_transition(NFA* nfa, int stateNumber, char inputChar, int destination);

extern void NFA_setLambdaTransition(NFA* nfa, int minus, int stateNumber, int destination);

extern LinkedSet* NFA_get_transition(NFA* nfa, int stateNumber, char inputChar);

extern LinkedSet* NFA_get_currentStates(NFA* nfa);

extern void NFA_set_currentState(NFA* nfa, int newState);

extern void NFA_set_currentStates(NFA* nfa, LinkedSet* newStates);

extern bool NFA_is_accepting(NFA* nfa);

extern bool NFA_get_accepting(NFA* nfa, int stateNum);

extern void NFA_set_accepting(NFA* nfa, int stateNum);

extern void NFA_union_with_all_transitions(NFA* nfa, char input, LinkedSet* targetSet);

extern bool NFA_accepts_string(NFA* nfa, char string[], int length);
