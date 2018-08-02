#include <stdio.h>
#include "constraint.h"

void constraintPrint(Constraint *theConstraint){
  printf("Node : %d ", theConstraint->tag);
  if (theConstraint->isConstraint == 1) {
       printf("is constrained \n");} else{printf("is not constrained \n");}
  
}

void constraintSetup(Constraint *theConstraint, int tag, int isConstraint) {
  theConstraint->tag = tag;
  theConstraint->isConstraint = isConstraint;
  theConstraint->next = NULL;
}
