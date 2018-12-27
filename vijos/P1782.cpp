/*
很难想到的二分啊
其实好像有线段树做法但是我太弱了
只能做二分了
但是vijos的数据太强了	各个OJ都AC了
唯独vijos不能
要优化读入数据了
用字符优化读入好像很强势的样子6666
二分订单数量，判断一下前mid个订单是否可以。
具体操作是前缀和处理，即每读入一个订单就在起始天+要借的房间数量，在结束天的下一天减去要借的房间数量
然后比较每一天的前缀和与本天总共的房间数的大小，如果房间数<前缀和，
当然用树状数组维护前缀和也是可以的
但毕竟不是动态的还不如直接前缀和数组维护好
就说明前mid个订单有问题，向前二分；否则就向后二分。
当然我们要先判断是否可行
不可行才开始二分
长见识了
原来二分还可以这样用QAQ
*/
#pragma GCC optimize("O2")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long maxn=1000005;
const long long INF=0x7fffff;
struct node
{
	long long d,x,y;
}a[maxn];
long long d[maxn];
long long minv=INF,maxv;
long long n,m;
long long c[maxn];

inline int read() 
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

bool check(long long m)
{
	memset(c,0,sizeof(c));
	for(int i=1; i<=m; i++) 
	{
        c[a[i].x] += a[i].d;
        c[a[i].y+1]-=a[i].d;
    }
    for(int i=1; i<=n; i++) 
    {
        c[i] += c[i-1];
        if(c[i] > d[i]) return false;
    }
    return true;
}

void init()
{
	 n=read(); m=read();
    for(int i=1; i<=n; i++) 
    	d[i]=read();
    for(int i=1; i<=m; i++) 
    {
        a[i].d=read();
        a[i].x=read();
        a[i].y=read();
    }
}

void solve()
{
	cout<<-1<<endl;
	long long l=1,d=m;
	while(l<=d)
	{
		long long mid=(l+d)/2;
		if(check(mid))
			l=mid+1;
		else
			d=mid-1;
	}
	cout<<l<<endl;
}

int main()
{
	init();
	if(check(m))
		cout<<0<<endl;
	else
		solve();
	return 0;
}