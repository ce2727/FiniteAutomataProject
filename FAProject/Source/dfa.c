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



DFA* initialize_DFA(int numStates) {
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

void DFA_set_transition(DFA* dfa, int stateNumber, char inputChar, int destination)
{
    dfa->state_array[stateNumber].transitions[inputChar]=destination;//Passing in char to array index translates it to ascii value
}

int DFA_get_transition(DFA* dfa, int stateNumber, char inputChar)
{
    return dfa->state_array[stateNumber].transitions[inputChar];
}

void DFA_set_accepting(DFA* dfa, int stateNumber)
{
    dfa->state_array[stateNumber].accepts = 1;
}

void print_state_array(DFA_State *array, int len){
  for (int i=0;i < len; i++) {
    printf("State Number: %d\n", array[i].stateNumber);
  }
}

//Sets all transitions of a state to a certain destination (Lambda operation)
void DFA_set_Lambda_Transition(DFA* dfa, int stateNumber, int destination)
{
    for (int i = 0; i < ASCII_Chars; i++)
        {
          dfa->state_array[stateNumber].transitions[i] = destination;
        }
}


int DFA_accepts_string(DFA* dfa, char string[],int length)
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

/*int main(){
    printf("Automaton testing for string 'ab'\n");

    //Part 1
    //Each required dfa will be created below
    //with the suffix as the question label
    // a).
    DFA* dfa_a = initialize_DFA(3);
    DFA_set_transition(dfa_a, 0, 'a',1);
    DFA_set_transition(dfa_a, 1, 'b',2);
    DFA_set_accepting(dfa_a, 2);

    char TString[] = {'a','b','b'};
    int exeInt = DFA_accepts_string(dfa_a,TString,3);
    printf("%d (1 Accepts, 0 Declined)\n", exeInt);

    // b).
    DFA* dfa_b = initialize_DFA(3);
    DFA_set_transition(dfa_b, 0, 'a',1);
    DFA_set_transition(dfa_b, 1, 'b',2);
    DFA_set_Lambda_Transition(dfa_b,2,2);
    DFA_set_accepting(dfa_b, 2);

        // c).
    DFA* dfa_c = initialize_DFA(2);
    DFA_set_transition(dfa_c, 0, '1',1);
    DFA_set_transition(dfa_c, 0, '0',0);
    DFA_set_transition(dfa_c, 1, '1',0);
    DFA_set_transition(dfa_c, 1, '0',1);
    DFA_set_accepting(dfa_c, 0);

            // d).
    DFA* dfa_d = initialize_DFA(4);
    DFA_set_transition(dfa_d, 0, '0',1);
    DFA_set_transition(dfa_d, 1, '0',0);
    DFA_set_transition(dfa_d, 1, '1',2);
    DFA_set_transition(dfa_d, 2, '1',1);
    DFA_set_transition(dfa_d, 2, '0',3);
    DFA_set_transition(dfa_d, 3, '0',2);
    DFA_set_transition(dfa_d, 3, '1',0);
    DFA_set_transition(dfa_d, 0, '1',3);
    DFA_set_accepting(dfa_d, 0);

    char TStringd[] = {'0','1','1','0','0','1','0','1'};
    int exeIntd = DFA_accepts_string(dfa_d,TStringd,8);
    printf("%d (1 Accepts, 0 Declined)\n", exeIntd);

    // e). It asked us for an interesting pattern,
    //so my pattern is exactly the string 'interesting'
    DFA* dfa_e = initialize_DFA(12);
    DFA_set_transition(dfa_e, 0, 'i',1);
    DFA_set_transition(dfa_e, 1, 'n',2);
    DFA_set_transition(dfa_e, 2, 't',3);
    DFA_set_transition(dfa_e, 3, 'e',4);
    DFA_set_transition(dfa_e, 4, 'r',5);
    DFA_set_transition(dfa_e, 5, 'e',6);
    DFA_set_transition(dfa_e, 6, 's',7);
    DFA_set_transition(dfa_e, 7, 't',8);
    DFA_set_transition(dfa_e, 8, 'i',9);
    DFA_set_transition(dfa_e, 9, 'n',10);
    DFA_set_transition(dfa_e, 10, 'g',11);
    DFA_set_accepting(dfa_e, 11);

    char TStringe[] = {'i','n','t','e','r','e','s','t','i','n','g'};
    int exeInte = DFA_accepts_string(dfa_e,TStringe,11);
    printf("%d (1 Accepts, 0 Declined)\n", exeInte);

  }*/
