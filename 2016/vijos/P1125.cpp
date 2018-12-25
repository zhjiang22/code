/*
水题啊
直接做就好了
Orz
果然是考数学的OTZ
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
int cnt;
double H,S,V,L,K;

int main () 
{
    cin>>H>>S>>V>>L>>K>>n;
    double tmax=sqrt(H/5),tmin=sqrt((H-K)/5);
    double x1=S-V*tmax,x2=S-V*tmin+L;
    for (int x=0;x<n;x++) 
        if (x>=x1-0.00001&&x<=x2+0.00001) 
        	cnt++;
    cout<<cnt<<endl;
    return 0;
}