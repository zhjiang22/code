#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
struct Node
{
    int x, idx;
    bool operator<(const Node &no) const
    {
        return x < no.x;
    }
} a[MAXN];
int n, L, t;
int p[MAXN];

void init()
{
    cin >> n >> L >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1);
    for(int i=1;i<=n;i++)
        p[a[i].idx]=i;
}

void work()
{
    t %= 2 * L;
    for (int i = 1; i <= n; i++)
    {
        if (t <= L - a[i].x)
            a[i].x += t;
        else if (t <= 2 * L - a[i].x)
            a[i].x = 2 * L - t - a[i].x;
        else
            a[i].x = t - (2 * L - a[i].x);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        cout << a[p[i]].x << " ";
    cout << endl;
}

int main()
{
    init();
    work();
    return 0;
}