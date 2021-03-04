
#ifndef FINALPROJECT_DATABASE_H
#define FINALPROJECT_DATABASE_H
#include "Date.h"

class Database {
public:
    void AddEvent(const Date& date, const string& event);

    bool DeleteEvent(const Date& date, const string& event);

    int DeleteDate(const Date& date);

    set<string> Find(const Date& date) const;

    void Print() const;

private:
    map<Date, set<string>> storage;
};


#endif //FINALPROJECT_DATABASE_H
