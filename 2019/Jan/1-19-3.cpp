#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int m;

int check(int mid)
{ //check的作用是检查当前mid是否可行
	int sum = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sum + a[i] > mid)
		{
			ans++;
			sum = a[i];
		}
		else
			sum += a[i];
	}
	if (sum > 0)
		ans++;
	if (ans <= m)
		return 1;
	else
		return 0;
}

int main()
{
	cin >> n >> m;
	int maxd = 0, sumd = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sumd += a[i];
		maxd = max(a[i], maxd);
	}
	int l = maxd, r = sumd;
	while (l < r)
	{ //二分尝试
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid; //尝试寻找更小
		else
			l = mid + 1; //尝试寻找更大
	}
	cout << l << endl;
	return 0;
}