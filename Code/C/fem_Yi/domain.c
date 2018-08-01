#include <stdio.h>
#include <stdlib.h>
#include "domain.h"
#include "node.h"

void domainPrint(Domain *theDomain) {
  printf("The Nodes:\n");
  domainPrintNodes(theDomain);
}

void domainAddNode(Domain *theDomain, int tag, double crd1, double crd2) {
  Node *theNextNode = (Node *)malloc(sizeof(Node));
  nodeSetup(theNextNode, tag, crd1, crd2);

  if (theDomain->theNodes != NULL) {
    theNextNode->next = theDomain->theNodes;
  } else {
    theNextNode->next = NULL;
  }
  theDomain->theNodes = theNextNode;
}

void domainPrintNodes(Domain *theDomain) {
  Node *theCurrentNode = theDomain->theNodes;
  while (theCurrentNode != NULL) {
    nodePrint(theCurrentNode);
    theCurrentNode = theCurrentNode->next;
  };
}

Node *domainGetNode(Domain *theDomain, int nodeTag) {
  Node *theCurrentNode = theDomain->theNodes;
  while (theCurrentNode != NULL) {
    if (theCurrentNode->tag == nodeTag) {
      return theCurrentNode;
    } else {
      theCurrentNode = theCurrentNode->next;
    }
  };
  return NULL;
}

void domainAddConstraint(Domain *theDomain, int Tag, int isconstraint) {
  Constraint *theNextConstraint = (Constraint *)malloc(sizeof(Constraint));
  constraintSetup(theNextConstraint, Tag, isconstraint);

  if (theDomain->theConstraint != NULL) {
    
    theNextConstraint->next = theDomain->theConstraint;
  } else {
    theNextConstraint->next = NULL;
  }
  theDomain->theConstraint = theNextConstraint;

}

Constraint *domainGetConstraint(Domain *theDomain, int ConstraintTag) {
  Constraint *theCurrentConstraint = theDomain->theConstraint;
  while (theCurrentConstraint != NULL) {
    if (theCurrentConstraint->tag == ConstraintTag) {
      return theCurrentConstraint;
    } else {
      theCurrentConstraint = theCurrentConstraint->next;
    }
  };

  return NULL;
}
