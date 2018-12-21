#include<cstdio>
int n,root;
int o[2009][2009],oo[2009][2009],p[2009],d[2009];
int q[2009],qh,qt;
void pu(int x){
	qt++;
	q[qt]=x;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	int m,x,flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			scanf("%d",&x);
			o[i][x]=1;
			d[x]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			if(root==0)flag=1;
			else flag=0;
			root=i;
		}
	}
	if(flag)pu(root);
	while(qh<qt){
		qh++;
		for(int i=1;i<=n;i++)if(o[q[qh]][i]){
			d[i]--;
			if(d[i]==0){
				p[i]=q[qh];
				pu(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		x=i;
		while(x!=0&&x!=root)x=p[x],oo[x][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(o[i][j]!=oo[i][j])flag=0;
		if(!flag)break;	
	}
	if(flag){
		printf("YES\n");
		for(int i=1;i<=n;i++){
			if(i!=root) printf("%d %d\n",p[i],i);
		}
	}
	else printf("NO\n");
	return 0;
}