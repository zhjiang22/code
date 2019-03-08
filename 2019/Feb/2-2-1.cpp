#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN];
int f[MAXN][2];
int n;

void init() {
    memset(f, 0, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[1][1] = a[1];
}

void work() {
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + a[i];
        ans = max(ans, max(f[i][0], f[i][1]));
    }
    //for (int i = 1; i <= n; i++)
    //    printf("%d : %d %d\n",i,f[i][0],f[i][1]);
    printf("%d\n", ans);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        work();
    }
    return 0;
}
