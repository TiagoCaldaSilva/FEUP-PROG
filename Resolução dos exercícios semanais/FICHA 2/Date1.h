#pragma once
#include "Date1.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;
class Date1
{
public:
    Date1();
    Date1(unsigned int year, unsigned int month, unsigned int day);
    Date1(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
    void setYear(unsigned int year);
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
    void setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    string getDate() const; // returns the date in format "yyyy/mm/dd"
    void show() const; // shows the date on the screen in format "yyyy/mm/dd"

    bool isValid() const;
    bool isEqualTo(const Date1& date) const;
    bool isNotEqualTo(const Date1& date) const;
    bool isAfter(const Date1& date) const;
    bool isBefore(const Date1& date) const;
private:
    bool Year() const; //retorna se o ano é ou não é bissexto
    int DaysOfMonth() const; //retorna os dias do mês
    string date;
};

