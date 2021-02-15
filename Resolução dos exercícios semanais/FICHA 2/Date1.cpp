#include "Date1.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;


Date1::Date1()
{
    date = "";
    time_t mytime = time(0);
    struct tm data_atual;
    localtime_s(&data_atual, &mytime);
    date += to_string(data_atual.tm_year + 1900) + to_string(data_atual.tm_mon + 1) + to_string(data_atual.tm_mday);
}

Date1::Date1(unsigned int year, unsigned int month, unsigned int day)
{
    date = to_string(year) + to_string(month) + to_string(day);
}

Date1::Date1(string yearMonthDay)
{
    date = yearMonthDay.substr(0, 4) + yearMonthDay.substr(5, 2) + yearMonthDay.substr(8, 2);
}

void Date1::setYear(unsigned int year)
{
    string y = to_string(year);
    int x = y.length();
    if (x != 4)
        y = string(4 - x, '0') + y;
    date = to_string(year) + date.substr(4, 4);
}

void Date1::setMonth(unsigned int month)
{
    string y;
    if (month >= 10)
        y = to_string(month);
    else
        y = "0" + to_string(month);
    date = date.substr(0, 4) + y + date.substr(6, 2);
}

void Date1::setDay(unsigned int day)
{
    string y;
    if (day >= 10)
        y = to_string(day);
    else
        y = "0" + to_string(day);
    date = date.substr(0, 6) + y;
}

void Date1::setDate(unsigned int year, unsigned int month, unsigned int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

unsigned int Date1::getYear() const
{
    return stoi(date.substr(0, 4));
}

unsigned int Date1::getMonth() const
{
    return stoi(date.substr(4, 2));
}

unsigned int Date1::getDay() const
{
    return stoi(date.substr(6, 2));
}

string Date1::getDate() const
{
    return date.substr(0, 4) + "/" + date.substr(4, 2) + "/" + date.substr(6, 2);
}

void Date1::show() const
{
    cout << date.substr(0, 4) + "/" + date.substr(4, 2) + "/" + date.substr(6, 2);
}

bool Date1::Year() const
{
    //cin >> x;
    if ((stoi(date.substr(0, 4)) % 4 == 0) && (stoi(date.substr(0, 4)) % 100 != 0))
        return true;
    else if (stoi(date.substr(0, 4)) % 400 == 0)
        return true;
    else
        return false;
}

int Date1::DaysOfMonth() const
{
    bool ValidOperation = true;
    switch (stoi(date.substr(4, 2)))
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
    if (stoi(date.substr(4, 2)) == 2)
    {
        if (Year())
            return 29;
        else
            return 28;
    }
}

bool Date1::isValid() const
{
    if (stoi(date.substr(0, 4)) < 0)
        return false;
    else if (stoi(date.substr(4, 2)) > 12 || stoi(date.substr(4, 2)) < 1)
        return false;
    else if (stoi(date.substr(6, 2)) < 0 || stoi(date.substr(6, 2)) > DaysOfMonth())
        return false;
    else return true;
}

bool Date1::isEqualTo(const Date1& date) const
{
    if (stoi((this->date).substr(0, 4)) == date.getYear() && stoi((this->date).substr(4, 2)) == date.getMonth() && stoi((this->date).substr(6, 2)) == date.getDay())
        return true;
    else
        return false;
}

bool Date1::isNotEqualTo(const Date1& date) const
{
    return !isEqualTo(date);
}

bool Date1::isAfter(const Date1& date) const
{
    if (stoi((this->date).substr(0, 4)) != date.getYear())
    {
        if (stoi((this->date).substr(0, 4)) > date.getYear())
            return true;
        else
            return false;
    }
    else if (stoi((this->date).substr(4, 2)) != date.getMonth())
    {
        if (stoi((this->date).substr(4, 2)) > date.getMonth())
            return true;
        else
            return false;
    }
    else if (stoi((this->date).substr(6, 2)) != date.getDay())
    {
        if (stoi((this->date).substr(6, 2)) > date.getDay())
            return true;
        else
            return false;
    }
    else
        return 0;
}

bool Date1::isBefore(const Date1& date) const
{
    return !isAfter(date);
}