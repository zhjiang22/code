#include <stdio.h>
#include <string.h>

typedef struct tp {
    int a, b;
    double x;
} tp;
tp a[160 * 160];
int len;
int n;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

void swap(tp *a, tp *b){
    tp c;
    c = *a;
    *a = *b;
    *b = c;
}

int main() {
    scanf("%d", &n);
    printf("0/1\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if(gcd(i,j) == 1 && i != 1)
                a[++len] = (tp){j, i, (double)j / i};
    for (int i = 1; i <= len; i++)
        for (int j = i+1; j <= len; j++)
            if(a[i].x > a[j].x)
                swap(&a[i], &a[j]);
    for (int i = 1; i <= len; i++)
        if(a[i].x != a[i-1].x)
            printf("%d/%d\n", a[i].a, a[i].b);
    return 0;
}