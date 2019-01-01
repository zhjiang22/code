#include <stdio.h>

int main()
{
    int a, b;
    freopen("out.txt", "w", stdout);
    stderr = stdin;
    fscanf(stderr, "%d", &a);
    fprintf(stdout, "%d\n", a);
    return 0;
}