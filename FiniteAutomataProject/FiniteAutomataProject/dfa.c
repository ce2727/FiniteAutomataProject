#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//#define ASCII_Chars 128
//#define DFA_state_size sizeof(DFAState*)
typedef struct DFAState DFAState;
typedef struct DFA DFA;

struct DFAState{
	int transitions[128];
	bool accepts;
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
	DFA* d = (DFA*)malloc(sizeof(DFA*));
	d->numStates = numStates;
	d->stateArray  = (DFAState*)malloc(numStates * sizeof(DFAState*));

	for (int i = 0; i < d->numStates; i++) {
		
	}
	return d;
}


int main() {
	printf("Automaton testing for string 'ab'\n");

	DFA* dfa = initialize_DFA(5);
	//TODO create actual graph
	int thing[2][2];
}