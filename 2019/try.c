#include <stdio.h>

struct ppp
{
    unsigned a : 8;
    unsigned b : 8;
};

int main() {
    struct ppp k;
    k.a = 5;    k.b = 6;
    printf("%d\n",k.a + k.b);
    return 0;
}