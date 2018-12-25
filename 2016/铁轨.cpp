#include<cstdio>
#include<stack>
using namespace std;
const int MAXN=1000+10;
int n,t[MAXN];
int main()
{
	while(scanf("%d",&n)==1)
	{
		stack<int> s;
		int a=1,b=1;
		for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
		int ok=1;
		while(b<=n)
		{
			if(a==t[b])
			{
				a++;b++;
			}
			else if(!s.empty()&&s.top()==t[b])
			{
				s.pop();
				b++;
			}
			else if(a<=n)
			s.push(a++);
			else
			{
				ok=0;break;
			}
		}
		printf("%s\n",ok?"Yes":"No");
		}
		return 0;
}
