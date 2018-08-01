#include "node.h"
#include "constraint.h"

typedef struct struct_domain {
  Node *theNodes;
  Constraint *theConstraint;
} Domain;

void domainPrint(Domain *theDomain);
void domainAddNode(Domain *theDomain, int tag, double crd1, double crd2);
void domainPrintNodes(Domain *theDomain);
Node *domainGetNode(Domain *, int nodeTag);
void domainAddConstraint(Domain *theDomain, int Tag, int isconstraint);
Constraint *domainGetConstraint(Domain *, int ConstraintTag);

