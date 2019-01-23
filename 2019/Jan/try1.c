#include <stdio.h>
#include <string.h>

void (*(f)())(int, float);
typedef void (*(*x)())(int, float);
void foo(int i, float f);

int main() {
    x p = f;
    p();
}

void (*(f)())(int, float) {
    return foo;
}

void foo(int i,float f) {
    printf("%d %f\n", i, f);
}
