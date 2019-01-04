#include <bits/stdc++.h>
using namespace std;

int a[100];
int n;

int main() {
     vector<int> vv;
    vv.push_back(4);
    vv.push_back(5);
    for(auto p:vv)
        cout << p << endl;
    return 0;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = i;
        int len = 0;
        while(k) {
            a[len++] = k % 10;
            k /= 10;
        }
        int l = 0, r = len - 1;
        int ok = 1;
        while (l < r) {
            if(a[l] != a[r]) {
                ok = 0;
                break;
            }
            l++;
            r--;
        }
        if(ok == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}