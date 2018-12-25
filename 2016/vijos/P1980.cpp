#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
typedef long long ll;
typedef double lf;
const int INF=1<<30;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int T,n,ans;
struct state{
	int num[16];
	inline int& operator[](int x){return num[x];}
}now;
int temp[10];
void dfs(int);
void group(int c,int s,int depth){
	for(int st=1,fi;st<=12-s+1;st++){
		for(fi=st;now[fi]>=c&&fi<=12;fi++){
			now[fi]-=c;
			if(fi-st+1>=s)
				dfs(depth+1);
		}
		for(int i=st;i<fi;i++)
			now[i]+=c;
	}
}
void dfs(int depth){
	if(depth>ans)return;
	int sum=0;
	for(int i=1;i<=15;i++)
		temp[now[i]]++;
	while(temp[4]>0){
		temp[4]--,sum++;
		if(temp[2]>=2)
			temp[2]-=2;
		else if(temp[1]>=2)
			temp[1]-=2;
	}
	while(temp[3]>0){
		temp[3]--,sum++;
		if(temp[2]>=1)
			temp[2]--;
		else if(temp[1]>=1)
			temp[1]--;
	}
	sum+=temp[1]+temp[2];
	if(temp[1]>=2&&now[14]>=1&&now[15]>=1)
		sum--;
	temp[1]=temp[2]=0;
	if(depth+sum<ans)
		ans=depth+sum;
	group(1,5,depth);
	group(2,3,depth);
	group(3,2,depth);
}
void work(){
	memset(now.num,0,sizeof now.num);
	ans=1<<30;
	for(int i=1;i<=n;i++){
		int k=read(),c=read();
		if(k==0)
			now[13+c]++;
		else if(k<=2)
			now[11+k]++;
		else
			now[k-2]++;
	}
	dfs(0);
	printf("%d\n",ans);
}
int main(){
	T=read(),n=read();
	for(int turn=1;turn<=T;turn++)
		work();
	return 0;
}
