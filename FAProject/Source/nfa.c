#include "NFA.h"

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
inline void NFA_set_transition(NFA* nfa, int stateNumber, char inputChar, int destination)
{
    LinkedSet_add_at_end(nfa->state_array[stateNumber].transitions[(int)inputChar],destination);//Passing in char to array index translates it to ascii value
}

/**
*Sets all transitions of a state to a destination, allows for an exception (minus param (-1 to exclude))
*/
inline void NFA_setLambdaTransition(NFA* nfa, int minus, int stateNumber, int destination)
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
inline LinkedSet* NFA_get_transition(NFA* nfa, int stateNumber, char inputChar)
{
    return nfa->state_array[stateNumber].transitions[(int)inputChar];
}

/**
*Returns all possible current states of the NFA
*/
inline LinkedSet* NFA_get_currentStates(NFA* nfa)
{
    return nfa->currentStates;
}

/**
*Sets an NFA's possible states to a linkedset with 1 value
*/
inline void NFA_set_currentState(NFA* nfa, int newState)
{
    free(nfa->currentStates);//Removes nfa's currentStates
    nfa->currentStates = LinkedSet_new();//Add create new linkedset
    LinkedSet_add_at_end(nfa->currentStates,newState);//add newstate to it
}

/**
*Sets an NFA's states to a linkedset param
*/
inline void NFA_set_currentStates(NFA* nfa, LinkedSet* newStates)
{
    free(nfa->currentStates);//Removes nfa's currentStates
    nfa->currentStates = newStates;//Add create new linkedset
}

/**
*Returns true if the nfa is accepting (used after processing)
*/
inline bool NFA_is_accepting(NFA* nfa)
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
inline bool NFA_get_accepting(NFA* nfa, int stateNum)
{
    return nfa->state_array[stateNum].accepts;
}

/**
*Sets a state of a nfa to accepting
*/
inline void NFA_set_accepting(NFA* nfa, int stateNum)
{
    nfa->state_array[stateNum].accepts = true;
}

/*
*Unions an empty set pointer with all of the current state's possible transitions
*/
inline void NFA_union_with_all_transitions(NFA* nfa, char input, LinkedSet* targetSet)
{
    for(LinkedSetNode* possibleState = nfa->currentStates->first; possibleState != NULL; possibleState = possibleState->next)//For all possible current states
    {
        LinkedSet_Union(targetSet,nfa->state_array[possibleState->data].transitions[(int)input]);
    }
}

/**
*Main computational process, runs the NFA on a string
*/
inline bool NFA_accepts_string(NFA* nfa, char string[], int length)
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
