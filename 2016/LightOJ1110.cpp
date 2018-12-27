#include<bits/stdc++.h>
using namespace std;

const int MAXN=105;
int f[MAXN][MAXN];
string a,b;
int Case;
int n,m;
int t;

void init(){
	cin>>a>>b;
	n=a.length();	m=b.length();
	memset(f,0,sizeof(f));
}

string s[MAXN][MAXN];

void work(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i-1]==b[j-1]){
				f[i][j]=f[i-1][j-1]+1;
				s[i][j]=s[i-1][j-1]+a[i-1];
			}
			else	if(f[i-1][j]>f[i][j-1]){
				f[i][j]=f[i-1][j];
				s[i][j]=s[i-1][j];
			}
			else	if(f[i][j-1]>f[i-1][j]){
				f[i][j]=f[i][j-1];
				s[i][j]=s[i][j-1];
			}
			else{
				f[i][j]=f[i-1][j];
				s[i][j]=min(s[i-1][j],s[i][j-1]);
			}
	if(s[n][m]=="")    printf("Case %d: :(\n",++Case);
	else    printf("Case %d: ",++Case),cout<<s[n][m]<<endl;
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     