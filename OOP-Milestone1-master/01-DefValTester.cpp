// Final Project Milestone 1
// Student defined values tester
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
    cout << "Checking defined values, POS.h: " << endl;
  }
  if (ok && MIN_YEAR != 2000){
    cout << "MIN_YEAR must be 2000" << endl;
    ok = false;
  }
  if (ok && MAX_YEAR != 2030){
    cout << "MAX_YEAR must be 2030" << endl;
    ok = false;
  }
  if (ok && (TAX - 0.13 > 0.0001 || TAX - 0.13 < -0.0001)){
    cout << "TAX must be 0.13" << endl;
    ok = false;
  }
  if (ok && MAX_SKU_LEN != 7){
    cout << "MAX_SKU_LEN must be 7" << endl;
    ok = false;
  }
  if (ok && MAX_NO_ITEMS != 2000){
    cout << "MAX_NO_ITESM must be 2000" << endl;
    ok = false;
  }
  if (ok) {
    cout << "Passed!" << endl;
    cout << "Checking define values for error code in Data.h" << endl;
  }
  if (ok && NO_ERROR != 0){
    cout << "NO_ERROR must be 0" << endl;
    ok = false;
  }
  if (ok && CIN_FAILED != 1){
    cout << "CIN_FAILED must be 1" << endl;
    ok = false;
  }
  if (ok && YEAR_ERROR != 2){
    cout << "YEAR_ERROR must be 2" << endl;
    ok = false;
  }
  if (ok && MON_ERROR != 3){
    cout << "MON_ERROR must be 3" << endl;
    ok = false;
  }
  if (ok && DAY_ERROR != 4){
    cout << "DAY_ERROR must be 4" << endl;
    ok = false;
  }
  if (ok && HOUR_ERROR != 5){
    cout << "HOUR_ERROR must be 4" << endl;
    ok = false;
  }
  if (ok && MIN_ERROR != 6){
    cout << "MIN_ERROR must be 6" << endl;
    ok = false;
  }
  if (ok){
    cout << "Passed!" << endl;
  }
  if (ok){
    cout << "Checking defined values passed, now run test no 2!" << endl;
  }
  else{
    cout << "You did not pass all the tests, keep working on your project!" << endl;
    ret = 1;
  }
  return ret;
}
