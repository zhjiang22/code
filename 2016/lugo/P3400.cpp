#include<iostream>
#include<cstdio>
using namespace std;
int a[3000][3000];
    int m,n,squ=0,rec,k,i;//m,n输入不解释，squ是正方形个数，rec是长方形个数，k是为了交换，i是循环变量
void solve()
{
    if(m<n){//让m>=n
        k=m;
        m=n;
        n=k;
    }
    for(i=0;i<n;i++)//求∑(i=0,n-1) (m-i)(n-i)
        squ+=(n-i)*(m-i);
    rec=(n*m*(n+1)*(m+1))/4-squ;//求长方形个数(包括正方形)再减去正方形个数
    printf("%d",squ+rec);
}
bool check(int x1,int y1,int x2,int y2)
{
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(!a[i][j])
                return 0;
    return 1;
}

void work()
{
    int ans=0;
    for(int x1=1;x1<=m;x1++)
        for(int y1=1;y1<=n;y1++)
            for(int x2=x1;x2<=m;x2++)
                for(int y2=y1;y2<=n;y2++)
                    if(check(x1,y1,x2,y2))
                        ans++;
    cout<<ans<<endl;
}

int main( ){
    scanf("%d%d",&m,&n);//输入
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    if(n>50)
    {
         solve();
         return 0;
    }
    else
    {
        work();
        return 0;
    }
    return 0;
}