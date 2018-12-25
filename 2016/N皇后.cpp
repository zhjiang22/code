#include<iostream>
#include <cstring>
using namespace std;

const int MAXN=10000;
int c[MAXN];
int vis[4][MAXN],n,cur;

void search(int cur)
{
 	 if(cur==n)
	  {
	   		   for(int i=0;i<n;i++)
				  cout<<c[i];
				  cout<<endl;
	  }
	  else
	  	
	  {
	   	  for(int i=0;i<n;i++)
			 {
			  	  if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n])
					{
					 											  c[cur]=i;
												          		  vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
																  search(cur+1);  
														    	  vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
                    }
			 }
      }
} 

int main()
{
	cin>>n;
	memset(c,0,sizeof(c));
	memset(vis,0,sizeof(vis));
	search(0);
	return 0;
}
