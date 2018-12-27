#include <bits/stdc++.h>
using namespace std;

void work() {
    int ans = 0;
    int cur = 2;
    int x;
    while(scanf("%d",&x)&&x){
        if(x == 1)
        {
            ans++;
            cur = 2;
        }
        else
        {
            ans += cur;
            cur += 2;
        }
    }
    printf("%d",ans);
}

int main() {
    work();
    return 0;
}