#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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

const int MAXM=55;
const int MAXN=1005;
int a[MAXM][MAXN];
int maxchar[MAXN];
int m,n;
int T;

inline int get_char()
{
	char ch;
	for(;;)
	{
		ch=getchar();
		if(ch=='A')
			return 1;
		else	if(ch=='C')
			return 2;
		else	if(ch=='G')
			return 3;
		else	if(ch=='T')
			return 4;
	}
}

char DNA[5]={' ','A','C','G','T'};

void init()
{
	read(m);	read(n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=get_char();
	for(int i=1;i<=n;i++)
	{
		int a1=0,a2=0,a3=0,a4=0;
		for(int j=1;j<=m;j++)
		{
			if(a[j][i]==1)
				a1++;
			else	if(a[j][i]==2)
				a2++;
			else	if(a[j][i]==3)
				a3++;
			else	if(a[j][i]==4)
				a4++;
		}
		if(a1>=a2&&a1>=a3&&a1>=a4)
			maxchar[i]=1;
		else	if(a2>=a1&&a2>=a3&&a2>=a4)
			maxchar[i]=2;
		else	if(a3>=a1&&a3>=a2&&a3>=a4)
			maxchar[i]=3;
		else	
			maxchar[i]=4;
	}
}

void work()
{
	for(int i=1;i<=n;i++)
		putchar(DNA[maxchar[i]]);
	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(maxchar[i]!=a[j][i])
				ans++;
		}
	out(ans);
}

int main()
{
	read(T);
	while(T--)
	{
		init();
		work();
	}
	return 0;
}
     