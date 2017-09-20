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
//Create new DFA pointer
extern DFA* initialize_DFA(int numStates);
//Sets a transition from the current (stateNumber) over a inputChar to the destination state
extern void DFA_set_transition(DFA* dfa, int stateNumber, char inputChar, int destination);
//Gets a transition
extern int DFA_get_transition(DFA* dfa, int stateNumber, char inputChar);
//Sets transition as accepting
extern void DFA_set_accepting(DFA* dfa, int stateNumber);
//Prints the state array of the DFA
extern void print_state_array(DFA* dfa);
//Sets all transitions of a state to a destination
extern void DFA_set_Lambda_Transition(DFA* dfa, int stateNumber, int destination);
//Runs DFA to see if it accepts a string or not
extern int DFA_accepts_string(DFA* dfa, char string[],int length);
