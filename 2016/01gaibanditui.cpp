#include<iostream>                                       
#include<cstring>                                        
#include<algorithm>                                      
using namespace std;                                     
                                                         
int T,n;                                                 
int f[100][100];   
int w[100],t[100];                                                                          
                                                  
int main()                                               
{                                                        
	memset(f,0,sizeof(f));                                  
	cin>>n>>T;      
	for(int i=1;i<=n;i++)
		cin>>t[i]>>w[i];                                       
	for(int i=1;i<=n;i++)
	{	
		for(int j=0;j<=T;j++)
		{
		f[i][j]=(i==1?0:f[i-1][j]);
		if(j>=t[i])	f[i][j]=max(f[i][j],f[i-1][j-t[i]]+w[i]*j);
		}
	}                             
	cout<<f[n][T]<<endl;   
	return 0;                                               
}                                                        