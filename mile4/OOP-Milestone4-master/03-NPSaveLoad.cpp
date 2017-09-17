// Final Project Milestone 4
// Non-Periashable Tester program 3
// Version 1.0
// Date 2017-03-23
// Author Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2017-03-23          Preliminary release    
/////////////////////////////////////////////////////////////////
#include "NonPerishable.h"
using namespace ict;
using namespace std;
#define FileName "nonper.txt"
void piv(const char* upc, const char* name, const char* price = "", 
  const char* taxed = "", const char* qty = "", const char* date = ""){
  cout
    << "Enter the following: " << endl
    << "Sku: " << upc << endl
    << "Name:" <<endl << name << endl;
  if (price[0]) cout << "Price: " << price << endl;
  if (taxed[0]) cout << "Taxed: " << taxed << endl;
  if (qty[0]) cout << "Quantity: " << qty << endl;
  if (date[0]) cout << "Expiry date: " << date << endl;
  cout << endl;
}
void dumpFile(const char* fname){
  ifstream f(fname);
  char ch;
  while (!f.get(ch).fail()){
    cout.put(ch);
  }
  f.clear();
  f.close();
}
void _pause(){
  cout << "****press enter to continue...";
  cin.ignore(1000, '\n');
}

int main(){
  fstream npfile(FileName, ios::out);
  NonPerishable np;
  cout << "----NonPerishable Storage and loading test, the output of the Program and yours must match:" << endl;
  piv("1234", "Box", "123.45", "y", "2");
  cin >> np;
  cin.ignore(1000, '\n');
  NonPerishable tnp;
  np.taxed(false);
  np.save(npfile) << endl;
  np.save(npfile) << endl;
  npfile.close();
  cout << "--Save NonPerishable, program: " << endl
    << "N,1234,Box,123.45,0,2" << endl
    << "N,1234,Box,123.45,0,2" << endl;
  cout << "--Save NonPerishable, yours: " << endl;
  dumpFile(FileName);
  cout << "--Load NonPerishable: " << endl;
  npfile.open(FileName, ios::in);
  npfile.ignore(2);
  tnp.load(npfile);
  cout << "Program: 1234   |Box                 | 123.45|  N|   2|   246.90|" << endl;
  cout << "  Yours: " << tnp << endl;
  npfile.clear();
  npfile.close();
  cout << endl << "If the program outputs and your outputs match, the test is passed." << endl << "Now run 04-PerErrHandling.cpp" << endl;
  return 0;
}
/*
Output:
----NonPerishable Storage and loading test, the output of the Program and yours must match:
Enter the following:
Sku: 1234
Name:
Box
Price: 123.45
Taxed: y
Quantity: 2

Item Entry:
Sku: 1234
Name:
Box
Price: 123.45
Taxed: y
Quantity: 2
--Save NonPerishable, program:
N,1234,Box,123.45,0,2
N,1234,Box,123.45,0,2
--Save NonPerishable, yours:
N,1234,Box,123.45,0,2
N,1234,Box,123.45,0,2
--Load NonPerishable:
Program: 1234   |Box                 | 123.45|  N|   2|   246.90|
Yours: 1234   |Box                 | 123.45|  N|   2|   246.90|

If the program outputs and your outputs match, the test is passed.
Now run 04-PerErrHandling.cpp
*/