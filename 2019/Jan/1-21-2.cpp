#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int b[1005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = i;
    for (int i = 1; i <= n; i++) //冒泡排序
        for (int j = i + 1; j <= n; j++)
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]); //b[i]表示当前i位置的人的编号为b[i]，注意要跟随a数组改变
            }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";//输出各位置对应的人的编号
    cout << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] * (n - i);//累加等待时间
    printf("%.2f\n", (double)ans / n);
    return 0;
}