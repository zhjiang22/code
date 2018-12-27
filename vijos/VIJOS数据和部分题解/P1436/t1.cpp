#include<cstdio>
main()
{freopen("t110.in","r",stdin);
freopen("t110.out","w",stdout);
int i,n,nn,t=0,a,b,c,d,e=0,kk;
char aa[257];
float k=1.00;
long long s=0;
scanf("%d",&n);
nn=n;
while(nn>1)
{nn/=2;t++;}
for(i=1;i<=t;i++)
{scanf("%d%d%d",&a,&b,&c);
k=k*a*b*c/1000000;
}
k*=100;
for(i=1;i<=t;i++)
{scanf("%d%d%d%d",&a,&b,&c,&d);
e+=a*b*c*d/1000000+d;
}
scanf("%d",&nn);
getchar();
for(i=1;i<=nn+1;i++)
{aa[i]=getchar();aa[i]-='0';}
a=b=c=0;
kk=nn;
while(e!=0&&aa[1]!=0)
{a=e%10;
b=aa[kk];
aa[kk]=(a+b+c)%10;
c=(a+b+c)/10;
kk--;
e/=10;
}
printf("%.2f\n",k);
if(c==1)
{printf("1");
for(i=1;i<=nn+1;i++)
{aa[i]+='0';printf("%c",aa[i]);}
}
else
for(i=1;i<=nn+1;i++)
{aa[i]+='0';printf("%c",aa[i]);}
}
