#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict{
	Date::Date(){
		m_dateOnly = false;
		set();
	}

	Date::Date(int year, int mon, int day){
		m_dateOnly = true;
		set(year, mon, day, 0, 0);
	}

	Date::Date(int year, int mon, int day, int hour, int min){
		m_dateOnly = false;
		set(year, mon, day, hour, min);
	}

	void Date::set() {
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		m_day = lt.tm_mday;
		m_mon = lt.tm_mon + 1;
		m_year = lt.tm_year + 1900;
		if (dateOnly()) {
			m_hour = m_min = 0;
		}
		else {
			m_hour = lt.tm_hour;
			m_min = lt.tm_min;
		}
	}

	//overloaded operators starts here
	bool Date::operator==(const Date & D) const{
		return this->value() == D.value();
	}

	bool Date::operator!=(const Date & D) const{
		return this->value() != D.value();
	}

	bool Date::operator<(const Date & D) const{
		return this->value() < D.value();
	}

	bool Date::operator>(const Date & D) const{
		return this->value() > D.value();
	}

	bool Date::operator<=(const Date & D) const {
		return this->value() <= D.value();
	}

	bool Date::operator>=(const Date & D) const {
		return this->value() >= D.value();
	}
	//overloaded operators ends here

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  void Date::errCode(int errorCode){
	  m_readErrorCode = errorCode;
  }

  void Date::set(int year, int mon, int day, int hour, int min){
	  m_year = year;
	  m_mon = mon;
	  m_day = day;
	  m_hour = hour;
	  m_min = min;
	  errCode(NO_ERROR);
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }
  int Date::errCode() const{
	  return m_readErrorCode;
  }
  bool Date::bad() const{
	  return m_readErrorCode != 0;
  }
  bool Date::dateOnly() const{
	  return m_dateOnly;
  }
  void Date::dateOnly(bool value){
	  m_dateOnly = value;
	  if (value == true) {
		  m_hour = m_min = 0;
	  }
  }
  std::istream& Date::read(std::istream& is){
	  char slash;
	  errCode(NO_ERROR);
	  if (dateOnly() == true) {
		  is >> m_year >> slash >> m_mon >> slash >> m_day;
		  if (!is.fail() && slash == '/') {
			  if (!(m_year >= MIN_YEAR && m_year <= MAX_YEAR)) {
				  errCode(YEAR_ERROR);
			  }
			  else if(!(m_mon >= 1 && m_mon <= 12)){
				  errCode(MON_ERROR);
			  }
			  else if (!(m_day >= 1 && m_day <= mdays())) {
				  errCode(DAY_ERROR);
			  }
		  }
		  else {
			  errCode(CIN_FAILED);
		  }
	  }
	  else {
        char comma, colon;
		  is >> m_year >> slash >> m_mon >> slash >> m_day >> comma >> m_hour >> colon >> m_min;
		  if (!is.fail() && slash == '/' && comma == ',' && colon == ':') {
			  if (!(m_year >= MIN_YEAR && m_year <= MAX_YEAR)) {
				  errCode(YEAR_ERROR);
			  }
			  else if (!(m_mon >= 1 && m_mon <= 12)) {
				  errCode(MON_ERROR);
			  }
			  else if (!(m_day >= 1 && m_day <= mdays())) {
				  errCode(DAY_ERROR);
			  }
			  else if (!(m_hour >= 0 && m_hour <= 23)) {
				  errCode(HOUR_ERROR);
			  }
			  else if (!(m_min >= 0 && m_min <= 59)) {
				  errCode(MIN_ERROR);
			  }
		  }
		  else {
			  errCode(CIN_FAILED);
		  }
	  }

	  return is;
  }
  std::ostream & Date::write(std::ostream & ostr) const{
	  char slash = '/';
	  if (dateOnly() == true) {
		  ostr << m_year << slash << setfill('0') << setw(2)<< m_mon << slash << setfill('0') << setw(2) << m_day;
	  }
	  else {
		  char comma = ',', colon = ':';
		  ostr << m_year << slash << setfill('0') << setw(2) << m_mon << slash << setfill('0') << setw(2) << m_day << comma << ' ' << setfill('0') << setw(2) << m_hour << colon << setfill('0') << setw(2) << m_min;
	  }
	  
	  return ostr;
  }
  std::istream & operator>>(std::istream & in, Date& d){
	  return d.read(in);
  }
  std::ostream & operator<<(std::ostream & out,const Date & d){
	  return d.write(out);
  }
}
