// Final Project Milestone 1
// Student error handling tester program
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
#include "Date.h"
#include "POS.h"
using namespace std;
using namespace ict;
int main(){
  int ret = 0;
  bool ok = true;

  if (ok){
    Date A;
    A.dateOnly(true);
    cout << "Testing error handling in read funciton;" << endl;
    cout << "cin faliure detection, " << endl;
    cout << "Please enter the following string \"abcd\": ";
    cin >> A;
    if (A.errCode() == CIN_FAILED){
      cout << "passed!" << endl;
    }
    else {
      cout << "Your read function does not check cin.fail() after entry," << endl
        << "or it did not set _readErrorCode to CIN_FAILED" << endl;
      ok = false;
    }
    cin.clear();
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    A.dateOnly(true);
    cout << "Year validation, " << endl;
    cout << "Please enter the following string \"10/1/1\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == YEAR_ERROR){
      cout << "passed!" << endl;
    }
    else {
      cout << "Your read function does not check the year entry limits after entry," << endl
        << "or it did not set _readErrorCode to YEAR_ERROR" << endl;
      ok = false;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    A.dateOnly(true);
    cout << "Month validation, " << endl;
    cout << "Please enter the following string \"2000/13/1\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == MON_ERROR){
      cout << "Passed" << endl;
    }
    else {
      cout << "Your read function does not check the month entry limits after entry," << endl
        << "or it did not set _readErrorCode to MON_ERROR" << endl;
      ok = false;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    A.dateOnly(true);
    cout << "Day validation, " << endl;
    cout << "Please enter the following string \"2000/1/50\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == DAY_ERROR){
      cout << "Passed!" << endl;
    }
    else {
      cout << "Your read function does not check the day entry limits after entry," << endl
        << "or it did not set _readErrorCode to DAY_ERROR" << endl;
      ok = false;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    A.dateOnly(true);
    cout << "Day validation, leap year:" << endl;
    cout << "Please enter the following string \"2016/2/29\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == DAY_ERROR){
      cout << "Your read function does not check the day entry limits using mday()" << endl;
      ok = false;
    }
    else {
      cout << "passed!" << endl;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    A.dateOnly(false);
    cout << "Hour validation, " << endl;
    cout << "Please enter the following string \"2000/1/1, 25:10\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == HOUR_ERROR){
      cout << "Passed!" << endl;
    }
    else {
      cout << "Your read function does not check the hour entry limit after entry," << endl
        << "or it did not set _readErrorCode to HOUR_ERROR" << endl;
      ok = false;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    A.dateOnly(false);
    cout << "Minute validation, " << endl;
    cout << "Please enter the following string \"2000/1/1, 23:60\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == MIN_ERROR){
      cout << "Passed!" << endl;
    }
    else {
      cout << "Your read function does not check the minute entry limit after entry," << endl
        << "or it did not set _readErrorCode to MIN_ERROR" << endl;
      ok = false;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    cout << "You passed all error handling tests." << endl<< endl
      << " If you have started with test no 1 and came down to here, " << endl
      << " you can now work on Error class." << endl;
  }
  else{
    cout << "You did not pass all the tests, keep working on your project!" << endl;
    ret = 1;
  }
  return ret;
}
