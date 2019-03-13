#include <bits/stdc++.h>
using namespace std;

class Example {
public:
    Example();
    Example(int, int);
    Example(int ,int ,int);
    ~Example();
    void seta(int);
    void setb(int);
    int geta()const;
    int getb()const;
    int add(const Example &e);
    static int getnum();
    friend Example operator + (const Example &, const Example &);
    friend ostream & operator << (ostream &, const Example &);
    friend istream & operator >> (istream &, Example &);
private:
    int a, b;
    static int Exnum;
};

int Example::Exnum = 0;

int Example::add(const Example &e) {
    return this -> a + e.a;
}

int Example::getnum() {
    return Example::Exnum;
}

Example::Example() {
    Exnum++;
    this -> a = -1; this -> b = -1;
}

Example::Example(int a, int b) {
    Exnum++;
    this -> a = a;  this -> b = b;
}

Example::Example(int a, int b, int c) {
    Exnum++;
    this -> a = a + c;  this -> b = b + c;
}

Example::~Example() {Exnum--;}

void Example::seta(int a = -1) {this -> a = a;}
void Example::setb(int b = -1) {this -> b = b;}

int Example::geta()const {return this -> a;}
int Example::getb()const {return this -> b;}

Example operator + (const Example &x, const Example &y) {
    return Example(x.a + y.a, x.b + y.b);
}

ostream & operator<<(ostream & os, const Example& x) {
    os << x.a << " " << x.b << " " << x.a + x.b << endl;
    return os;
}

istream & operator>>(istream & os, Example& x) {
    os >> x.a >> x.b;
    return os;
}

void work() {
    Example p[100] = { {1,2} , {3,4}, {4,4,4}};
    Example y(4, 4, 4);
    cout << y << endl;
    cout << y.add(p[0]);
}

int main() {
    Example x, y;
    cin >> x >> y;
    Example c = x + y;
    cout << c << endl;
    return 0;
}
