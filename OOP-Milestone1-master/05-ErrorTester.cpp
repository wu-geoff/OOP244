// Final Project Milestone 1
// Version 1.0
// Date	2017/03/07
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Error class
// for submission.
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Error.h"
using namespace std;
using namespace ict;
int main(){
  Error T("Testing Error Message");
  Error e;
  bool ok = true;
  int pc = 1;
  cout << T << endl << e << endl << "isClear(): " << (e.isClear() ? "Passed!" : "failed!") << endl;
  if (!e.isClear()) ok = false;
  for (int i = 0; i < 10000000; i++){
    e = "Some error message that is really long long  long  long  long  long  long  long"
       " long  long  long  long  long  long  long  long  long  long  long  long  long"
       " long  long  long  long  long  long  long  long  long  long  long  long  long"
       " long  long  long  long  long  long  long  long  long  long  long  long  long"
       " long  long  long  long  long  long  long  long  long  long  long  long  long"
       " long  long  long  long  long  long  long  long  long  long  long  long  long"
       ;
    if (i % 100000 == 0) cout << "\r" << pc++ << "%";
  }
  cout << endl << e << endl << "isClear(): " << (e ? "Failed!" : "Passed!") << endl;
  if (e) ok = false;
  e.message("Short Error Message");
  cout << e << " is the same as " << (const char*)e << endl << "isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
  e.clear();
  cout << "Nothing here: >" << e << "<" << endl << "isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl;
  if (!e) ok = false;
  cout << (ok ? "All tests passed!" : "Failed!") << endl;
  return 0;
}