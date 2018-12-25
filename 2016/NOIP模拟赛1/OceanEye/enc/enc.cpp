#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxl = 2000;

int s1[maxl],s2[maxl],s3[maxl],ans[maxl],len1,len2,len3,i,j;
int map[30],chk[30];

int main()
{
	freopen("enc.in","r",stdin);
	freopen("enc.out","w",stdout);
	char ch=getchar();
	len1 = len2 = len3 = 0;
	while(1)
	{
		if (ch=='\n') break;
		s1[len1++]=ch;
		ch=getchar();
	}
	//while(ch==' '||ch=='\n')
	ch=getchar();while(ch==' '||ch=='\n') ch = getchar();
	while(1)
	{
		if (ch=='\n') break;
		s2[len2++]=ch;
		ch=getchar();
	}
	//while(ch==' '||ch=='\n')
	ch=getchar();while(ch==' '||ch=='\n') ch = getchar();
	if(len1!=len2)
	{
		printf("ERROR\n");
		return 0;
	}
	memset(map,-1,sizeof(map));
	memset(chk,-1,sizeof(chk));
	for(i=0;i<len1;i++)
	{
		int a = s1[i]-96 , b = s2[i]-96;
		if(chk[a]==-1)
		{
			chk[a]=b;
			if(map[b]==-1)
				map[b] = a;
			else if(map[b]!=a)
			{
				printf("ERROR\n");
				return 0;
			}
		}
		else if(chk[a]!=b)
		{
			printf("ERROR\n");
			return 0;
		}
	}
	while(1)
	{
		if (ch=='\n') break;
		s3[len3++]=ch;
		ch=getchar();
	}
	for(i=0;i<len3;i++)
	{
		if(map[s3[i]-96]==-1)
		{
			printf("ERROR\n");
			return 0;
		}
		ans[i] = map[s3[i]-96] + 96;
	}
	for(i=0;i<len3;i++) printf("%c",ans[i]);
	printf("\n");
	return 0;
}

