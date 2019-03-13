#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class Student
{
public:
  	int id;
  	char name[50]; // Data field
  	int age; // Data field
  	Student();
	Student(int);
  	Student(int, char*, int);
  	//void set(int, char*, int);
  	//void print();
};

void set(Student &, int, char*, int);
void print(Student);

void set(Student & stu, int idx, char *namex, int agex) {
	stu.id = idx;
	strcpy(stu.name, namex);
	stu.age = agex;
}

void print(Student stu) {
	printf("%s (%d) is %d years old.\n", stu.name, stu.id, stu.age);
}

Student::Student() {
	this -> id = this -> age = 0;
	strcpy(this -> name, "No Name");
}

Student::Student(int idx, char *namex, int agex) {
	this -> id = idx;	this -> age = agex;
	strcpy(this -> name, namex);
}

Student::Student(int idx) {
	this -> id = idx;	this -> age = 0;
	strcpy(this -> name, "No Name");
}

int main()
{
  	Student std1, std2(123, "Larry Jordan", 18), std3(124);
  	set(std1, 100, "Steven Gates", 61);
  	print(std1);
  	print(std2);
  	print(std3);
  	return 0;
}
