#include "Executable.h"

int main(){
  NFA* n1 = initialize_NFA(4);
  NFA_set_transition(n1,0,'m',1);
  NFA_set_transition(n1,1,'a',2);
  NFA_set_transition(n1,2,'n',3);
  NFA_setLambdaTransition(n1,-1,0,0);
  NFA_set_accepting(n1,3);

  if (NFA_accepts_string(n1,"man",3)) {
      printf("NFA Works\n");
  } else {
    printf("NFA Doesn't work...\n");
  }

  DFA* converted = Convert(n1);
  if (DFA_accepts_string(converted,"man",3)) {
      printf("DFA WORKS! YOU DID IT!\n");
  } else {
    printf("DFA Doesn't work, almost there!\n");
  }
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

  /**
  *Temp - create and run NFA
  */
    //n1 accepts the pattern of strings ending in "man"

    //n2 accepts the pattern of strings with more than one a, g, h, i, o, s, t, or w, or more than two n’s
  /*
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
    */
