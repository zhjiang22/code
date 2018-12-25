/*
比较简单的一道区间dp了
然而我竟然想了半天没想到
其实我们仔细一看就可以发现
每一次取数	对于取每一行的哪个数
其实是每行独立的
怎么说呢	就是其实你可以把问题分解成
在n行中每次取数	使得每行的得到的价值最大
每行最优一定就能得到全局最优	这是充分必要条件
所以我们就可以转换为n次dp
每次是在某一行进行dp求出最大值
那么问题变成了一维了
我们再看怎么处理一维呢？	一维就比较简单了
定义状态f[i][j]表示从左向右取了i个数字,从右向左取了j个数字所能达到的最大值
而对于决策来说只有取最左或最右的数这两种决策
f[i][j]=max(f[i-1][j]+a[x][i]*b[i+j],f[i][j-1]+a[x][m-j+1]*b[i+j])
(其中b[i]表示2^i的数)
注意要从0开始递推，所以我们要特判一下i=0或者j=0的情况
即不能在某一端扩展了
所以我们就可以得出正确答案了
但数据范围也说了
{
60%的数据满足：1<=n,m<=30,答案不超过10^16
100%的数据满足：1<=n,m<=80,0<=a<=1000
}
这就不得不用高精度了
高精度真心难写	所以我这么懒的弱逼就直接放弃了
然后就明白dp就好了	高精度有时间好好练习一下QWQ
这是我的非高精度代码	然后用了别人的高精度代码过了一下安慰自己
23333333333333333
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=85;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int b[MAXN];
char ans[20];
char c[20];
int n,m;
int l;

void change(int x)
{
	int k=0;
	while(x)
	{
		a[k++]=(x%10)+'0';
		x/=10;
	}
	a[k]='/0';
}

void add(int x)
{
	change(x);
	for(int i=0;i<max)
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];

}

void getb()
{
	int x=2;
	for(int i=1;i<MAXN;i++)
		b[i]=x,x*=2;
}

int dp(int x)
{
	int ans=0;
	memset(f,0,sizeof(f));
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			{
				if(i==0&&j==0)
					continue;
				else	if(i==0&&j!=0)
					f[i][j]=max(f[i][j],f[i][j-1]+a[x][m-j+1]*b[i+j]);
				else	if(j==0&&i!=0)
					f[i][j]=max(f[i][j],f[i-1][j]+a[x][i]*b[i+j]);
				else
					f[i][j]=max(f[i-1][j]+a[x][i]*b[i+j],f[i][j-1]+a[x][m-j+1]*b[i+j]);
			}
	for(int i=1;i<=m;i++)
		ans=max(ans,f[i][m-i]);
	return ans;
}

int main()
{
	init();
	getb();
	for(int i=1;i<=n;i++)
		add(dp(i));
	cout<<ans<<endl;
	return 0;
}
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 80 + 5;

struct bignum{
    int l; short int w[1000];
    bignum(){
        l = 1; memset(w, 0 , sizeof(w));
    }

    bignum(int x){
        l = 0; memset(w, 0 , sizeof(w));
        while(x){
            w[l] = x % 10; x /= 10;
            l++;
        }
    }

    bool operator > (bignum x){
        if(l > x.l) return true;
        else 
        if(l == x.l) 
            for(int i = l - 1; i >= 0; i--){
                if(w[i] > x.w[i]) return true;
                if(w[i] < x.w[i]) return false;
            }

        return false;
    }

    bignum operator + (const bignum& x){
        bignum ans;
        if(l>x.l) ans.l=l;
        else ans.l=x.l;

        for(int i = 0; i < ans.l; i++){
            ans.w[i] += w[i] + x.w[i];
            ans.w[i+1] += ans.w[i] / 10;
            ans.w[i] %= 10;
        }
        if(ans.w[ans.l]) ans.l++;
        return ans;

    }

    bignum operator * (const bignum& x){
        bignum ans;
        ans.l = l + x.l;
        for(int i=0;i<l;i++){
            for(int j=0;j<x.l;j++){
                ans.w[i+j] += w[i] * x.w[j];
                ans.w[i+j+1] += ans.w[i+j] / 10;
                ans.w[i+j] %= 10;
            }
        }
        if(ans.w[ans.l-1]==0) ans.l--;
        return ans;
    }
    bignum operator * (int x){
        bignum ans(x);
        return operator*(ans);
    }

    void print(){
        if(l == 0) cout<<0;
        for(int i = l - 1; i >= 0; i--)
            printf("%d", w[i]);
        printf("\n");
    }


};
int a[maxn]={0};
bignum d[maxn][maxn];//d[i][j]:某一排！！从i到j能够取到的最大值 
int n, m;
int main(){
    cin >> n >> m;
    bignum ans = 0; int x;

    bignum mi[83];//m[i]为2的i次幂
    mi[0] = 1;
    for(int i = 1; i <= m; i++){
        mi[i] = mi[i-1];
        mi[i] = mi[i] * 2;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x; a[j] = x;
        }
        for(int i = 1; i <= m; i++) d[i][i] = mi[m]*a[i];
        for(int l = 1; l < m; l++){
            for(int i = 1; i < m; i++){
                if(i + l > m) break;
                bignum v1 = mi[m - l] * a[i]   + d[i+1][i+l];
                bignum v2 = mi[m - l] *a[i+l] + d[i][i+l-1];
                if(v1>v2) d[i][i+l] = v1;
                else d[i][i+l] = v2;
            }
        }
        ans = ans + d[1][m];
    }

    ans.print();

    return 0;

}