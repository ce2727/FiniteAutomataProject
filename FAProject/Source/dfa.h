#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define ASCII_Chars 128
#define DFA_NoTransition -1

typedef struct{
  int accepts;
  int transitions[ASCII_Chars];
  int stateNumber;
}DFA_State;

typedef struct {
  int states;
  DFA_State *state_array;
  int currentState;
}DFA;

extern DFA* initialize_DFA(int numStates);

extern void DFA_set_transition(DFA* dfa, int stateNumber, char inputChar, int destination);

extern int DFA_get_transition(DFA* dfa, int stateNumber, char inputChar);

extern void DFA_set_accepting(DFA* dfa, int stateNumber);

extern void print_state_array(DFA_State *array, int len);

extern void DFA_set_Lambda_Transition(DFA* dfa, int stateNumber, int destination);

extern int DFA_accepts_string(DFA* dfa, char string[],int length);
