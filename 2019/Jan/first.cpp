#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x;
    int a[10005];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> x;
    for (int i = n; i >= x; i--)
        a[i + 1] = a[i];
    a[x] = a[n + 1];
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}