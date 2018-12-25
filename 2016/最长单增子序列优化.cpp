#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

int a[50002];
int Long[50002];
int Max=1,n;

int find(int key)
{
  int l=1,r=Max;
  while(l<=r)
  {
    int mid=(l+r)>>1;
    if(a[Long[mid]]<key)
      l=mid+1;
    else
      r=mid-1;
  }
  return l-1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
   {
    Max=1;cin>>n;
      for(int i=1;i<=n;i++)
       cin>>a[i];
     Long[Max]=1;
     for(int i=2;i<=n;i++)
     {
       if(a[i]>a[Long[Max]])
       {
         Max++;
         Long[Max]=i;
       }
       else
       {
         int l=find(a[i]);
         Long[l+1]=i;
       }
     }
     cout<<Max<<endl;}
  return 0;
}
     