#include <bits/stdc++.h>

typedef struct {
  int year, month, day;
} Date;

Date* CreateDate(int year, int month, int day);
void DestroyDate(Date** p);
Date* CopyDate(const Date* date);

int GetYear(const Date* date);
int GetMonth(const Date* date);
int GetDay(const Date* date);
void SetYear(Date* date, int year);
void SetMonth(Date* date, int month);
void SetDay(Date* date, int day);
void SetDate(Date* date, int year, int month, int day);

char* GetDateString(const Date* date);
void DestroyDateString(char** p);

void IncreaseDate(Date* date);
void DecreaseDate(Date* date);

int month_days[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date *CreateDate(int year, int month, int day) {
    Date *p = (Date *) malloc (sizeof(Date));
    p -> year = year;   p -> month = month;  p -> day = day;
    return p;
}

void DestroyDate(Date **date) {
    free(*date);
    *date = NULL;
}

Date *CopyDate(const Date *date) {
    Date *p = (Date *) malloc (sizeof(Date));
    p -> year = date -> year;   p -> month = date -> month;  p -> day = date -> day;
    return p;
}

int GetYear(const Date *date) {
    return date -> year;
}

int GetMonth(const Date *date) {
    return date -> month;
}

int GetDay(const Date *date) {
    return date -> day;
}

void SetYear(Date *date, int year) {
    date -> year = year;
}

void SetMonth(Date *date, int month) {
    date -> month = month;
}

void SetDay(Date *date, int day) {
    date -> day = day;
}

void SetDate(Date *date, int year, int month, int day) {
    date -> year = year;    date -> month = month;  date -> day = day;
}

char* GetDateString(const Date *date) {
    char *pc = (char *)malloc(sizeof(char) * 23);
    sprintf(pc, "%04d-%02d-%02d", date -> year, date -> month, date -> day);
    return pc;
}

void DestroyDateString(char **p) {
    free(*p);
    *p = NULL;
}

void IncreaseDate(Date *date) {
    date -> day++;
    if ( (date -> year % 100 && date -> year % 4 == 0) || (date -> year % 400 == 0) )
        month_days[2] = 29;
    else
        month_days[2] = 28;
    if (date -> day > month_days[date -> month]) {
        date -> month++;
        if (date -> month > 12) {
            date -> month = 1;
            date -> year++;
        }
        date -> day = 1;
    }
}

void DecreaseDate(Date *date) {
    date -> day--;
    if ( (date -> year % 100 && date -> year % 4 == 0) || (date -> year % 400 == 0) )
        month_days[2] = 29;
    else
        month_days[2] = 28;
    if (date -> day < 1) {
        date -> month--;
        if (date -> month < 1) {
            date -> year--;
            date -> month = 12;
        }
        date -> day = month_days[date -> month];
    }
}

void TestDate(Date* date, int after, int before) {
  printf("Year: %d\n", GetYear(date));
  printf("Month: %d\n", GetMonth(date));
  printf("Day: %d\n", GetDay(date));

  char* date_string = GetDateString(date);
  printf("Formatted: %s\n", date_string);

  DestroyDateString(&date_string);
  assert(date_string == NULL);
  DestroyDateString(&date_string);

  IncreaseDate(date);
  date_string = GetDateString(date);
  printf("1 day later: %s\n", date_string);
  DestroyDateString(&date_string);

  int i;
  for (i = 0; i < after; ++i) {
    IncreaseDate(date);
  }
  date_string = GetDateString(date);
  printf("Another %d day(s) later: %s\n", after, date_string);
  DestroyDateString(&date_string);

  for (i = 0; i < before; ++i) {
    DecreaseDate(date);
  }
  date_string = GetDateString(date);
  printf("Another %d day(s) earlier: %s\n", before, date_string);
  DestroyDateString(&date_string);  
}

int main() {
  int year, month, day;
  int after, before;
  scanf("%d%d%d%d%d", &year, &month, &day, &after, &before);

  Date* date1 = CreateDate(year, month, day);
  assert(sizeof(*date1) == sizeof(Date));

  Date* date2 = CopyDate(date1);
  assert(date1 != date2);
  assert(date1->month == date2->month);

  SetDate(date1, year + 1, month, day);
  SetYear(date1, year);
  SetMonth(date1, month);
  SetDay(date1, day);

  TestDate(date1, after, before);

  DestroyDate(&date1);
  DestroyDate(&date2);

  assert(date1 == NULL);
  DestroyDate(&date2);

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
