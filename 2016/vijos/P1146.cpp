#include <iostream>
using namespace std;
int n,ans;
bool map[6][6],v[20];
void add()
{
int t=0;
for(int i=1;i<=5;i++)
{
if(map[i][1]==1 && map[i][2]==1 && map[i][3]==1 && map[i][4]==1 && map[i][5]==1)
t++;
if(map[1][i]==1 && map[2][i]==1 && map[3][i]==1 && map[4][i]==1 && map[5][i]==1)
t++;
}
if(map[1][1]==1 && map[2][2]==1 && map[3][3]==1 && map[4][4]==1 && map[5][5]==1)
t++;
if(map[5][1]==1 && map[4][2]==1 && map[3][3]==1 && map[2][4]==1 && map[1][5]==1)
t++;
if(v[t]==0)
{
ans+=t;
v[t]=true;
}
}
void down(int k,int l)
{
int x=(k-1)/5+1,y=(k-1)%5+1;
if(l==n)
{
add();
return ;
}
for (int i=k+1;i<=25;i++)
{
int x1=(i-1)/5+1,y1=(i-1)%5+1;
map[x1][y1]=1;
down(i,l+1);
map[x1][y1]=0;
}
}
int main()
{
cin >> n;
for (int i=1;i<=25;i++)
{
int x=(i-1)/5+1,y=(i-1)%5+1;
map[x][y]=1;
down(i,1);
map[x][y]=0;
}
cout << ans << endl;
return 0;
}