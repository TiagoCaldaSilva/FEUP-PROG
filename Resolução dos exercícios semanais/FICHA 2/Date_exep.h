#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

class Date_exep;

ostream& operator<<(ostream& out, const Date_exep& right);
istream& operator>>(istream& in, const Date_exep &right);

class Date_exep
{
public:
    Date_exep();
    Date_exep(int year, int month, int day);
    Date_exep(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setDate_exep(int year, int month, int day);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    string getDate_exep() const; // returns the Date_exep in format "yyyy/mm/dd"
    void show() const; // shows the Date_exep on the screen in format "yyyy/mm/dd"

    bool isValid() const;
    bool isEqualTo(const Date_exep& Date_exep) const;
    bool isNotEqualTo(const Date_exep& Date_exep) const;
    bool isAfter(const Date_exep& Date_exep) const;
    bool isBefore(const Date_exep& Date_exep) const;

    bool operator==(const Date_exep& right) const;
    bool operator!=(const Date_exep& right) const;
    bool operator<=(const Date_exep& right) const;
    bool operator>=(const Date_exep& right) const;
    bool operator>(const Date_exep& right) const;
    bool operator<(const Date_exep& right) const;
    Date_exep& operator++();
    Date_exep& operator++(int unused);


    Date_exep& _setYear(int year);
    Date_exep& _setMonth(int month);
    Date_exep& _setDay(int day);
    Date_exep& _setDate_exep(int year, int month, int day);
private:
    bool Year() const; //retorna se o ano é ou não é bissexto
    int DaysOfMonth() const; //retorna os dias do mês
    int year;
    int month;
    int day;
};

