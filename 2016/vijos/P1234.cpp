#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 10;

int N, M, K, ans, tot;
int fa[maxn];

struct edge{ int x, y, v; } es[maxn];
bool cmp(edge e1, edge e2) { return e1.v < e2.v; }

int find(int x) { return x == fa[x] ? x : find(fa[x]); }

void Kruskal() {
    sort(es + 1, es + 1 + M, cmp);
    for(int i = 1; i <= N; i++) fa[i] = i;
    for(int i = 1; i <= M && tot > K; i++) {
        int u = find(es[i].x), v = find(es[i].y);
        if(u != v) {
            fa[u] = v;
            ans += es[i].v;
            tot--;
        }
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &K); tot = N;
    for(int i = 1; i <= M; i++) scanf("%d%d%d", &es[i].x, &es[i].y, &es[i].v);
    Kruskal();
    if(tot == K) printf("%d\n", ans);
    else printf("No Answer\n");

    return 0;
}