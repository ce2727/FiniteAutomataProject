#include "SubsetConstruction.h"
/*
*Converts an implementation of a NFA to a DFA. The output DFA accepts the
*same language as an NFA does, therefore accepting on strings the NFA does as well.
*/
DFA* Convert(NFA* nfa)
{
  DFA* dfa = initialize_DFA(1 << nfa->states);//Create dfa with double the states of the nfa
  int* visited = (int*)calloc(1 << nfa->states, sizeof(int));//Tells if nodes are visited yet or have been queued for visiting
  LinkedList* pre_nodes = LinkedList_new();//Unchecked nodes within the DFA - will be added to and removed from during processing
  LinkedList_add_at_end(pre_nodes,(void*)1);//Set node 1 as first unchecked node - has to start somewhere!
  visited[1] = true;//Sets the first node as visited

  while(!LinkedList_is_empty(pre_nodes))//While there are still unvisited nodes in the DFA queue
  {
    int current_state = (int)LinkedList_pop(pre_nodes);//Int to hold temp state-to-process value

    /*In the processed DFA, each state's value IS
    *the value of the corresponding NFA states it
    * could be on, component_states holds these
    * NFA states!
    */
    LinkedSet* component_states = LinkedSet_new();//The set of comprising DFA states
    //This section gathers the component_states for the new DFA state
    int temp_state = current_state;//Start at the main DFA node of interest
    for (int i = 0; i < nfa->states; i++){//For the each nfa state
      if (temp_state % 2 != 0){//If odd
        LinkedSet_add_at_end(component_states, i);//Add the state to the component list
        if (nfa->state_array[i].accepts){//If any of these nfa states is accepting
          DFA_set_accepting(dfa,current_state);//Set the corresponding dfa state to accept as well
        }
      }
      temp_state = temp_state >> 1;//Cut temp state in half via bitwise right shift
    }

    for (int i = 0; i < ASCII_Chars; i++){
      int state_num = 0;

      LinkedSetIterator *comp_state_it = LinkedSet_iterator(component_states);
      while (LinkedSetIterator_has_next(comp_state_it)){
        LinkedSetIterator *trans_states = LinkedSet_iterator(nfa->state_array[LinkedSetIterator_next(comp_state_it)].transitions[i]);
        while(LinkedSetIterator_has_next(trans_states))
          state_num = state_num | 1 << (int)LinkedSetIterator_next(trans_states);
          free(trans_states);
      }
      if (state_num != 0){
        if(visited[state_num] == 0){
          LinkedList_add_at_end(pre_nodes,(void*)state_num);
          visited[state_num] = 1;
          DFA_set_transition(dfa, current_state, i, state_num);
        } else {
          DFA_set_transition(dfa,current_state,i,state_num);
        }
      }
      free(comp_state_it);
    }
    LinkedSet_free(component_states);
  }
  LinkedList_free(pre_nodes, true);
  return dfa;
}
