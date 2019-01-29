#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
    double w;
    bool operator<(const Edge &e) const
    {
        return w < e.w;
    }
} e[1005];
int fa[1005];
int tot;
int n = 14;

inline int getfather(int x)
{
    return fa[x] == x ? x : fa[x] = getfather(fa[x]);
}

inline void Add_Edge(const int &u, const int &v, const double &w)
{
    e[++tot].u = u;
    e[tot].v = v;
    e[tot].w = w;
}

void add_edge1()
{
    Add_Edge(1, 11, 18.804);
    Add_Edge(1, 9, 25.639);
    Add_Edge(9, 10, 7.390);
    Add_Edge(10, 11, 14.096);
    Add_Edge(2, 10, 12.264);
    Add_Edge(2, 3, 10.880);
    Add_Edge(3, 9, 21.362);
    Add_Edge(2, 4, 16.574);
    Add_Edge(3, 4, 10.168);
    Add_Edge(4, 7, 13.343);
    Add_Edge(4, 8, 33.503);
    Add_Edge(7, 8, 20.256);
    Add_Edge(6, 7, 22.278);
    Add_Edge(6, 8, 4.965);
    Add_Edge(5, 6, 27.853);
}

void add_edge2()
{
    Add_Edge(12, 1, 51.487);
    Add_Edge(12, 2, 14.01);
    Add_Edge(12, 3, 4.538);
    Add_Edge(12, 4, 6.18);
    Add_Edge(12, 5, 68.939);
    Add_Edge(12, 6, 41.167);
    Add_Edge(12, 7, 19.093);
    Add_Edge(12, 8, 39.348);
    Add_Edge(12, 9, 25.896);
    Add_Edge(12, 10, 23.349);
    Add_Edge(12, 11, 37.393);
}

void add_edge3()
{
    Add_Edge(13, 1, 1.769);
    Add_Edge(13, 2, 43.517);
    Add_Edge(13, 3, 48.234);
    Add_Edge(13, 4, 57.997);
    Add_Edge(13, 5, 121.437);
    Add_Edge(13, 6, 93.583);
    Add_Edge(13, 7, 71.305);
    Add_Edge(13, 8, 91.186);
    Add_Edge(13, 9, 26.876);
    Add_Edge(13, 10, 31.235);
    Add_Edge(13, 11, 19.236);
}

void add_edge4()
{
    Add_Edge(14, 1, 116.943);
    Add_Edge(14, 2, 75.393);
    Add_Edge(14, 3, 70.072);
    Add_Edge(14, 4, 60.148);
    Add_Edge(14, 5, 3.365);
    Add_Edge(14, 6, 24.561);
    Add_Edge(14, 7, 46.836);
    Add_Edge(14, 8, 27.497);
    Add_Edge(14, 9, 91.308);
    Add_Edge(14, 10, 87.388);
    Add_Edge(14, 11, 101.222);
}

void init()
{
    add_edge1();
    add_edge2();
}

void Kruskal()
{
    cout << "The edges we choose:" << endl;
    double ans = 0;
    int cnt = 0;
    for (int i = 1; i <= tot; i++)
    {
        int &x = e[i].u, &y = e[i].v;
        if (getfather(x) == getfather(y))
            continue;
        fa[getfather(x)] = getfather(y);
        ans += e[i].w;
        cnt++;
        cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
        if (cnt == n - 1)
            break;
    }
    cout << "The ans:" << endl;
    cout << ans << endl;
}

void work()
{
    sort(e + 1, e + tot + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    Kruskal();
}

int main()
{
    init();
    work();
    return 0;
}