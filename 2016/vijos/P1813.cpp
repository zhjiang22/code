#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=5005;
struct people
{
	int num;
	int score;
}a[MAXN];
int n,m;
int k;

inline bool cmp(people a,people b)
{
	if(a.score==b.score)
		return a.num<b.num;
	else
		return a.score>b.score;
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].score;
	sort(a+1,a+n+1,cmp);
}

int main()
{
	init();
	k=m*1.5;
	while(a[k].score==a[k+1].score)
		k++;
	cout<<a[k].score<<" "<<k<<endl;
	for(int i=1;i<=k;i++)
		cout<<a[i].num<<" "<<a[i].score<<endl;
	return 0;
}
     