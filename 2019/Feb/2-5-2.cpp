#include <bits/stdc++.h>
using namespace std;

int a[10005];
int n;

int main() {
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[x]++;
    }
    int ans = 0, maxd = -1;
    for (int i = 1; i <= 10001; i++)
        if (a[i] > maxd)
            maxd = a[i], ans = i;
    cout << ans << endl;
    return 0;
}
