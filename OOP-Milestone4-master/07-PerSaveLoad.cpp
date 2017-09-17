// Final Project Milestone 4
// Non-Periashable Tester program 7
// Version 1.0
// Date 2017-03-23
// Author Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2017-03-23           Preliminary release    
/////////////////////////////////////////////////////////////////
#include "Perishable.h"
using namespace ict;
using namespace std;
#define FileName "perish.txt"
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
  fstream prfile(FileName, ios::out);
  Perishable pr;
  cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
  piv("1234", "Box", "123.45", "y", "2", "2015/11/25");
  cin >> pr;
  cin.ignore(1000, '\n');
  Perishable tpr;
  pr.taxed(false);
  pr.save(prfile) << endl;
  pr.save(prfile) << endl;
  prfile.close();
  cout << "--Save NonPerishable, program: " << endl
    << "P,1234,Box,123.45,0,2,2015/11/25" << endl
    << "P,1234,Box,123.45,0,2,2015/11/25" << endl;
  cout << "--Save Perishable, yours: " << endl;
  dumpFile(FileName);
  cout << "--Load Perishable: " << endl;
  prfile.open(FileName, ios::in);
  prfile.ignore(2);
  tpr.load(prfile);
  cout << "Program: 1234   |Box                 | 123.45|  P|   2|   246.90|" << endl;
  cout << "  Yours: " << tpr << endl;
  prfile.clear();
  prfile.close();
  cout << endl << "If the program outputs and your outputs match, the test is passed." << endl << "Now you can submit milestone 4!" << endl;
  return 0;
}

/*
Output:
----Storage and loading test, the output of the Program and yours must match:
Enter the following:
Sku: 1234
Name:
Box
Price: 123.45
Taxed: y
Quantity: 2
Expiry date: 2015/11/25

Perishable Item Entry:
Sku: 1234
Name:
Box
Price: 123.45
Taxed: y
Quantity: 2
Expiry date (YYYY/MM/DD): 2015/11/25
--Save NonPerishable, program:
P,1234,Box,123.45,0,2,2015/11/25
P,1234,Box,123.45,0,2,2015/11/25
--Save Perishable, yours:
P,1234,Box,123.45,0,2,2015/11/25
P,1234,Box,123.45,0,2,2015/11/25
--Load Perishable:
Program: 1234   |Box                 | 123.45|  P|   2|   246.90|
  Yours: 1234   |Box                 | 123.45|  P|   2|   246.90|

If the program outputs and your outputs match, the test is passed.
Now you can submit milestone 4!
*/