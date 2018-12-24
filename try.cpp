#include <bits/stdc++.h>
using namespace std;

int g[105][105];
int n, m;

int main() {
	memset(g,0x3f,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)	g[i][i] = 0;
	int u, v, w;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		g[u][v] = g[v][u] = w;
	}
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
	
	return 0;
}
