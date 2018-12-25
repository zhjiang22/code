/*
OTZ怎么办窝好弱啊
弱死了怎么办我的天啊QWQ
一开始看了一眼题目	我去怎么这么水
然后直接开始写
然后结果看成了
要我输出有多少张覆盖了
QWQ
然后又傻逼一般地以为他给我的是中间的点
仔细一看是左下角的点
然后判断的也错了
唉果然我去NOIP就是被虐啊
跪求各位中小学生饶我一马Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
struct node
{
	int x,y,l,h;
}a[MAXN];
int n;
int x,y;
int ans;

bool check(int i)
{
	return (a[i].x+a[i].l>=x&&a[i].x<=x&&
	   a[i].y+a[i].h>=y&&a[i].y<=y);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].l>>a[i].h;
	cin>>x>>y;
	for(int i=n;i>=1;i--)
		if(check(i))
		{
			cout<<i<<endl;
			return 0;
		}
	cout<<-1<<endl;
	return 0;
}
     