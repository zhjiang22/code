#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN=1005;
const int eps=1e-12;
double a[MAXN][MAXN];
int m,n;
int T;

void input()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lf",&a[i][j]);
}

int cur;

void work()
{
	cur=1;
	for(int k=1;k<=m;k++)
	{
		bool ok=0;//当前列有没有主元
		for(int i=cur;i<=n;i++)
		{
			if(fabs(a[i][k])>eps)
			{
				swap(a[i],a[cur]);
				ok=1;
				break;
			}
		}
		if(!ok)
			continue;
		for(int j=k+1;j<=m;j++)
			a[cur][j]/=a[cur][k];
		a[cur][k]=1.0;
		for(int i=1;i<=n;i++)
			if(i!=cur)
			{
				double kp=a[i][k];
				for(int j=1;j<=m;j++)
				{
					a[i][j]-=(kp*a[cur][j]);
					if(fabs(a[i][j])<eps)
						a[i][j]=0.0;
				}
			}
		cur++;
	}
}

void output()
{
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%.3f%c",(a[i][j]+eps),j==m?'\n':' ');
	}
}

int main()
{
	/*freopen("input.txt","r",stdin);
	freopen("output.ans","w",stdout);*/
	cin>>T;
	cout<<T<<endl;
	while(T--)
	{
		input();
		work();
		output();
	}
	return 0;
}