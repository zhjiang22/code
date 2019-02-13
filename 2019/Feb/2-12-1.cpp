#include <bits/stdc++.h>
using namespace std;

int a[1006];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans = min(ans, abs(a[i] - a[j]));
    cout << ans << endl;
    return 0;
}