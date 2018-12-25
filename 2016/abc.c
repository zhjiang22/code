#include<stdio.h>
int main()
{
int i,j,k,fghij,n,abcde;
char a[13];
printf("please enter n");
scanf("%d",&n);
for(fghij=1000;fghij<=100000;i++)
{
abcde=n*fghij;
scanf(a,"%d%d",abcde,fghij);
for(i=0;i<sizeof(a)-1;i++)
{
for(j=i+1;j<sizeof(a);j++)
if(a[i]==a[j]) {k=0; break;}
else k=1;
}
if(k)
printf("%d/%d=%d\n",abcde,fghij,n);
}
return 0;
}
