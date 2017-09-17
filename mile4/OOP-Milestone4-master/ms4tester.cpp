// Final Project Milestone 4
// Non-Periashable Tester program 1
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
#include "Perishable.h"
using namespace ict;
using namespace std;
const char nonPerFile[] = "nonper.txt";
const char PerFile[] = "per.txt";
void piv(const char* sku, const char* name, const char* price = "",
  const char* taxed = "", const char* qty = "", const char* date = ""){
  cout
    << "Enter the following: " << endl
    << "Sku: " << sku << endl
    << "Name:" << endl << name << endl;
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
bool yes(){
  char ch;
  cin >> ch;
  cin.ignore(1000, '\n');
  return (ch == 'y' || ch == 'Y');
}
int main(){
  NonPerishable np;
  Perishable pr;
  bool ok = true;
  cout << "Tester 1 ---------------------------------------------------------------------" << endl
    << "--NonPerishable Error Handling test:" << endl;
  cout << "----Price validation test:" << endl;
  piv("abc", "abc", "abc");
  cin >> np;
  if (cin.fail()){
    cin.clear();
    cin.ignore(2000, '\n');
    cout << "Passed " << np << endl;
  }
  else{
    ok = false;
    cout << "Price validation failed" << endl;
    _pause();
  }
  if (ok){
    cout << "----Taxed validation test:" << endl;
    piv("abc", "abc", "10", "abc");
    cin >> np;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Passed " << np << endl;
    }
    else{
      ok = false;
      cout << "Taxed validaton failed" << endl;
      _pause();
    }
  }
  if (ok){
    cout << "----Quantity validation test:" << endl;
    piv("abc", "abc", "10", "y", "abc");
    cin >> np;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Passed " << np << endl;
    }
    else{
      ok = false;
      cout << "Quantity validaton failed" << endl;
      _pause();
    }
  }
  if (ok){
    cout << "Tester 2 ---------------------------------------------------------------------" << endl
      << "----Display test, the output of the Program and yours must match:" << endl;
    piv("1234", "Box", "123.45", "y", "2");
    cin >> np;
    cin.ignore(1000, '\n');
    cout << "--Linear------------" << endl;
    cout << "Program: 1234   |Box                 | 123.45| TN|   2|   279.00|" << endl;
    cout << "  Yours: " << np << endl;
    cout << "--Form Display------" << endl;
    cout << "--Program: " << endl;
    cout << "Name:" << endl << "Box" << endl;
    cout << "Sku: 1234" << endl;
    cout << "Price: 123.45" << endl;
    cout << "Price after tax: 139.50" << endl;
    cout << "Quantity: 2" << endl;
    cout << "Total Cost: 279.00" << endl;
    cout << "--Yours: " << endl;
    np.write(cout, false);
    cout << endl << "Did the program and your outputs match? (y)es/(n)o: ";
    ok = yes();
  }
  if (ok){
    cout << "Tester 3 ---------------------------------------------------------------------" << endl;
    fstream npfile(nonPerFile, ios::out);
    cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
    NonPerishable tnp;
    np.taxed(false);
    np.save(npfile) << endl;
    np.save(npfile) << endl;
    npfile.close();
    cout << "--Save NonPerishable, program: " << endl
      << "N,1234,Box,123.45,0,2" << endl
      << "N,1234,Box,123.45,0,2" << endl;
    cout << "--Save NonPerishable, yours: " << endl;
    dumpFile(nonPerFile);
    cout << "--Load NonPerishable: " << endl;
    npfile.open(nonPerFile, ios::in);
    npfile.ignore(2);
    tnp.load(npfile);
    cout << "Program: 1234   |Box                 | 123.45|  N|   2|   246.90|" << endl;
    cout << "  Yours: " << tnp << endl;
    npfile.clear();
    npfile.close();
    cout << endl << "Did the program and your outputs match? (y)es/(n)o: ";
    ok = yes();
  }
  if (ok){
    cout << "Tester 4 ---------------------------------------------------------------------" << endl;
    cout << "--Perishable Error Handling test:" << endl;
    cout << "Each test must display the error message related to the test." << endl << endl;
    cout << "----Price validation test:" << endl;
    piv("abc", "abc", "abc");
    cin >> pr;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Error: " << pr << endl;
    }
    else{
      ok = false;
      cout << "Price validation failed" << endl;
      _pause();
    }
    if (ok){
      cout << "----Taxed validation test:" << endl;
      piv("abc", "abc", "10", "abc");
      cin >> pr;
      if (cin.fail()){
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Error: " << pr << endl;
      }
      else{
        ok = false;
        cout << "Taxed validaton failed" << endl;
        _pause();
      }
    }
    if (ok){
      cout << "----Quantity validation test:" << endl;
      piv("abc", "abc", "10", "y", "abc");
      cin >> pr;
      if (cin.fail()){
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Error: " << pr << endl;
      }
      else{
        ok = false;
        cout << "Quantity validaton failed" << endl;
        _pause();
      }
    }
  }
  if (ok){
    cout << "Tester 5 ---------------------------------------------------------------------" << endl;
    cout << "--Perishable Expiry Date Error Handling test:" << endl;
    cout << "Each test must display the error message related to the test." << endl << endl;
    if (ok){
      cout << "----Invalid Date Entry validation test:" << endl;
      piv("a", "a", "1", "y", "1", "a");
      cin >> pr;
      if (cin.fail()){
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Error: " << pr << endl;
      }
      else{
        ok = false;
        cout << "Date validaton failed" << endl;
        _pause();
      }
    }
    if (ok){
      cout << "----Invalid Year Entry validation test:" << endl;
      piv("a", "a", "1", "y", "1", "10/10/10");
      cin >> pr;
      if (cin.fail()){
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Error: " << pr << endl;
      }
      else{
        ok = false;
        cout << "Year validaton failed" << endl;
        _pause();
      }
    }
    if (ok){
      cout << "----Invalid Month Entry validation test:" << endl;
      piv("a", "a", "1", "y", "1", "2000/13/10");
      cin >> pr;
      if (cin.fail()){
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Error: " << pr << endl;
      }
      else{
        ok = false;
        cout << "Month validaton failed" << endl;
        _pause();
      }
    }
    if (ok){
      cout << "----Invalid Day Entry validation test:" << endl;
      piv("a", "a", "1", "y", "1", "2000/10/0");
      cin >> pr;
      if (cin.fail()){
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Error: " << pr << endl;
      }
      else{
        ok = false;
        cout << "Year validaton failed" << endl;
        _pause();
      }
    }
  }
  if (ok){
    cout << "Tester 6 ---------------------------------------------------------------------" << endl;
    cout << "----Display test, the output of the Program and yours must match:" << endl;
    piv("1234", "Box", "123.45", "y", "2", "2015/11/26");
    cin >> pr;
    cin.ignore(1000, '\n');
    cout << "--Linear------------" << endl;
    cout << "Program: 1234   |Box                 | 123.45| TP|   2|   279.00|" << endl;
    cout << "  Yours: " << pr << endl;
    cout << "--Form Display------" << endl;
    cout << "--Program: " << endl;
    cout << "Name:" << endl << "Box" << endl;
    cout << "Sku: 1234" << endl;
    cout << "Price: 123.45" << endl;
    cout << "Price after tax: 139.50" << endl;
    cout << "Quantity: 2" << endl;
    cout << "Total Cost: 279.00" << endl;
    cout << "Expiry date: 2015/11/26" << endl;
    cout << "--Yours: " << endl;
    pr.write(cout, false);
    cout << endl << "If the program outputs and your outputs match, the test is passed." << endl;
    cout << endl << "Did the program and your outputs match? (y)es/(n)o: ";
    ok = yes();
  }
  if (ok){
    cout << "Tester 7 ---------------------------------------------------------------------" << endl;
    fstream prfile(PerFile, ios::out);
    cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
    Perishable tpr;
    pr.taxed(false);
    pr.save(prfile) << endl;
    pr.save(prfile) << endl;
    prfile.close();
    cout << "--Save NonPerishable, program: " << endl
      << "P,1234,Box,123.45,0,2,2015/11/26" << endl
      << "P,1234,Box,123.45,0,2,2015/11/26" << endl;
    cout << "--Save Perishable, yours: " << endl;
    dumpFile(PerFile);
    cout << "--Load Perishable: " << endl;
    prfile.open(PerFile, ios::in);
    prfile.ignore(2);
    tpr.load(prfile);
    cout << "--Program: " << endl;
    cout << "Name:" << endl << "Box" << endl;
    cout << "Sku: 1234" << endl;
    cout << "Price: 123.45" << endl;
    cout << "Price after tax: N/A" << endl;
    cout << "Quantity: 2" << endl;
    cout << "Total Cost: 246.90" << endl;
    cout << "Expiry date: 2015/11/26" << endl;
    cout << "--Yours: " << endl;
    pr.write(cout, false);
    prfile.clear();
    prfile.close();
    cout << endl << "Did the program and your outputs match? (y)es/(n)o: ";
    ok = yes();
  }
  if (ok){
    cout << "It seems you passed all the tests" << endl << "If this program is running within the submission script, type exit to have the outputs tested." << endl;
  }
  else{
    cout << "Did not pass all the tests, please fix the problems and try again." << endl;
  }
}

/*
Tester 1 ---------------------------------------------------------------------
--NonPerishable Error Handling test:
----Price validation test:
Enter the following:
Sku: abc
Name:
abc
Price: abc

Item Entry:
Sku: abc
Name:
abc
Price: abc
Passed Invalid Price Entry
----Taxed validation test:
Enter the following:
Sku: abc
Name:
abc
Price: 10
Taxed: abc

Item Entry:
Sku: abc
Name:
abc
Price: 10
Taxed: abc
Passed Invalid Taxed Entry, (y)es or (n)o
----Quantity validation test:
Enter the following:
Sku: abc
Name:
abc
Price: 10
Taxed: y
Quantity: abc

Item Entry:
Sku: abc
Name:
abc
Price: 10
Taxed: y
Quantity: abc
Passed Invalid Quantity Entry
Tester 2 ---------------------------------------------------------------------
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

Did the program and your outputs match? (y)es/(n)o: y
Tester 3 ---------------------------------------------------------------------
----Storage and loading test, the output of the Program and yours must match:
--Save NonPerishable, program:
N,1234,Box,123.45,0,2
N,1234,Box,123.45,0,2
--Save NonPerishable, yours:
N,1234,Box,123.45,0,2
N,1234,Box,123.45,0,2
--Load NonPerishable:
Program: 1234   |Box                 | 123.45|  N|   2|   246.90|
  Yours: 1234   |Box                 | 123.45|  N|   2|   246.90|

Did the program and your outputs match? (y)es/(n)o: y
Tester 4 ---------------------------------------------------------------------
--Perishable Error Handling test:
Each test must display the error message related to the test.

----Price validation test:
Enter the following:
Sku: abc
Name:
abc
Price: abc

Perishable Item Entry:
Sku: abc
Name:
abc
Price: abc
Error: Invalid Price Entry
----Taxed validation test:
Enter the following:
Sku: abc
Name:
abc
Price: 10
Taxed: abc

Perishable Item Entry:
Sku: abc
Name:
abc
Price: 10
Taxed: abc
Error: Invalid Taxed Entry, (y)es or (n)o
----Quantity validation test:
Enter the following:
Sku: abc
Name:
abc
Price: 10
Taxed: y
Quantity: abc

Perishable Item Entry:
Sku: abc
Name:
abc
Price: 10
Taxed: y
Quantity: abc
Error: Invalid Quantity Entry
Tester 5 ---------------------------------------------------------------------
--Perishable Expiry Date Error Handling test:
Each test must display the error message related to the test.

----Invalid Date Entry validation test:
Enter the following:
Sku: a
Name:
a
Price: 1
Taxed: y
Quantity: 1
Expiry date: a

Perishable Item Entry:
Sku: a
Name:
a
Price: 1
Taxed: y
Quantity: 1
Expiry date (YYYY/MM/DD): a
Error: Invalid Date Entry
----Invalid Year Entry validation test:
Enter the following:
Sku: a
Name:
a
Price: 1
Taxed: y
Quantity: 1
Expiry date: 10/10/10

Perishable Item Entry:
Sku: a
Name:
a
Price: 1
Taxed: y
Quantity: 1
Expiry date (YYYY/MM/DD): 10/10/10
Error: Invalid Year in Date Entry
----Invalid Month Entry validation test:
Enter the following:
Sku: a
Name:
a
Price: 1
Taxed: y
Quantity: 1
Expiry date: 2000/13/10

Perishable Item Entry:
Sku: a
Name:
a
Price: 1
Taxed: y
Quantity: 1
Expiry date (YYYY/MM/DD): 2000/13/10
Error: Invalid Month in Date Entry
----Invalid Day Entry validation test:
Enter the following:
Sku: a
Name:
a
Price: 1
Taxed: y
Quantity: 1
Expiry date: 2000/10/0

Perishable Item Entry:
Sku: a
Name:
a
Price: 1
Taxed: y
Quantity: 1
Expiry date (YYYY/MM/DD): 2000/10/0
Error: Invalid Day in Date Entry
Tester 6 ---------------------------------------------------------------------
----Display test, the output of the Program and yours must match:
Enter the following:
Sku: 1234
Name:
Box
Price: 123.45
Taxed: y
Quantity: 2
Expiry date: 2015/11/26

Perishable Item Entry:
Sku: 1234
Name:
Box
Price: 123.45
Taxed: y
Quantity: 2
Expiry date (YYYY/MM/DD): 2015/11/26
--Linear------------
Program: 1234   |Box                 | 123.45| TP|   2|   279.00|
  Yours: 1234   |Box                 | 123.45| TP|   2|   279.00|
--Form Display------
--Program:
Name:
Box
Sku: 1234
Price: 123.45
Price after tax: 139.50
Quantity: 2
Total Cost: 279.00
Expiry date: 2015/11/26
--Yours:
Name:
Box
Sku: 1234
Price: 123.45
Price after tax: 139.50
Quantity: 2
Total Cost: 279.00
Expiry date: 2015/11/26

If the program outputs and your outputs match, the test is passed.

Did the program and your outputs match? (y)es/(n)o: y
Tester 7 ---------------------------------------------------------------------
----Storage and loading test, the output of the Program and yours must match:
--Save NonPerishable, program:
P,1234,Box,123.45,0,2,2015/11/26
P,1234,Box,123.45,0,2,2015/11/26
--Save Perishable, yours:
P,1234,Box,123.45,0,2,2015/11/26
P,1234,Box,123.45,0,2,2015/11/26
--Load Perishable:
--Program:
Name:
Box
Sku: 1234
Price: 123.45
Price after tax: N/A
Quantity: 2
Total Cost: 246.90
Expiry date: 2015/11/26
--Yours:
Name:
Box
Sku: 1234
Price: 123.45
Price after tax: N/A
Quantity: 2
Total Cost: 246.90
Expiry date: 2015/11/26

Did the program and your outputs match? (y)es/(n)o: y
It seems you passed all the tests
If this program is running within the submission script, type exit to have the outputs tested.
*/













