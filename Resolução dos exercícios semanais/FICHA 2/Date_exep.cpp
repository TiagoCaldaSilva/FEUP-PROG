#include "Date_exep.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include "InvalidDate.h"

using namespace std;


Date_exep::Date_exep()
{
    time_t mytime = time(0);
    struct tm data_atual;
    localtime_s(&data_atual, &mytime);
    this->year = data_atual.tm_year + 1900; this->month = data_atual.tm_mon + 1; this->day = data_atual.tm_mday;
}

Date_exep::Date_exep(int year, int month, int day)
{  
    if ((year < 0) || (month < 0 || month > 12))
    {
        throw InvalidDate("Invalid date input.");
    }
    this->year = year; this->month = month;
    if(day < 0 || day > DaysOfMonth())
    {
        throw InvalidDate("Invalid date input.");
    }
    this->day = day;
}

Date_exep::Date_exep(string yearMonthDay)
{
    int _year, _month, _day;
    _year = stoi(yearMonthDay.substr(0, 4));
    _month = stoi(yearMonthDay.substr(5, 2));
    _day = stoi(yearMonthDay.substr(8, 2));
    if ((_year < 0) ||(_month < 0 || _month > 12))
    {
        throw InvalidDate("Invalid date input.");
    }
    year = _year;
    month = _month;
    if(_day < 0 || day > DaysOfMonth())
    {
        throw InvalidDate("Invalid date input.");
    }
    day = _day;
}

void Date_exep::setYear(int year)
{
    if (year < 0)
        throw InvalidDate("Invalid year input.");
    this->year = year;
}

void Date_exep::setMonth(int month)
{
    if (month < 0 || month > 12)
    {
        throw InvalidDate("Invalid month input. ");
    }
    this->month = month;
}

void Date_exep::setDay(int day)
{
    if (day < 0 || day > DaysOfMonth())
    {
        throw InvalidDate("Invalid day input.");
    }
    this->day = day;
}

void Date_exep::setDate_exep(int year, int month, int day)
{
    if ((year < 0) || (month < 0 || month > 12))
    {
        throw InvalidDate("Invalid date input.");
    }
    this->year = year; this->month = month;
    if (day < 0 || day > DaysOfMonth())
    {
        throw InvalidDate("Invalid date input.");
    }
    this->day = day;
}

int Date_exep::getYear() const
{
    return this->year;
}

int Date_exep::getMonth() const
{
    return this->month;
}

int Date_exep::getDay() const
{
    return this->day;
}

string Date_exep::getDate_exep() const
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

void Date_exep::show() const
{
    cout << setfill('0');
    cout << setw(4) << year << "/" << setw(2) << month << "/" << setw(2) << day;// << endl;
}

bool Date_exep::Year() const
{
    //cin >> x;
    if ((year % 4 == 0) && (year % 100 != 0))
        return true;
    else if (year % 400 == 0)
        return true;
    else
        return false;
}

int Date_exep::DaysOfMonth() const
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

bool Date_exep::isValid() const
{
    if (year < 0)
        return false;
    else if (month > 12 || month < 1)
        return false;
    else if (day < 0 || day >(int)DaysOfMonth())
        return false;
    else return true;
}

bool Date_exep::isEqualTo(const Date_exep& Date_exep) const
{
    if (this->year == int(Date_exep.getYear()) && this->month == int(Date_exep.getMonth()) && this->day == int(Date_exep.getDay()))
        return true;
    else
        return false;
}

bool Date_exep::isNotEqualTo(const Date_exep& Date_exep) const
{
    return !isEqualTo(Date_exep);
}

bool Date_exep::isAfter(const Date_exep& Date_exep) const
{
    if (year != Date_exep.getYear())
    {
        if (year > Date_exep.getYear())
            return true;
        else
            return false;
    }
    else if (month != Date_exep.getMonth())
    {
        if (month > Date_exep.getMonth())
            return true;
        else
            return false;
    }
    else if (day != Date_exep.getDay())
    {
        if (day > Date_exep.getDay())
            return true;
        else
            return false;
    }
    else
        return 0;
}

bool Date_exep::isBefore(const Date_exep& Date_exep) const
{
    return !isAfter(Date_exep);
}

bool Date_exep::operator==(const Date_exep& right) const
{
    return isEqualTo(right);
}

bool Date_exep::operator!=(const Date_exep& right) const
{
    return isNotEqualTo(right);
}

bool Date_exep::operator<=(const Date_exep& right) const
{
    return (isEqualTo(right) || isBefore(right));
}

bool Date_exep::operator>=(const Date_exep& right) const
{
    return (isEqualTo(right) || isAfter(right));
}

bool Date_exep::operator<(const Date_exep& right) const
{
    return isBefore(right);
}

bool Date_exep::operator>(const Date_exep& right) const
{
    return isAfter(right);
}

ostream& operator<<(ostream& out, const Date_exep& right)
{
    out << right.getDate_exep();
    return out;
}

istream& operator>>(istream& in, Date_exep& right)
{
    string Date_exep, _year, _month, _day;
    char barra;
    getline(in, Date_exep, '\n');
    stringstream x(Date_exep);
    x >> _year >> barra >> _month >> barra >> _day;
    right.setYear(stoi(_year));
    right.setMonth(stoi(_month));
    right.setDay(stoi(_day));
    return in;
}

/*
    Date_exep x(2001, 2, 3);
    x.show();
    Date_exep y(2002, 2, 3);
    cout << (x > y) << endl << (x < y) << endl << (x == y) << endl << (x != y) << endl;
    cout << x << endl;
    cout << y << endl;
  */

Date_exep& Date_exep::_setYear(int year)
{
    if(year < 0)
        throw InvalidDate("Invalid year input.");
    this->year = year;
    return *this;
}

Date_exep& Date_exep::_setMonth(int month)
{
    if (month < 0 || month > 12)
    {
        throw InvalidDate("Invalid month input. ");
    }
    this->month = month;
    return *this;
}

Date_exep& Date_exep::_setDay(int day)
{
    if (day < 0 || day > DaysOfMonth())
    {
        throw InvalidDate("Invalid day input.");
    }
    this->day = day;
    return *this;
}

Date_exep& Date_exep::_setDate_exep(int year, int month, int day)
{
    if ((year < 0) || (month < 0 || month > 12))
    {
        throw InvalidDate("Invalid date input.");
    }
    this->year = year; this->month = month;
    if (day < 0 || day > DaysOfMonth())
    {
        throw InvalidDate("Invalid date input.");
    }
    this->day = day;
    return *this;
}


/*
    The difference is that, if the function returns Date_exep&, it is possible to use setDay(x).setYear(x).setMonth(x);
    If the funcion returns Date_exep, it isn't possible, because only the copy is changed
*/

Date_exep& Date_exep::operator++()
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

Date_exep& Date_exep::operator++(int unesed)
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