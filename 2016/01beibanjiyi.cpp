#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int T,n;
int f[100],d[100]={0};
int t[100],w[100]; 	
                   
int dp(int s)
{
	if(f[s]>0)
	return f[s];
 	f[s]=0;
 	for(int i=1;i<=n;i++)
 	if(s>=t[i]&&!d[i])
  	{
  		d[i]=1;
	  f[s]=max(f[s],dp(s-t[i])+w[i]*s);
  	}
  	return f[s];
}

int main()
{
	memset(f,0,sizeof(f));
	cin>>n>>T;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>w[i];
	dp(T);
	cout<<f[T];
	return 0;
}