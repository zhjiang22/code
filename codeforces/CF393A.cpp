#include<bits/stdc++.h>
using namespace std;

const int MAXN=105;
char a[MAXN];
int n;

void init()
{
	gets(a);
	n=strlen(a);
}

void work()
{
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	for(int i=0;i<n;i++)
		if(a[i]=='n')
			cnt1++;
		else	if(a[i]=='e')
			cnt2++;
		else	if(a[i]=='t')
			cnt3++;
		else	if(a[i]=='i')
			cnt4++;
	int ans=100;
	ans=min(ans,cnt2/3);	ans=min(ans,cnt3);
	ans=min(ans,cnt4);
	if(cnt1<3)
		ans=0;
	else
		ans=min(ans,(cnt1-3)/2+1);
	printf("%d\n",ans);
}

int main()
{
	init();
	work();
	return 0;
}
     