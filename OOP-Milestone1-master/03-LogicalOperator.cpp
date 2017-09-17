// Final Project Milestone 1
// Student Logical operator Tester program
// Version 1.0
// Date	2017/03/07
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include "Date.h"
#include "POS.h"
using namespace std;
using namespace ict;

int main(){
  int ret = 0;
  bool ok = true;
  if (ok){
    cout << "Testing the logical operators: " << endl;
  }
  if (ok){
    Date A(2018, 10, 18, 15);
    Date B(2018, 10, 18, 15);
    cout << "testing operator==" << endl;
    if (A == B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is equal to " << B << " but operator== returns otherwise!" << endl;
      ok = false;
    }
  }

  if (ok){
    Date A(2018, 10, 18, 15);
    Date B(2018, 10, 18, 15);
    cout << "testing operator>=" << endl;
    if (A >= B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is equal to " << B << endl << "but operator>= returns otherwise!" << endl;
      ok = false;
    }
  }

  if (ok){
    Date A(2018, 10, 18, 15);
    Date B(2018, 10, 18, 15);
    cout << "testing operator<=" << endl;
    if (A <= B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is equal to " << B << endl << "but operator<= returns otherwise!" << endl;
      ok = false;
    }
  }

  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18, 15);
    cout << "testing operator!=" << endl;
    if (A != B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is not equal to " << B << " but operator!= returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18, 15);
    cout << "testing operator<" << endl;
    if (A < B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is less than " << B << " but operator< returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18, 15);
    cout << "testing operator>" << endl;
    if (B > A){
      cout << "passed!" << endl;
    }
    else{
      cout << B << " is greater than " << B << " but operator> returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18, 15);
    cout << "testing operator<=" << endl;
    if (A < B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is less than " << B << " but operator<= returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18, 15);
    cout << "testing operator>=" << endl;
    if (B >= A){
      cout << "passed!" << endl;
    }
    else{
      cout << B << " is greater than " << B << " but operator>= returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    cout << "You passed logical operator tests, now run test no 4!" << endl;
  }
  else{
    cout << "You did not pass all the tests, keep working on your project!" << endl;
    ret = 1;
  }

  return ret;
}
