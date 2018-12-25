/*
直接抄一下吧
数学实在差
这道题特别坑，用long long int 还不够,要unsigned long long int 才行。
其次，我发现对于这种题，直接动态规划，思路特别简单，而那些灵巧的递推需要灵感才能发现。
算法大意：g(a,n)表示把a个相同的球放入n个不同的盒子(必须放进去)。
那么，ans=【g(a,n)+g(a-1,n)+g(a-2,n)......+g(0,n)】*[g(b,n)+g(b-1,n)+.....+g(0,n)].
而g(a,n)=g(a,n-1)                表示第一个盒子放0个球，
        +g(a-1,n-1)       表示第一个盒子放一个球
           +。。+g(0,n-1)     表示第一个盒子放a个球
*/
#include <iostream>
#include <cstring> 
#include <cmath>
using namespace std;   
long long int g[17][23];
int n, a, b;
void init(){
    int i, j,k;
    memset(g, 0, sizeof(g)); 
    for (i = 0; i <= n; i++)g[0][i] = 1;
    for (i = 1; i <= 15; i++){
        for (j = 1; j <= n; j++){
            g[i][j] = 0;
            for (k = 0; k <= i; k++){
                g[i][j] += g[i-k][j-1];
            }
        }
    }
}
int main(){ 
    freopen("in.txt", "r", stdin);  
    cin >> n >> a >> b;
    init();
    int i;
    unsigned long long int ga, gb;
    ga = gb = 0;
    for (i = 0; i <= a; i++){
        ga += g[a - i][n];
    }
    for (i = 0; i <= b; i++)
        gb += g[b - i][n];
    cout <<(unsigned long long ) (ga*gb) << endl;
    return 0;
}