#include "DFA.h"
/*
*Creates and returns an allocated DFA pointer
*/
inline DFA* initialize_DFA(int numStates) {
	DFA* d = (DFA*)malloc(sizeof(DFA));
	d->states = numStates;
	d->state_array = (DFA_State*)malloc(numStates * sizeof(DFA_State));
	d->currentState = 0;

	for (int i = 0; i < numStates; i++) {
		d->state_array[i].accepts = FALSE;
    d->state_array[i].stateNumber = i;
		for (int j = 0; j < ASCII_Chars; j++) {
			d->state_array[i].transitions[j] = DFA_NoTransition; //Set it to have no transitions
		}
	}

	return d;
}

/*
*Sets a specific transition of a DFA
*/
inline void DFA_set_transition(DFA* dfa, int stateNumber, char inputChar, int destination)
{
    dfa->state_array[stateNumber].transitions[(int)inputChar]=destination;//Passing in char to array index translates it to ascii value
}

/*
*Gets a specific transition of a dfa
*/
inline int DFA_get_transition(DFA* dfa, int stateNumber, char inputChar)
{
    return dfa->state_array[stateNumber].transitions[(int)inputChar];
}

/*
*Sets an accepting state of a DFA
*/
inline void DFA_set_accepting(DFA* dfa, int stateNumber)
{
    dfa->state_array[stateNumber].accepts = 1;
}

/*(DEBUG)
*Prints the state array
*/
inline void print_state_array(DFA_State *array, int len)
{
  for (int i=0;i < len; i++) {
    printf("State Number: %d\n", array[i].stateNumber);
  }
}
/*
*Sets all transitions of a state to a certain destination (Lambda operation)
*/
inline void DFA_set_Lambda_Transition(DFA* dfa, int stateNumber, int destination)
{
    for (int i = 0; i < ASCII_Chars; i++)
        {
          dfa->state_array[stateNumber].transitions[i] = destination;
        }
}

/*
*Returns true (1) if the DFA accepts the input string
*/
inline int DFA_accepts_string(DFA* dfa, char string[],int length)
{
    for (int i = 0; i < length; i++)
    {
        dfa->currentState = DFA_get_transition(dfa,dfa->currentState,string[i]);
        if (dfa->currentState == -1)
        {
            return FALSE;
        }
    }
    if (dfa->state_array[dfa->currentState].accepts)
    {
        return TRUE;
    }
    return FALSE;
}
