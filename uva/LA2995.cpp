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

const int MAXN=12;
const int MAXK=6;
char view[MAXK][MAXN][MAXN];
char pos[MAXN][MAXN][MAXN];
int n;

char read_char()
{
	char ch;
	for(;;)
	{
		ch=getchar();
		if((ch>='A'&&ch<='Z')||ch=='.')
			return ch;
	}
}

inline void get(int k,int i,int j,int len,int& x,int& y,int& z)
{
	if(k==0)	{x=len;y=j;z=i;}
	else	if(k==1)	{x=n-j-1;y=len;z=i;}
	else	if(k==2)	{x=n-len-1;y=n-j-1;z=i;}
	else	if(k==3)	{x=j;y=n-len-1;z=i;}
	else	if(k==4)	{x=n-i-1;y=j;z=len;}
	else	if(k==5)	{x=i;y=j;z=n-len-1;}
}

void init()
{
	for(int i=0;i<n;i++)
		for(int k=0;k<6;k++)
			for(int j=0;j<n;j++)
				view[k][i][j]=read_char();
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				pos[k][i][j]='@';
}

void work()
{
	for(int k=0;k<6;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(view[k][i][j]=='.')
					for(int len=0;len<n;len++)
					{
						int x,y,z;
						get(k,i,j,len,x,y,z);
						pos[x][y][z]='.';
					}

	for(;;)
	{
		bool done=0;
		for(int k=0;k<6;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(view[k][i][j]!='.')
						for(int len=0;len<n;len++)
						{
							int x,y,z;
							get(k,i,j,len,x,y,z);
							if(pos[x][y][z]=='.')
								continue;
							if(pos[x][y][z]=='@')
							{
								pos[x][y][z]=view[k][i][j];
								break;
							}
							if(pos[x][y][z]==view[k][i][j])
								break;
							pos[x][y][z]='.';
							done=1;
						}
		if(!done)
			break;
	}

	int ans=0;
	for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
			for(int z=0;z<n;z++)
				if(pos[x][y][z]!='.')
					ans++;
	printf("Maximum weight: %d gram(s)\n",ans);
}

int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		init();
		work();
	}
	return 0;
}
     