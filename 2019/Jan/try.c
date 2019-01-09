#include <stdio.h>

struct name {
    unsigned p : 30;
    unsigned a : 3;
    unsigned b : 30;
};

int main() {
    printf("%d\n",(int)sizeof(struct name));
}
