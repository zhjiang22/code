#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int x;
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> x;
	sort(a + 1, a + n + 1);
	cout << lower_bound(a + 1, a + n + 1, x) - a << endl;//下界，返回>=x的第一个数的位置
	cout << upper_bound(a + 1, a + n + 1, x) - a << endl;//上界，返回>x的第一个数的位置
	cout << upper_bound(a + 1, a + n + 1, x) - lower_bound(a + 1, a + n + 1, x) << endl;
	//上界-下界=出现的次数
	return 0;
}