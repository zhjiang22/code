#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

char n[10000];

int main()
{
	double m;
	long long s=0;
	gets(n);
	cin>>m;
	int len=strlen(n);
    for(int i=len-1;i>=0;i--)
{if(n[i]=='0') s+=0*pow(m,len-i-1);
if(n[i]=='1') s+=1*pow(m,len-i-1);
if(n[i]=='2') s+=2*pow(m,len-i-1);
if(n[i]=='3') s+=3*pow(m,len-i-1);
if(n[i]=='4') s+=4*pow(m,len-i-1);
if(n[i]=='5') s+=5*pow(m,len-i-1);
if(n[i]=='6') s+=6*pow(m,len-i-1);
if(n[i]=='7') s+=7*pow(m,len-i-1);
if(n[i]=='8') s+=8*pow(m,len-i-1);
if(n[i]=='9') s+=9*pow(m,len-i-1);
if(n[i]=='A') s+=10*pow(m,len-i-1);
if(n[i]=='B') s+=11*pow(m,len-i-1);
if(n[i]=='C') s+=12*pow(m,len-i-1);
if(n[i]=='D') s+=13*pow(m,len-i-1);
if(n[i]=='E') s+=14*pow(m,len-i-1);
if(n[i]=='F') s+=15*pow(m,len-i-1);
if(n[i]=='G') s+=16*pow(m,len-i-1);
    }
    cout<<s;
}

