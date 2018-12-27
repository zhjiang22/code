#include<bits/stdc++.h>
using namespace std;

const int MAXN=2005;
int a[MAXN];
int n,r;

void init(){
	cin>>n>>r;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

void work(){
	int ans=0;
	sort(a+1,a+n+1);
	int cur=0;
	for(int i=1;i<=n;i++){
		while(a[i]){
			if(a[i]<=(r-cur)){
				cur+=a[i];	a[i]=0;
				if(cur==r)	cur=0,ans++;
			}
			else	if(a[i]-(r-cur)>=2||a[i]-(r-cur)==0){
				a[i]-=r-cur;	cur=0;
				ans++;
			}
			else{
				a[i]=2;
				ans++;	cur=0;				
			}
		}
	}
	if(cur)	ans++;
	printf("%d\n",ans);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	work();
	fclose(stdin);	fclose(stdout);
	return 0;
}
     