#include<iostream>
#include <cstdio>
#include<cstring>
using namespace std;
int v[33][33],mem[33][33];
unsigned int N,L,i;
int dp(int len,int count){
    int& ans=mem[len][count];
    if(v[len][count]) return ans;
    v[len][count]=1;
    if(count==0||len==0) return ans=1;
    return ans=dp(len-1,count)+dp(len-1,count-1);
}
int main()
{
	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\out.txt","w",stdout);
  memset(v,0,sizeof(v));
  cin>>N>>L>>i;
  for(int j=N-1;j>=0;j--){
    if(dp(j,L)<i){
      cout<<1;
      i-=dp(j,L);
        L--;
    }else{
      cout<<0;
    }
  }
  return 0;
}