#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#define rep(i, x, y) for (int i = x; i <= y; ++i)

using namespace std;

const int maxn = 200005;
int pool_cnt;

struct Node {
    int nextNode;
    Node *next;
} *N[maxn], pool[maxn << 1];

int n;

inline void AddEdge(int x, int y) {
    Node *p = &pool[++pool_cnt];
    *p = (Node){y, N[x]};
    N[x] = p;
}
inline int read() {
    int r = 0;
    char p = getchar();
    while (!isdigit(p)) p = getchar();
    while (isdigit(p)) {r *= 10; r += (p - '0'); p = getchar();}
    return r;
}
bool vis1[maxn];
int down1[maxn], down2[maxn], father[maxn];
void dfs1(int k) {
    vis1[k] = true;
    for (Node *p = N[k]; p; p = p->next) {
        if (!vis1[p->nextNode]) {
            father[p->nextNode] = k;
            dfs1(p->nextNode);
            if (down1[p->nextNode] + 1 > down1[k]) {
                down2[k] = down1[k];
                down1[k] = down1[p->nextNode] + 1;
            }
            else if (down1[p->nextNode] + 1 > down2[k]) down2[k] = down1[p->nextNode] + 1;
        }
    }
}
bool vis2[maxn];
int up[maxn];
void dfs2(int k) {
    if (k != 0) {
        up[k] = up[father[k]] + 1;
        if (down1[father[k]] - 1 == down1[k]) up[k] = max(up[k], down2[father[k]] + 1); else up[k] = max(up[k], down1[father[k]] + 1);
    }
    vis2[k] = true;
    for (Node *p = N[k]; p; p = p->next) {
        if (!vis2[p->nextNode]) {
            dfs2(p->nextNode);
        }
    }
}
int length[maxn];
int main(int argc, const char *argv[]) {
	freopen("D:\\duipa\\data.txt","r",stdin);
	freopen("D:\\duipa\\ans1.txt","w",stdout);
    scanf("%d", &n);
    int x, y;
    rep(i, 1, n - 1) {
        scanf("%d %d", &x, &y);
        AddEdge(x, y);
        AddEdge(y, x);
    }
    dfs1(0);
    dfs2(0);
    int maxl = 0;
    rep(i, 0, n - 1) {
//        printf("number:%d first:%d second:%d up:%d\n", i, down1[i], down2[i], up[i]);
        length[i] = down1[i] + max(up[i], down2[i]);
        maxl = max(maxl, length[i]);
    }
    rep(i, 0, n - 1) {
        if (length[i] == maxl) printf("%d\n", i);
    }
    return 0;
}