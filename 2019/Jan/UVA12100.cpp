#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
struct job {
    int idx;
    int rank;
} a[MAXN];
int cnt[15];
int n, m;
int t;

void init() {
    cin >> n >> m;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
        cin >> a[i].rank, cnt[a[i].rank]++, a[i].idx = i;
    m++;
}

void work() {
    queue<job> q;
    for (int i = 1; i <= n; i++)
        q.push(a[i]);
    int t = 0;
    while (!q.empty()) {
        job u = q.front();
        q.pop();
        bool ok = 1;
        for (int i = u.rank + 1; i <= 9; i++)
            if (cnt[i])
                ok = 0;
        if(ok) {
            t++;
            if (u.idx == m) {
                while(!q.empty())
                    q.pop();
                printf("%d\n",t);
            }
            else    cnt[u.rank]--;
        }
        else {
            q.push(u);
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        init();
        work();
    }
    return 0;
}