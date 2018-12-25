#include<stdio.h>
#include<stdlib.h>
#define ELEMTP int
struct node
{ELEMTP data;
struct node*lc,*rc;
}*root;
int m=0;

struct node *creat()
{
struct node *t,*q,*s[6];
int i,j,x;
printf("qing yi kongge fenge");
printf("i,x=");
scanf("%d %d",&i,&x);
while((i!=0)&&(x!=0))
{q=(struct node *)malloc(sizeof(struct node));
q->data=x; q->lc=NULL; q->rc=NULL; s[i]=q;
if(i=1) t=q;
else {j=i/2;
if((i%2)==0) s[j]->lc=q;
else s[j]->rc=q;
}
printf("i,x=");
scanf("%d %d",&i,&x);
}
return(t);
}

void preorderz(struct node *p)
{
if(p!=NULL)
{
printf("%d",p->data);
preorderz(p->lc);
preorderz(p->rc);
}
}

void inorder(struct node *p)
{
if(p!=NULL)
{
inorder(p->lc);
printf("%d",p->data);
inorder(p->rc);
}
}

void postorder(struct node *p)
{
if(p!=NULL)
{
postorder(p->lc);
postorder(p->rc);
printf("%d",p->data);
}
}

int main()
{
int a;
printf("\nMenu\n1creat\n2xianxu\n3zhongxu\n4houxu\n5exit\n");
do
{
printf("please choose");
scanf("%d",&a);
switch(a)
{
case 1:{
root=creat();
printf("jianli ok");
}break;
case2:{
preorderz(root);
printf("\nxianxu ok");
}break;
case3:{
inorder(root);
printf("\nzhongxu ok");
}break;
case 4:{
postorder(root);
printf("\n houxu ok");
}break;
case 5:
{exit(0);}
break;
}
}while(a<=5);
}
