/*
递归入门吧
直接解决就好了
不多说啥
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;   

char a[1050][1050];

void work(int n,int x,int y)
{
    if(n==1)
    {
        a[x][y]=a[x-1][y+1]='/';
        a[x-1][y+2]=a[x][y+3]='\\';
        a[x][y+1]=a[x][y+2]='_';
        return;
    }
    else
    {
        work(n-1,x-(1<<n-1),y+(1<<(n-1)));
        work(n-1,x,y);
        work(n-1,x,y+(1<<n));
        return;
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    work(n,(1<<n),1);
    for(i=1;i<=(1<<n);i++)
    {
        for(j=1;j<=i+(1<<n);j++)
            if(a[i][j])cout<<a[i][j];else cout<<' ';
        cout<<endl;
    }
    return 0;
}