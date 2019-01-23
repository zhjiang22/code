#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int x;
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> x;
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] >= x)
            r = mid; //[l,mid]
        else
            l = mid + 1; //[mid+1,r]
    }
/*
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (a[mid] > x)
            r = mid - 1; //[l,mid-1]
        else
            l = mid; //[mid,r]
    }
*/
    if (a[l] == x)
        cout << l << endl;
    else
        cout << -1 << endl;
    return 0;
}