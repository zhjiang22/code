#include <bits/stdc++.h>
using namespace std;

class Box {
public:
    int a, b;
    double c;
    Box add(const Box& t) const {
        Box d;
        d.a = a + t.a;  d.b = b + t.b;  d.c = c + t.c;
        return d;
    }
    Box operator+(const Box& t) const {
        Box d;
        d.a = a + t.a;  d.b = b + t.b;  d.c = c + t.c;
        return d;
    }
private:
    int d;
};

namespace env {
    int add(int a, int b) {
        return a + b;
    }
};

template <class T>
inline T Max(T const &a, T const& b) {
    return a < b? b : a;
}

using namespace env;

int main() {
    int a, b;
    a = 6, b = 1;
    std::cout << env::add(a, b) << std::endl;
    std::cout << Max(a, b) << std::endl;
    return 0;
}
