#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int d[1000]={0};
int f[1000][1000]={0};
int ans=0;
int n;

struct node
{
	int x,y;
}a[1000]={0};

int powder(int i)
{
	if(d[i]) return d[i];
	d[i]=1;
	for(int j=0;j<n;j++)
	{
		if(f[i][j])
			d[i]=max(d[i],powder(j)+1);	
	}
	return d[i];
}

void print(int i)
{
	cout<<i+1;
	for(int j=0;j<n;j++)
	if(f[i][j]&&d[i]==d[j]+1)
	{
		print(j);
		break;
	}
}

int main()
{

	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i].x>>a[i].y;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if((a[i].x<a[j].x&&a[i].y<a[j].y)||(a[i].y<a[j].x&&a[i].x<a[j].y))
		f[i][j]=1;
		for(int i=0;i<n;i++)
		d[i]=powder(i);
	int k;
	for(int i=0;i<n;i++)
		if(d[i]>ans)	ans=d[k=i];
		cout<<ans<<endl;
		print(k);
	
		return 0;	
}
/*样例输入
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
样例输出
5*/