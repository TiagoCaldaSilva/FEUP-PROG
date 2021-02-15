#include "Date.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;


Date::Date()
{
    time_t mytime = time(0);
    struct tm data_atual;
    localtime_s(&data_atual, &mytime);
    this->year = data_atual.tm_year + 1900; this->month = data_atual.tm_mon + 1; this->day = data_atual.tm_mday;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
    this->year = year; this->month = month; this->day = day;
}

Date::Date(string yearMonthDay)
{
    this->year = stoi(yearMonthDay.substr(0, 4));
    this->month = stoi(yearMonthDay.substr(5, 2));
    this->day = stoi(yearMonthDay.substr(8, 2));
}

void Date::setYear(unsigned int year)
{
    this->year = year;
}

void Date::setMonth(unsigned int month)
{
    this->month = month;
}

void Date::setDay(unsigned int day)
{
    this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day)
{
    this->year = year; this->month = month; this->day = day;
}

unsigned int Date::getYear() const
{
    return this->year;
}

unsigned int Date::getMonth() const
{
    return this->month;
}

unsigned int Date::getDay() const
{
    return this->day;
}

string Date::getDate() const
{
    string y = to_string(year), m = to_string(month), d = to_string(day);
    while (y.length() != 4)
    {
        y = '0' + y;
    }
    while (m.length() != 2)
    {
        m = '0' + m;
    }
    while (d.length() != 2)
    {
        d = '0' + d;
    }
    return y + "/" + m + "/" + d;
}

void Date::show() const
{
    cout << setfill('0');
    cout << setw(4) << year << "/" << setw(2) << month << "/" << setw(2) << day;// << endl;
}

bool Date::Year() const
{
    //cin >> x;
    if ((year % 4 == 0) && (year % 100 != 0))
        return true;
    else if (year % 400 == 0)
        return true;
    else
        return false;
}

int Date::DaysOfMonth() const
{
    bool ValidOperation = true;
    switch (month)
    {
    case (1):
        return 31;
    case (3):
        return 31;
    case (4):
        return 30;
    case (5):
        return 31;
    case (6):
        return 30;
    case (7):
        return 31;
    case (8):
        return 31;
    case (9):
        return 30;
    case (10):
        return 31;
    case (11):
        return 30;
    case (12):
        return 31;
    }
    if (month == 2)
    {
        if (Year())
            return 29;
        else
            return 28;
    }
    return 0;
}

bool Date::isValid() const
{
    if (year < 0)
        return false;
    else if (month > 12 || month < 1)
        return false;
    else if (day < 0 || day > (unsigned int)DaysOfMonth())
        return false;
    else return true;
}

bool Date::isEqualTo(const Date& date) const
{
    if (this->year == int(date.getYear()) && this->month == int(date.getMonth()) && this->day == int(date.getDay()))
        return true;
    else
        return false;
}

bool Date::isNotEqualTo(const Date& date) const
{
    return !isEqualTo(date);
}

bool Date::isAfter(const Date& date) const
{
    if (year != date.getYear())
    {
        if (year > date.getYear())
            return true;
        else
            return false;
    }
    else if (month != date.getMonth())
    {
        if (month > date.getMonth())
            return true;
        else
            return false;
    }
    else if (day != date.getDay())
    {
        if (day > date.getDay())
            return true;
        else
            return false;
    }
    else
        return 0;
}

bool Date::isBefore(const Date& date) const
{
    return !isAfter(date);
}

bool Date::operator==(const Date& right) const
{
    return isEqualTo(right);
}

bool Date::operator!=(const Date& right) const
{
    return isNotEqualTo(right);
}

bool Date::operator<=(const Date& right) const
{
    return (isEqualTo(right) || isBefore(right));
}

bool Date::operator>=(const Date& right) const
{
    return (isEqualTo(right) || isAfter(right));
}

bool Date::operator<(const Date& right) const
{
    return isBefore(right);
}

bool Date::operator>(const Date& right) const
{
    return isAfter(right);
}

ostream& operator<<(ostream& out, const Date& right)
{
    out << right.getDate();
    return out;
}

istream& operator>>(istream& in, Date& right)
{
    string date, _year, _month, _day;
    char barra;
    getline(in, date, '\n');
    stringstream x(date);
    x >> _year >> barra >> _month >> barra >> _day;
    right.setYear(stoi(_year));
    right.setMonth(stoi(_month));
    right.setDay(stoi(_day));
    return in;
}

/*
    Date x(2001, 2, 3);
    x.show();
    Date y(2002, 2, 3);
    cout << (x > y) << endl << (x < y) << endl << (x == y) << endl << (x != y) << endl;
    cout << x << endl;
    cout << y << endl;
  */

Date& Date::_setYear(unsigned int year)
{
    this->year = year;
    return *this;
}

Date& Date::_setMonth(unsigned int month)
{
    this->month = month;
    return *this;
}

Date& Date::_setDay(unsigned int day)
{
    this->day = day;
    return *this;
}

Date& Date::_setDate(unsigned int year, unsigned int month, unsigned int day)
{
    this->year = year; this->month = month; this->day = day;
    return *this;
}


/*
    The difference is that, if the function returns Date&, it is possible to use setDay(x).setYear(x).setMonth(x);
    If the funcion returns Date, it isn't possible, because only the copy is changed
*/

Date& Date::operator++()
{
    day++;
    if (day > DaysOfMonth())
    {
        day = 1;
        month++;
        if (month > 12)
        {
            year++;
            month = 1;
        }
    }
    return *this;
}

Date& Date::operator++(int unesed)
{
    day++;
    if (day > DaysOfMonth())
    {
        day = 1;
        month++;
        if (month > 12)
        {
            year++;
            month = 1;
        }
    }
    return *this;
}