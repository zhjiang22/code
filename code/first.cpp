#include<cstdio>
#define ma(i,j) map[(i-1)*m+j-1]
int n,m,d;
int sx,sy,fx,fy;
int map[400009];
int qx[400009],qy[400009],qv[400009],qh,qt;
void pu(int x,int y,int v){
	if(ma(x,y)==0&&x>0&&y>0&&x<=n&&y<=m){
		qt++;
		qx[qt]=x;
		qy[qt]=y;
		qv[qt]=v;
//		printf("%d %d %d\n",x,y,v);
		ma(x,y)=1;
	}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&d);
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c=getchar();
			while(c!='S'&&c!='F'&&c!='M'&&c!='.')c=getchar();
			if(c=='S')sx=i,sy=j;
			if(c=='F')fx=i,fy=j;
			if(c=='M')pu(i,j,d);
		}
	}
//	printf("%d %d %d %d\n",sx,sy,fx,fy);
	while(qh<qt){
		qh++;
		if(qv[qh]>0){
			pu(qx[qh],qy[qh]+1,qv[qh]-1);
			pu(qx[qh],qy[qh]-1,qv[qh]-1);
			pu(qx[qh]+1,qy[qh],qv[qh]-1);
			pu(qx[qh]-1,qy[qh],qv[qh]-1);
		}
	}
	qh=qt=0;
	pu(sx,sy,0);
	int flag=0;
	while(qh<qt){
		qh++;
		if(qx[qh]==fx&&qy[qh]==fy){
			flag=1;
			break;
		}
		pu(qx[qh],qy[qh]+1,qv[qh]+1);
		pu(qx[qh],qy[qh]-1,qv[qh]+1);
		pu(qx[qh]+1,qy[qh],qv[qh]+1);
		pu(qx[qh]-1,qy[qh],qv[qh]+1);
	}
	if(flag)printf("%d",qv[qh]);
	else printf("-1");
	return 0;
}