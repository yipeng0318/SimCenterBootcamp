#include <iostream>
#include "shape1.h"

using namespace std;

int main(int argc, char **argv) {
  Circle s1(2.0);
  Shape *s2 = new Rectangle(1.0, 2.0);
  Shape *s3 = new Rectangle(3.0,2.0);
  
  s1.PrintArea(cout);
  s2->PrintArea(cout);
  s3->PrintArea(cout);

  return 0;
}


Shape::~Shape() {
  cout << "Shape Destructor\n";
}

void
Shape::PrintArea(ostream &s) {
  s << "UNKOWN area: " << this->GetArea() << "\n";
}
  

int Rectangle::numRect = 0;
Rectangle::~Rectangle() {
  numRect--;
  cout << "Rectangle Destructor\n";
}

Rectangle::Rectangle(double w, double d)
  :Shape(), width(w), height(d)
{
  numRect++;
}

double
Rectangle::GetArea(void) {
  return width*height;
}

void 
Rectangle::PrintArea(ostream &s) {
  s << "Rectangle: " << width * height << " numRect: " << numRect << "\n";
}

Circle::~Circle() {
  cout << "Circle Destructor\n";
}

Circle::Circle(double d) {
  diameter = d;
}

double
Circle::GetArea(void) {
  return this->GetPI() * diameter * diameter/4.0;
}

double
Circle::GetPI(void) {
  return 3.14159;
}
