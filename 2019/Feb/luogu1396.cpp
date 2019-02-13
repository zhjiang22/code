#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
struct Edge {
    int to,nxt;
    int w;
    Edge() {
        to = nxt = -1;
        w = 0;
    }
}e[MAXN << 2];
int first[MAXN];
int tot;
int n, m;
int s, t;
int maxw;

inline void Add_Edge(const int &u, const int &v, const int &w) {
    e[++tot].w = w; e[tot].to = v; e[tot].nxt = first[u]; first[u] = tot;
}

void init() {
    cin >> n >> m >> s >> t;
    memset(first, -1, sizeof(first));
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        Add_Edge(u, v, w);  Add_Edge(v, u, w);
        maxw = max(maxw, w);
    }
}

bool inq[MAXN];
int d[MAXN];
const int INF = 0x3f3f3f3f;

bool check(const int &val) {
    memset(inq, 0, sizeof(inq));
    fill(d, d + n + 1, INF);
    queue<int> q;
    q.push(s);  inq[s] = 1;  d[s] = 0;
    while (!q.empty()) {
        int u = q.front();  q.pop();
        inq[u] = 0;
        for (int i = first[u]; i != -1; i = e[i].nxt) {
            int &v = e[i].to, &w = e[i].w;
            if (w > val)    continue;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return d[t] < INF;
}

void work() {
    int l = 0, r = maxw;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    init();
    work();
    return 0;
}