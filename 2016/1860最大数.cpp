#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string nu[25];

int cmp(string a,string b)
{
return a+b>b+a;
}

int main()
{
int n,i,j;
cin>>n;
for(i=0;i<n;i++) cin>>nu[i];
sort(nu,nu+n,cmp);
for(i=0;i<n;i++) cout<<nu[i];
cout<<endl;
return 0;
}
