#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <queue>
using namespace std;

const int INF=0x7fffff;
priority_queue<int,vector<int>,greater<int> > q;
int n;
long long ans=0;

int main()
{
	int a,b;
	int x;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x,q.push(x);
	for(int i=1;i<n;i++)
	{
		a=q.top();q.pop();
		b=q.top();q.pop();
		ans+=(a+b);
		q.push(a+b);
	}
	cout<<ans<<endl;
	return 0;
}
     