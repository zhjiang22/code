#include<stdio.h>
int main()
{
int D,I,j,k=1;
while((scanf("%d%d",&D,&I))==2)
{
printf("ok");
for(j=0;j<D-1;j++)
if(I%2)
{
k=k*2;
I=(I+1)/2;
}
else
{
k=k*2+1;
I/=2;
}
printf("%d\n",k);
k=1;
}
return 0;
}
