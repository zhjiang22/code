#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v)
{
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
	if(v==0)
		putchar(48);
	else  
    {
    	if(v<0)
    	{
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0)
    	{
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

const int MAXN=1005;
map<string,int> p;
string ch[MAXN];
int cnt[MAXN];
int n;
int m;

int change(const string& c)
{
	if(!p.count(c))
	{
		p[c]=++m;
		ch[m]=c;
		return m;
	}
	else
		return p[c];
}

void work()
{
	string c;
	memset(cnt,0,sizeof(cnt));
	p.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		int x=change(c);
		cnt[x]++;
	}
	int maxd=-1,maxp;
	for(int i=1;i<=m;i++)
	{
		if(cnt[i]>maxd)
		{
			maxd=cnt[i];
			maxp=i;
		}
	}
	cout<<ch[maxp]<<endl;
}

int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		work();
	}
	return 0;
}
     