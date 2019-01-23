#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n, m;

int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    while (l <= r)
    {
        while (a[l] + a[r] > m && l < r)
        {
            r--;
            ans++;
        }
        l++;
        r--;
        ans++;
    }
    cout << ans << endl;
    return 0;
}