#include <cstdio>
#include <iostream>
using namespace std;
int n,k,m,i,x,tot;
int main()
{
cin>>n>>k;
for (i=1;i<=n;i++)
{
cin>>x;tot=1;
while (x!=0)
{
tot++;
cin>>x;
}
if (tot>k) m++;
}
cout<<m<<endl;
    return 0;
}