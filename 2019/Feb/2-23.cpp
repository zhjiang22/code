#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];
int c[200005];
char s1[100005], s2[1000005];
int l1, l2;
int l;

int main() {
    cin >> s1 >> s2;
    l1 = strlen(s1);    l2 = strlen(s2);
    l = l1 + l2;
    for (int i = 0; i < l1; i++)
        a[i] = s1[l1 - i - 1] - '0';
    for (int i = 0; i < l2; i++)
        b[i] = s2[l2 - i - 1] - '0';

    for (int i = 0; i < l1; i++)
        for (int j = 0; j < l2; j++) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    if (!c[l - 1])  l--;
    for (int i = l - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
    return 0;
}
