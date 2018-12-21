#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==21) printf("1\n");
	else if(n>=30 && n<=40) printf("2\n");
	else if(n<21) printf("-1\n");
	else
	{
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			if(n-i*14 >= 30 && n-i*14 <=40) {printf("%d\n",i+2);ok=1;break;}
		}
		if(!ok) printf("-1\n");

	}
	return 0;
}