#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
char map[5000000];
int main()
{
	while(scanf("%s",map)!=EOF)
	{
		vector<int >a;
		if(map[0]=='[')
		{
			int ll=strlen(map);
			int i,j;
			bool cc=0;
			for(i=0;i<ll;i++)
			{
				if(map[i]>='0'&&map[i]<='9'&&cc==0)
				{
					cc=1;
					int k=i;
					int wc=0;
					while(map[k]>='0'&&map[k]<='9')
					{
						wc=wc*10+(map[k]-'0');
						k++;
					}
					a.push_back(wc);
				} 
				else
				{
					cc=0;
				}
			}
			if(a.size()==1)
			{
				printf("%d\n",a.back());
				continue;
			}
			int h,l,g;
			l=1;
			g=a.back();
			a.pop_back();
			h=a.back();
			a.pop_back();
			h=h*g+l;
			l=g;
			g=h;//g 要作为分子  l 要做为分母 
			while(a.size()!=0)
			{
				h=a.back();
				a.pop_back();
				h=h*g+l;
				l=g;
				g=h;//g 要作为分子  l 要做为分母 
			}
			printf("%d/%d\n",g,l);
		}
		else
		{
			
			int i=0,j;
			int zuo,you=0;
			zuo=0;
			while(map[i]!='/')
			{
				zuo=zuo*10+(map[i]-'0');
				i++;
			}
			i++;
			while(map[i])
			{
				you=you*10+(map[i]-'0');
				i++;
			}
			if(zuo%you==0)
			{
				printf("[%d]\n",zuo/you);
				continue;
			}
			printf("[");
			int cnm=zuo/you;
			printf("%d;",zuo/you);
			zuo=zuo-cnm*you;
			int cf;
			cf=zuo;
			zuo=you;
			you=cf;
			while(1)
			{
				int cnm=zuo/you;
				printf("%d",cnm);
				if(you!=1&&zuo%you!=0)
				{
					printf(",");
				}
				zuo=zuo-cnm*you;
				if(zuo==0)
				break;
				int cf;
				cf=zuo;
				zuo=you;
				you=cf;
			}
			printf("]\n");
		}
	}
	return 0;
} 