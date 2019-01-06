#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    while(scanf("%s %s",a,b) == 2) {
        int l = strlen(a);
        int maxd = 0;
        int maxp = 0;
        for (int i = 0; i < l; i++)
            if(a[i] > maxd) {
                maxd = a[i];
                maxp = i;
            }
        for (int i = 0; i <= maxp; i++)
            putchar(a[i]);
        int l2 = strlen(b);
        for (int i = 0; i < l2; i++)
            putchar(b[i]);
        for (int i = maxp + 1; i < l; i++)
            putchar(a[i]);
        printf("\n");
    }
}