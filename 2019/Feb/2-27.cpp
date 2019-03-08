#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
long long a[MAXN];
long long n;

int Found(int x) {
    int l = 1, r = MAXN - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return a[l] == x? l : -1;
}

int main() {
    for (int i = 1; i < MAXN; i++)
        a[i] = (long long)i * i;
    cin >> n;
    int x = sqrt(n);
    for (int i = 1; i <= x; i++) {
        long long keys = n - i * i;
        if (Found(keys) != -1) {
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
    return 0;
}