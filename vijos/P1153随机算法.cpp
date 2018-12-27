#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#define maxn 200
#define INF 2000000000
long n,blood[maxn+10];
int main()
{
long i,ans_one,ans_two,ans,here,tmp;
long which,lim[2],number[2],quantity[2];
scanf("%ld",&n);
for(i=1;i<=n;++i)
scanf("%ld",&blood[i]);
srand(time(0));
lim[0]=n/2;
lim[1]=n-lim[0];
ans=INF;
while(clock()<900)
{
quantity[0]=quantity[1]=number[0]=number[1]=0;
for(i=1;i<=n;++i)
{
which=rand()%2;
if(number[which]==lim[which]) which=(which+1)%2;
++number[which];
quantity[which]+=blood[i];
}
assert(number[0]<=lim[0] && number[1]<=lim[1]);
if(quantity[0]>quantity[1])
tmp=quantity[0],quantity[0]=quantity[1],quantity[1]=tmp;
here=quantity[1]-quantity[0];
if(here<ans)
ans=here,ans_one=quantity[0],ans_two=quantity[1];
}
printf("%ld %ld\n",ans_one,ans_two);
return 0;
}