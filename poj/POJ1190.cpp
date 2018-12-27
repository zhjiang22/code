#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXM=22;
const int PI=3.14159;
int r[MAXM],h[MAXM];
int mins[MAXM],minv[MAXM];
int N,n;
int ans=0x3f3f3f;

void init()
{
	cin>>N>>n;
	r[0]=h[0]=0x3f3f3f;
	for(int i=1;i<=n;i++)
		mins[i]=mins[i-1]+2*i*i;
	for(int i=1;i<=n;i++)
		minv[i]=minv[i-1]+i*i*i;
}

void dfs(int V,int cur,int nowS)//当前体积，当前层数,当前面积
{
	if(V>N)
		return;
	if(V==N&&cur==n+1)
	{
		ans=min(ans,nowS);
		return;
	}
	if(cur>n)
		return;
	if(nowS>=ans||(nowS+mins[n-cur+1])>ans)
		return;
	if(N-V<minv[n-cur+1])
		return;
	if(2*(N-V)/r[cur-1]>ans-nowS)//useful and important
		return;
	int maxr=min(r[cur-1],(int)sqrt(N-V));
	for(int R=maxr;R>=n-cur+1;R--)
		for(int H=min(h[cur-1],(N-V)/(R*R));H>=n-cur+1;H--)
			if(R!=r[cur-1]&&H!=h[cur-1])
			{
				r[cur]=R;
				h[cur]=H;
				if(cur==1)
					dfs(V+R*R*H,cur+1,nowS+2*R*H+R*R);
				else
					dfs(V+R*R*H,cur+1,nowS+2*R*H);
			}
}


void work()
{
	dfs(0,1,0);
	if(ans==0x3f3f3f)
		cout<<0<<endl;
	else
		cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}