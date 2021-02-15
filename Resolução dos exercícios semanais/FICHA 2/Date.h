#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

class Date;

ostream& operator<<(ostream& out, const Date& right);
istream& operator>>(istream& in, const Date& right);

class Date
{
public:
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
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
    bool isEqualTo(const Date& date) const;
    bool isNotEqualTo(const Date& date) const;
    bool isAfter(const Date& date) const;
    bool isBefore(const Date& date) const;

    bool operator==(const Date& right) const;
    bool operator!=(const Date& right) const;
    bool operator<=(const Date& right) const;
    bool operator>=(const Date& right) const;
    bool operator>(const Date& right) const;
    bool operator<(const Date& right) const;
    Date& operator++();
    Date& operator++(int unused);


    Date& _setYear(unsigned int year);
    Date& _setMonth(unsigned int month);
    Date& _setDay(unsigned int day);
    Date& _setDate(unsigned int year, unsigned int month, unsigned int day);
private:
    bool Year() const; //retorna se o ano é ou não é bissexto
    int DaysOfMonth() const; //retorna os dias do mês
    unsigned int year;
    unsigned int month;
    unsigned int day;
};