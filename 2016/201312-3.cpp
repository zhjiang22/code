#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int a[MAXN];
int n;

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void work()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int mind = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            mind = min(mind, a[j]);
            ans = max(ans, mind * (j - i + 1));
        }
    }
    printf("%d", ans);
}

int main()
{
    init();
    work();
    return 0;
}