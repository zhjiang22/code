#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
using namespace std;

typedef int stade[16];
struct node
{
	stade x;
	int step;
};
stade goal,a;
queue<node> q;
set<int> vis;
int f[4]={1,-1,4,-4};

int change(stade o)
{
	int ans=0,u=1;
	for(int i=15;i>=0;i--)
	{
		ans+=o[i]*u;
		u*=2;
	}
	return ans;
}

int main()
{
	int xxxx,p=0;
	for(int i=0;i<4;i++)
	{
		cin>>xxxx;
		a[p++]=xxxx/1000;
		a[p++]=(xxxx/100)%10;
		a[p++]=(xxxx/10)%10;
		a[p++]=xxxx%10;
	}
	p=0;
	for(int i=0;i<4;i++)
	{
		cin>>xxxx;
		goal[p++]=xxxx/1000;
		goal[p++]=(xxxx/100)%10;
		goal[p++]=(xxxx/10)%10;
		goal[p++]=xxxx%10;
	}
	vis.insert(change(a));
	node po;
	memcpy(&po.x,&a,sizeof(a));
	po.step=0;
	q.push(po);
	
	while(!q.empty())
	{
		node r=q.front();
		q.pop();
		if(memcmp(goal,r.x,sizeof(goal))==0)
		{
			cout<<r.step<<endl;
			return 0;
		}
		for(int i=0;i<=15;i++)
			if(r.x[i])
			{for(int j=0;j<4;j++)
						{
							if((i==3||i==7||i==11||i==15)&&j==0)	continue;
							if((i==0||i==4||i==8||i==12)&&j==1)		continue;
							if((i==12||i==13||i==14||i==15)&&j==2)	continue;
							if((i==0||i==1||i==2||i==3)&&j==3)		continue;
			
							if(r.x[i]!=r.x[i+f[j]])
							{
								node ll;
								memcpy(&ll.x,&r.x,sizeof(r.x));
								swap(ll.x[i],ll.x[i+f[j]]);
								int i1=change(ll.x);
								if(!vis.count(i1))
								{
									ll.step=r.step+1;
									q.push(ll);
									vis.insert(i1);
								}
							}
						}}
	}
	return 0;
}
     