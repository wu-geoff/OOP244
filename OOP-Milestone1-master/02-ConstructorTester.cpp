// Final Project Milestone 1
// Student constructor tester
// Version 1.0
// Date	2017/03/07
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Date.h"
#include "POS.h"
using namespace std;
using namespace ict;

bool equalDates(const Date& A, const Date& B);
bool yes();
int main(){
  int ret = 0;
  bool ok = true;
  if (ok){
     cout << "Testing Date constructors and operator<< overload; " << endl;
    time_t t = time(NULL);
    Date Cur;
    tm lt = *localtime(&t);
    Date tCur(lt.tm_year + 1900, lt.tm_mon + 1, lt.tm_mday, lt.tm_hour, lt.tm_min);
    cout << tCur << (equalDates(tCur, Cur) ? " is the same as " : " is not the same as ") << Cur << endl;

    if (equalDates(tCur, Cur)){
       cout << "Passed!" << endl;
    }
    else{
       cout << "One or more of the Date constructors or operator<< are not implemented correctly." << endl;
       ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 18);
    Date B = A;
    cout << "Testing Date(int, int, int) constructor and operator>> overload; " << endl;
    cout << "enter the following date, 2018/10/18" << endl << ">";
    cin >> B;

    if (!equalDates(A, B)){
      cout << "Either the constructor or operator>> is not implemented correctly." << endl;
      ok = false;
    }
    else{
      cout << "Passed!" << endl;
    }
  }
  if (ok){
    Date A(2015, 9, 7, 14, 30);
    Date B = A;
    B.dateOnly(false);
    cout << "Testing Date(int, int, int,int,int) constructor and operator>> overload; " << endl;
    cout << "enter the following date, 2015/9/7, 14:30" << endl << ">";
    cin >> B;

    if (!equalDates(A, B)){
      cout << "Either the constructor or operator>> is not implemented correctly." << endl;
      ok = false;
    }
    else{
      cout << "Passed!" << endl;
    }
  }
  if (ok){
    Date A(2015, 9, 7, 15);
    Date B = A;
    B.dateOnly(false);
    cout << "Testing Date(int, int, int,int,int=0) constructor and operator>> overload; " << endl;
    cout << "enter the following date, 2015/9/7, 15:0" << endl << ">";
    cin >> B;

    if (!equalDates(A, B)){
      cout << "Either the constructor or operator>> is not implemented correctly." << endl;
      ok = false;
    }
    else{
      cout << "Passed!" << endl;
    }
  }
  if (ok){
    cout << "You passed all Constructor tests, run test no 3!" << endl;
  }
  else{
    cout << "You did not pass all the tests, keep working on your project!" << endl;
    ret = 1;
  }


  return ret;
}
bool equalDates(const Date& A, const Date& B) {
	ostringstream Astr, Bstr;
	Astr << A;
	Bstr << B;
	return (Astr.str() == Bstr.str());
}

bool yes(){
  char ch;
  ch = cin.get();
  cin.ignore(1000, '\n');
  return ch == 'y' || ch == 'Y';
}
