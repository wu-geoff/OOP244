// Final Project Milestone 4
// Non-Periashable Tester program 2
// Version 1.0
// Date 2017-03-23
// Author Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2017-03-23           Preliminary release    
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
  cout << "----Display test, the output of the Program and yours must match:" << endl;
  piv("1234", "Box", "123.45", "y", "2");
  cin >> np;
  cin.ignore(1000, '\n');
  cout << "--Linear------------" << endl;
  cout << "Program: 1234   |Box                 | 123.45| TN|   2|   279.00|" << endl;
  cout << "  Yours: " << np << endl;
  cout << "--Form Display------" << endl;
  cout << "--Program: " << endl;
  cout << "Name:" <<endl << "Box" << endl;
  cout << "Sku: 1234" << endl;
  cout << "Price: 123.45" << endl;
  cout << "Price after tax: 139.50" << endl;
  cout << "Quantity: 2" << endl;
  cout << "Total Cost: 279.00" << endl;
  cout << "--Yours: " << endl;
  np.write(cout, false);
  cout << endl << "If the program outputs and your outputs match, the test is passed."<<endl<<"Now run 03-NPSaveLoad.cpp" << endl;
  return 0;
}

/*
Ouput:
----Display test, the output of the Program and yours must match:
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
--Linear------------
Program: 1234   |Box                 | 123.45| TN|   2|   279.00|
Yours: 1234   |Box                 | 123.45| TN|   2|   279.00|
--Form Display------
--Program:
Name:
Box
Sku: 1234
Price: 123.45
Price after tax: 139.50
Quantity: 2
Total Cost: 279.00
--Yours:
Name:
Box
Sku: 1234
Price: 123.45
Price after tax: 139.50
Quantity: 2
Total Cost: 279.00

If the program outputs and your outputs match, the test is passed.
Now run 03-NPSaveLoad.cpp*/