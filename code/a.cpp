#include<bits/stdc++.h>
using namespace std;

const int N=200010;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char a[N],b[N];
	scanf("%s",a+1);
	scanf("%s",b+1);
	int n=strlen(a+1);
	int l=0,r=n+1;
	while(l+1<=n && a[l+1] == b[l+1]) l++;
	while(r-1>=1 && a[r-1] == b[r-1]) r--;
	bool ok=1;
	l++;r--;
	int i=l,j=r;
	while(i<=r)
	{
		if(a[i]!=b[j]) {ok=0;break;}
		i++;j--;
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}