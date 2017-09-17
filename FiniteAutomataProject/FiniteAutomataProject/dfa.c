#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NoTransition -1
#define ASCII_Chars 128
#define DFA_state_size sizeof(DFAState*)
#define TRUE 1
#define FALSE 0

typedef struct DFAState DFAState;
typedef struct DFA DFA;

struct DFAState{
	int transitions[ASCII_Chars];
	int accepts;
};

struct DFA{
	int numStates;
	DFAState* currentState;
	DFAState* stateArray;

};


typedef struct {
	int state;
}NFA;


DFA* initialize_DFA(int numStates) {
	DFA* d = (DFA*)malloc(sizeof(DFA));
	d->numStates = numStates;
	d->stateArray = (DFAState*)malloc(numStates * DFA_state_size);
	d->currentState = 0;

	for (int i = 0; i < numStates; i++) {
		printf("Does it die here? ");
		d->stateArray[i].accepts = FALSE;//Each state is initialized to not accepting upon creation
		for (int j = 0; j < ASCII_Chars; j++) {//For each position in the array
			
			d->stateArray[i].transitions[j] = NoTransition; //Set it to have no transitions
		}
	}
	
	return d;
}



int main() {
	printf("Automaton testing for string 'ab'\n");

	DFA* dfa = initialize_DFA(3);
	//TODO create actual graph
	//Main array is which current state, sub arrays are transitions
	//Create a 2d array via double pointer - the size of two DFAStates
	//dfa->stateArray[0].transitions[97] = 1;
	//dfa->stateArray[1].transitions[98] = 2;
	//dfa->stateArray[2].accepts = true;
	printf("Done!");
}