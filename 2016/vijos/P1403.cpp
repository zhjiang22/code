#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int maxn=150;
int n;
int map[maxn][maxn];
int ansall;
int t;
int ans[maxn];
int f8[maxn];

int main()
{
	cin>>n;
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
cin>>map[i][j];

for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
char ch=map[i][j];long sum=0;
if(map[i][j-1]==ch&&map[j-1]==ch)
{
long x=f1[i][j-1];
long y=f1[j-1];
if(x<y)y=x;else x=y;
f1[i][j]=x+1;
sum+=f1[i][j];
}
if(map[j-1]==ch&&map[j]==ch)
{
long x=f2[j-1];
long y=f2[j];
if(x<y)y=x;else x=y;
f2[i][j]=x+1;
sum+=f2[i][j];
}
if(map[j]==ch&&map[j+1]==ch)
{
long x=f3[j];
long y=f3[j+1];
if(x<y)y=x;else x=y;
f3[i][j]=x+1;
sum+=f3[i][j];
}
if(map[i][j-1]==ch&&map[j]==ch)
{
long x=f4[i][j-1];
long y=f4[j];
if(x<y)y=x;else x=y;
f4[i][j]=x+1;
sum+=f4[i][j];
}
if(map[j-1]==ch&&map[j]==ch&&map[j+1]==ch)
{
long x=f5[j-1];
long y=f5[j+1];
if(x<y)y=x;else x=y;
f5[i][j]=x+1;
sum+=f5[i][j];
}
int k;
for(k=1;k<=t;k++)
if(ans[k].abc==(int)ch)break;
if(k>t){t++;ans[t].num=sum;ans[t].abc=(int)ch;}
if(k<=t){ans[k].num+=sum;}
}
for(int i=n;i>=1;i--)
for(int j=n;j>=1;j--)
{
char ch=map[i][j];long sum=0;
if(map[j+1]==ch&&map[j]==ch&&map[j-1]==ch)
{
long x=f6[j-1];
long y=f6[j+1];
if(x<y)y=x;else x=y;
f6[i][j]=x+1;
sum+=f6[i][j];
}
int k;
for(k=1;k<=t;k++)
if(ans[k].abc==(int)ch)break;
if(k>t){t++;ans[t].num=sum;ans[t].abc=(int)ch;}
if(k<=t){ans[k].num+=sum;}
}
for(int j=1;j<=n;j++)
for(int i=n;i>=1;i--)
{
char ch=map[i][j];long sum=0;
if(map[i][j-1]==ch&&map[j-1]==ch&&map[j-1]==ch)
{
long x=f7[j-1];
long y=f7[j-1];
if(x<y)y=x;else x=y;
f7[i][j]=x+1;
sum+=f7[i][j];
}
int k;
for(k=1;k<=t;k++)
if(ans[k].abc==(int)ch)break;
if(k>t){t++;ans[t].num=sum;ans[t].abc=(int)ch;}
if(k<=t){ans[k].num+=sum;}
}
for(int j=n;j>=1;j--)
for(int i=1;i<=n;i++)
{
char ch=map[i][j];long sum=0;
if(map[i][j+1]==ch&&map[j+1]==ch&&map[j+1]==ch)
{
long x=f8[j+1];
long y=f8[j+1];
if(x<y)y=x;else x=y;
f8[i][j]=x+1;
sum+=f8[i][j];
}
int k;
for(k=1;k<=t;k++)
if(ans[k].abc==(int)ch)break;
if(k>t){t++;ans[t].num=sum;ans[t].abc=(int)ch;}
if(k<=t){ans[k].num+=sum;}
}
qsort(ans+1,t,sizeof(ans[0]),cmp);
for(int i=1;i<=t;i++)
ansall+=ans[i].num;
cout<<ansall<<endl;
for(int i=1;i<=t;i++)
cout<<(char)ans[i].abc<<" "<<ans[i].num<<endl;
}
   