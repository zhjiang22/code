#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long n, m;
long long d[1001], c[10001], dp[1001][1001];

void init()
{
	scanf("%lld%lld", &n, &m);
	for (long long i = 0; i < n; ++i)
		scanf("%lld", d + i);
	for (long long i = 1; i <= m; ++i)
		scanf("%lld", c + i);
	for (long long i = 0; i <= n; ++i)
		for (long long j = 0; j <= m; ++j)
		{
			if (!i)
				dp[i][j] = 0;
			else
				dp[i][j] = 1 << 30;
		}
}

int main()
{
	init();
	for (long long i = 1; i <= n; ++i)
		for (long long j = 1; j <= m; ++j)
		{
			dp[i][j] = min(dp[i][j], dp[i][j-1]);
			if(j>=i)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]+d[i-1]*c[j]);
		}
	printf("%lld", dp[n][m]);
}