
#ifndef FINALPROJECT_DATE_H
#define FINALPROJECT_DATE_H
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Date{
public:
    Date(int new_year, int new_month, int new_day);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& stream, const Date& date);
#endif //FINALPROJECT_DATE_H
