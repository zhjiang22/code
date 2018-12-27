#include<iostream>
using namespace std;
const int maxn = 1000 + 5;
int n, a[maxn]={0};
int dfs(int t){
    int h= t / 2;
    if(a[h]) return a[h];
    a[h] = 1;
    for(int i = 1; i <= h; i++)    a[h] += dfs(i);
    return a[h];
}
int main(){
    cin >> n;
    cout << dfs(n);
    return 0;

}