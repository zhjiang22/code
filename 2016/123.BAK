#include<stdio.h>
#include<time.h>
int a[10000],p[100];
void pai(int n,int a[],int p[],int cur)
{
	int i,j;
	if(cur==n)
	{
for(i=0;i<n;i++)
printf("%d",a[i]);
printf("\n");
}
else if(!i||p[i]!=p[i-1]){
for(i=0;i<n;i++)
{
int c1=0,c2=0;
for(j=0;j<cur;j++) {if(a[j]==p[i]) c1++;}
for(j=0;j<n;j++) {if(p[i]==p[j]) c2++;}
if(c1<c2)
{
a[cur]=p[i];
pai(n,a,p,cur+1);
}
	}}
}
int main()
{
int n,o;
scanf("%d",&n);
for(o=0;o<n;o++)
scanf("%d",&p[o]);
pai(n,a,p,0);
printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
return 0;
}
