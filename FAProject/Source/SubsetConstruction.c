#include "NFA.c"
#include "dfa.c"
#include "LinkedList.h"
#include "LinkedList.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

DFA* Convert(NFA* nfa)
{
  DFA* dfa = initialize_DFA(1 << nfa->states);//Create dfa with extra memory allocation
  int* visited = (int*)calloc(1 << nfa->states, sizeof(int));
  LinkedList* pre_nodes = LinkedList_new();//Unchecked nodes
  LinkedList_add_at_end(pre_nodes,(void*)1);//Set node 1 as first unchecked node - has to start somewhere!
  visited[1] = true;//Manually set it as visited

  while(!LinkedList_is_empty(pre_nodes))//While there are still unvisited nodes
  {
    int current_state = (int)LinkedList_pop(pre_nodes);//Int to hold temp state-to-process value

    /*In the processed DFA, each state's value IS
    *the value of the corresponding NFA states it
    * could be on, component_states holds these
    * NFA states!
    */
    LinkedSet* component_states = LinkedSet_new();

    int temp_state = current_state;//Create a temporary state for processing
    for (int i = 0; i < nfa->states; i++){//For each nfa state
      if (temp_state % 2 != 0){//If the temp( or current) state is odd
        LinkedSet_add_at_end(component_states, i);//Add the state we're checking
        if (nfa->state_array[i].accepts){//If the iterating state (i) accepts
          DFA_set_accepting(dfa,current_state);//Set the corresponding dfa state to accept as well
        }
      }
      temp_state = temp_state >> 1;
    }

    for (int i = 0; i < ASCII_Chars; i++){
      int state_num = 0;


    }
  }
return dfa;
}
