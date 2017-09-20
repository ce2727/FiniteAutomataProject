#include "Executable.h"

  int main(){


    /**
    *Deterministic Finite Automata
    */

    //Exactly the string 'ab'
    // a).
    printf("Automaton testing for string 'ab'\n");

    DFA* dfa_a = initialize_DFA(3);
    DFA_set_transition(dfa_a, 0, 'a',1);
    DFA_set_transition(dfa_a, 1, 'b',2);
    DFA_set_accepting(dfa_a, 2);

    char TStringa[] = {'a','b'};
    int exeInta = DFA_accepts_string(dfa_a,TStringa,2);
    printf("%d (1 Accepts, 0 Declined)\n", exeInta);

    //Any string starting with ab
    // b).
    printf("Automaton testing for any string starting with sub-string 'ab'\n");

    DFA* dfa_b = initialize_DFA(3);
    DFA_set_transition(dfa_b, 0, 'a',1);
    DFA_set_transition(dfa_b, 1, 'b',2);
    DFA_set_Lambda_Transition(dfa_b,2,2);
    DFA_set_accepting(dfa_b, 2);

    char TStringb[] = {'a','b'};
    int exeIntb = DFA_accepts_string(dfa_b,TStringb,2);
    printf("%d (1 Accepts, 0 Declined)\n", exeIntb);

    //Binary input with even number of 1's
    printf("Automaton testing for even  # of 1's \n");

    DFA* dfa_c = initialize_DFA(2);
    DFA_set_transition(dfa_c, 0, '1',1);
    DFA_set_transition(dfa_c, 0, '0',0);
    DFA_set_transition(dfa_c, 1, '1',0);
    DFA_set_transition(dfa_c, 1, '0',1);
    DFA_set_accepting(dfa_c, 0);

    char TStringc[] = {'1','1'};
    int exeIntc = DFA_accepts_string(dfa_c,TStringc,2);
    printf("%d (1 Accepts, 0 Declined)\n", exeIntc);

    //Binary with even 0's and 1's
    printf("Automaton testing for even # of 1's and 0's\n");

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

    //Exactly the string 'interesting'

    printf("Automaton testing for string 'interesting'\n");
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

    /**
    *Non-Deterministic Finite Automata
    */

    //Strings with more than one a, g, h, i, o, s, t, or w, or more than two n’s
    printf("Automaton testing for strings with more than one a, g, h, i, o, s, t, or w, or more than two n's\n");

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

    /*
    *Random example nfa
    */

    NFA* n3 = initialize_NFA(4);
    NFA_set_transition(n3,0,'0',1);
    NFA_set_transition(n3,1,'0',2);
    NFA_set_transition(n3,0,'1',3);
    NFA_set_transition(n3,3,'2',1);
    NFA_setLambdaTransition(n3,-1,0,0);
    NFA_setLambdaTransition(n3,-1,2,2);
    NFA_set_accepting(n3,2);

    if (NFA_accepts_string(n3,"1100",4)) {
        printf("n3 Works\n");
    } else {
      printf("n3 Doesn't work...\n");
    }
}
