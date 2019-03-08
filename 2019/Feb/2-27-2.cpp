#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#ifndef DATE_HPP_
#define DATE_HPP_
#include <string>
#include <cstdio>

class Date {

 public:
  void setDate(int year, int month, int day);
  int year() const;
  int month() const;
  int day() const;

  std::string toString() const {
    const int length_of_date_string = 10;

    char date_string[length_of_date_string + 1];
    snprintf(date_string,
            length_of_date_string + 1,
            "%04d-%02d-%02d",
            year_, month_, day_);

    return std::string(date_string);
  }

  void increment();
  void decrement();

 private:
  int year_;
  int month_;
  int day_;

  int daysOfMonth(int year, int month) const;
};

#endif

bool is_run(int x) {
    return ((x % 100 && (x % 4 == 0)) || ((x % 100 == 0) && (x % 400 == 0)));
}

int Date::year()const {return year_;}
int Date::month()const {return month_;}
int Date::day()const {return day_;}

int Date::daysOfMonth(int year, int month) const {
    if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
        return 31;
    if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
        return 30;
    if (is_run(year))
        return 29;
    else
        return 28;
}

int DaysOfMonth(int year_, int month_) {
    if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
        return 31;
    if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
        return 30;
    if (is_run(year_))
        return 29;
    else
        return 28;
}

void update(int& month_, int& day_, int& year_ ) {
    int x = DaysOfMonth(year_, month_);
    if (day_ > x) {
        day_ -= x;
        month_++;
    }
    if (day_ < 1) {
        month_ -= 1;
        if (month_ < 1)
            month_ += 12;
        day_ = DaysOfMonth(year_, month_);
    }
    if (month_ > 12) {
        month_ -= 12;
        year_++;
    }
}

void Date::increment() {
    day_++;
    update(month_, day_ , year_);
}

void Date::decrement() {
    day_--;
    update(month_, day_, year_);
}

void Date::setDate(int year, int month, int day) {
    year_ = year;  month_ = month;  day_ = day;
}

void TestDate(Date& date, int after, int before) {
  cout << "Year: " << date.year() << endl
       << "Month: " << date.month() << endl
       << "Day: " << date.day() << endl;
  cout << "Formatted: " << date.toString() << endl;

  date.increment();
  cout << "1 day later: " << date.toString() << endl;
  for (int i = 0; i < after; ++i) {
    date.increment();
  }
  cout << "Another " << after << " day(s) later: " << date.toString() << endl;
  for (int i = 0; i < before; ++i) {
    date.decrement();
  }
  cout << "Another " << before << " day(s) earlier: " << date.toString() << endl;
}

int main() {
  int year, month, day;
  int after, before;
  cin >> year >> month >> day;
  cin >> after >> before;

  Date date;
  date.setDate(year, month, day);
  TestDate(date, after, before);

  return 0;
}

/*
One probable test case:

1900 2 28 365 366
Year: 1900
Month: 2
Day: 28
Formatted: 1900-02-28
1 day later: 1900-03-01
Another 365 day(s) later: 1901-03-01
Another 366 day(s) earlier: 1900-02-28

*/