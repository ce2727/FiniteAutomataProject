#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedSet.c"
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


/**
*Creates and returns an NFA
*/
NFA* initialize_NFA(int numStates) {
	NFA* n = (NFA*)malloc(sizeof(NFA));
	n->states = numStates;
	n->state_array = (NFA_State*)malloc(numStates * sizeof(NFA_State));
	n->currentStates = LinkedSet_new();
	LinkedSet_add_at_end(n->currentStates,0);//Add new IntSet as current state and add it as to 0

	for (int i = 0; i < numStates; i++) {
		n->state_array[i].accepts = FALSE;
    n->state_array[i].stateNumber = i;
		for (int j = 0; j < ASCII_Chars; j++) {
			n->state_array[i].transitions[j] = LinkedSet_new(); //Set it to have no transitions
		}
	}

	return n;
}

/**
*Set singular transition
*/
void NFA_set_transition(NFA* nfa, int stateNumber, char inputChar, int destination)
{
    LinkedSet_add_at_end(nfa->state_array[stateNumber].transitions[(int)inputChar],destination);//Passing in char to array index translates it to ascii value
}

/**
*Sets all transitions of a state to a destination, allows for an exception (minus param (-1 to exclude))
*/
void NFA_setLambdaTransition(NFA* nfa, int minus, int stateNumber, int destination)
{
    for (int i = 0; i < ASCII_Chars; i++)
        {
          if(i != minus){//If not the minus char
          LinkedSet_add_at_end(nfa->state_array[stateNumber].transitions[i],destination);
          }
        }
}

/**
*Returns the linkedset of transitions
*/
LinkedSet* NFA_get_transition(NFA* nfa, int stateNumber, char inputChar)
{
    return nfa->state_array[stateNumber].transitions[(int)inputChar];
}

/**
*Returns all possible current states of the NFA
*/
LinkedSet* NFA_get_currentStates(NFA* nfa)
{
    return nfa->currentStates;
}

/**
*Sets an NFA's possible states to a linkedset with 1 value
*/
void NFA_set_currentState(NFA* nfa, int newState)
{
    free(nfa->currentStates);//Removes nfa's currentStates
    nfa->currentStates = LinkedSet_new();//Add create new linkedset
    LinkedSet_add_at_end(nfa->currentStates,newState);//add newstate to it
}

/**
*Sets an NFA's states to a linkedset param
*/
void NFA_set_currentStates(NFA* nfa, LinkedSet* newStates)
{
    free(nfa->currentStates);//Removes nfa's currentStates
    nfa->currentStates = newStates;//Add create new linkedset
}

/**
*Returns true if the nfa is accepting (used after processing)
*/
bool NFA_is_accepting(NFA* nfa)
{
    for (LinkedSetNode* node = nfa->currentStates->first; node != NULL; node = node->next)
    {
        if (nfa->state_array[node->data].accepts){ return true ;}
    }
    return false;
}

/**
*Gets accepting value of a state
*/
bool NFA_get_accepting(NFA* nfa, int stateNum)
{
    return nfa->state_array[stateNum].accepts;
}

/**
*Sets a state of a nfa to accepting
*/
void NFA_set_accepting(NFA* nfa, int stateNum)
{
    nfa->state_array[stateNum].accepts = true;
}
/*
*Unions an empty set pointer with all of the current state's possible transitions
*/
void NFA_union_with_all_transitions(NFA* nfa, char input, LinkedSet* targetSet)
{
    for(LinkedSetNode* possibleState = nfa->currentStates->first; possibleState != NULL; possibleState = possibleState->next)//For all possible current states
    {
        LinkedSet_Union(targetSet,nfa->state_array[possibleState->data].transitions[(int)input]);
    }
}
/**
*Main computational process, runs the NFA on a string
*/
bool NFA_accepts_string(NFA* nfa, char string[], int length)
{
    NFA_set_currentState(nfa,0);//Start at 0
    for (int i = 0; i < length; i++) {
        LinkedSet* newStates = LinkedSet_new();
        NFA_union_with_all_transitions(nfa,string[i],newStates);
        NFA_set_currentStates(nfa,newStates);
        if(LinkedSet_is_empty(NFA_get_currentStates(nfa))){
            return false;
        }
    }
    if (NFA_is_accepting(nfa)){
        return true;
    }
    return false;
}
/**
*Temp - create and run NFA
*/
int main(){
  //n1 accepts the pattern of strings ending in "man"
  NFA* n1 = initialize_NFA(4);
  NFA_set_transition(n1,0,'m',1);
  NFA_set_transition(n1,1,'a',2);
  NFA_set_transition(n1,2,'n',3);
  NFA_setLambdaTransition(n1,-1,0,0);
  NFA_set_accepting(n1,3);

  if (NFA_accepts_string(n1,"man",3)) {
      printf("n1 Works\n");
  } else {
    printf("n1 Doesn't work...\n");
  }

  //n2 accepts the pattern of strings with more than one a, g, h, i, o, s, t, or w, or more than two n’s

  NFA* n2 = initialize_NFA(20);
  NFA_set_accepting(n2,2);
  NFA_set_accepting(n2,4);
  NFA_set_accepting(n2,6);
  NFA_set_accepting(n2,8);
  NFA_set_accepting(n2,10);
  NFA_set_accepting(n2,12);
  NFA_set_accepting(n2,14);
  NFA_set_accepting(n2,16);
  NFA_set_accepting(n2,19);
  for (int i=0;i<20;i++){
    NFA_setLambdaTransition(n2,-1,i,i);
  }
  NFA_set_transition(n2,0,'a',1);
  NFA_set_transition(n2,1,'a',2);
  NFA_set_transition(n2,0,'g',3);
  NFA_set_transition(n2,3,'g',4);
  NFA_set_transition(n2,0,'h',5);
  NFA_set_transition(n2,5,'h',6);
  NFA_set_transition(n2,0,'i',7);
  NFA_set_transition(n2,7,'i',8);
  NFA_set_transition(n2,0,'o',9);
  NFA_set_transition(n2,9,'o',10);
  NFA_set_transition(n2,0,'s',11);
  NFA_set_transition(n2,11,'s',12);
  NFA_set_transition(n2,0,'t',13);
  NFA_set_transition(n2,13,'t',14);
  NFA_set_transition(n2,0,'w',15);
  NFA_set_transition(n2,15,'w',16);
  NFA_set_transition(n2,0,'n',17);
  NFA_set_transition(n2,17,'n',18);
  NFA_set_transition(n2,18,'n',19);

  if (NFA_accepts_string(n2,"nnn",3)) {
      printf("n2 Works\n");
  } else {
    printf("n2 Doesn't work\n");
  }

  NFA* n3 = initialize_NFA(4);
  NFA_set_transition(n3,0,'0',1);
  NFA_set_transition(n3,1,'0',2);
  NFA_set_transition(n3,0,'1',3);
  NFA_set_transition(n3,3,'2',1);
  NFA_setLambdaTransition(n3,-1,0,0);
  NFA_setLambdaTransition(n3,-1,2,2);
  NFA_set_accepting(n3,2);

  if (NFA_accepts_string(n3,"1100",5)) {
      printf("n3 Works\n");
  } else {
    printf("n3 Doesn't work...\n");
  }
}
