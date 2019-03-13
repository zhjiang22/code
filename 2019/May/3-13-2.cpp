#include <iostream>
#include <cstring>
#define MAX 51
using namespace std;
#ifndef VECTOR_H
#define VECTOR_H
#include <string>
using namespace std;
 class Vector {
    public:
        Vector() {
            name = "";
            dimension = 0;
            param = NULL;
        }
        Vector(string, int, int[]);
        Vector(const Vector &otherVec);
        ~Vector();
        void isEqual(const Vector &);
        void setName(string);
        void print();
    private:
        string name;
        int dimension, *param;
};
 #endif

Vector::Vector(string s, int dim, int *par) {
    this -> name = s;
    this -> dimension = dim;
    this -> param = par;
    printf("construct a vector called ");
    cout << this -> name << '.' << endl;
}

Vector::Vector(const Vector & t) {
    *this = t;
    printf("copy a vector called ");
    cout << this -> name << '.' << endl;
}

Vector::~Vector() {
    printf("release memory from a vector called ");
    cout << this -> name << '.' << endl;
}

void Vector::isEqual(const Vector & t) {
    int k1 = this -> name == t.name;
    int k2 = 1;
    if (this -> dimension == t.dimension) {
        for (int i = 0; i < this -> dimension; i++)
            if (*(param + i) != *(t.param + i)) {
                k2 = 0;
                break;
            }
    }
    else    k2 = 0;
    if (k1 == 1 && k2 == 1)   printf("same name, same value.\n");
    else if (k1 == 1 && k2 == 0)  printf("same name, different value.\n");
    else if (k1 == 0 && k2 == 1)  printf("different name, same value.\n");
   	else printf("different name, different value.\n");
}

void Vector::setName(string s) {
    this -> name = s;
}

void Vector::print() {
    cout << this -> name;
    cout << '(';
    for (int i = 1; i <= this -> dimension; i++) {
        cout << *(param + i - 1);
        if (i != this -> dimension) cout << ", ";
    }
    cout << ')';
    cout << endl;
}

 int main() {
    string name = "";
    int dim, num[MAX];
    cin >> name >> dim;
    for (int i = 0; i < dim; i++) {
        cin >> num[i];
    }
    Vector vec1(name, dim, num);
    vec1.print();
    Vector vec2(vec1);
    vec2.print();
    vec1.isEqual(vec2);
    int vec3_num[] = {1, 2, 3};
    Vector vec3(name, 3, vec3_num);
    vec1.isEqual(vec3);
    vec2.setName("helloWorld!");
    vec1.isEqual(vec2);
    return 0;
}