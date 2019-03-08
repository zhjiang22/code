#include <bits/stdc++.h>
using namespace std;

char b[1005];

int main() {
    int a;
    int x = 16;
    cin >> a;
    int cur = 0;
    while (a > 0) {
        b[cur] = a % x + '0';
        if (b[cur] > '9')
            b[cur] = (a % x - 10) + 'A';
        cur++;
        a /= x;
    }
    for (int i = cur - 1; i >= 0; i--)
        cout << b[i];
    cout << endl;
    return 0;
}