#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int g[105][105][105];
        memset(g, 0x3f, sizeof(g));
        int INF = g[0][0][0];
        int l = flights.size();
        for (int i = 0; i < l; i++)
            g[flights[i][0]][flights[i][1]][1] = flights[i][2];
        for (int len = 1; len <= n; len++)
            for (int k = 1; k <= n; k++)
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= n; j++)
                        g[i][j][s] = min(g[i][j][s], g[i][k][s - 1] + g[k][j][1]);

    }
    int ans = INF;
    for (int i = 1; i <= K; i++)
        ans = min(ans, g[src][dst][i]);
    if (ans == INF)    ans = -1;
    return ans;
};

int main() {
    
}
