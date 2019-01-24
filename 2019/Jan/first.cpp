#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ans = min(j, n - j + 1);
            ans = min(ans, i);
            ans = min(ans, n - i + 1);
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}