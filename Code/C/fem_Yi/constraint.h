#ifndef _CONSTRAINT
#define _CONSTRAINT 

#include <stdio.h>

typedef struct constraint {
  int tag;
  int isConstraint;
  struct constraint *next;
} Constraint;


void constraintPrint(Constraint *theConstraint);
void constraintSetup(Constraint *, int tag, int isConstraint);

#endif
