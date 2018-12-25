#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node 
{
	int data;
	struct node* next;
};
typedef struct node* powder;

powder creat()
{
	int dat;
	powder Head,p1,p2;
	Head=new node;
	cout<<"please input number: "<<endl;
	cin>>dat;
	Head->data=dat;
	Head->next=NULL;

	while(1)
	{
		p1=new node;
		if(p1==NULL)
			exit(0);
		cout<<"please input number: "<<endl;
		cin>>dat;
		if(dat==-1)
			return Head;
		p1->data=dat;
		p1->next=Head;
		Head=p1;
	}
	return Head;
}

void print(powder Head)
{
	powder p;
	p=Head;
	if(p==NULL)
    printf("\nempty\n");
  else
    do
    {
       printf("%d ",p->data);
       p=p->next;
    }while(p!=NULL);
}


int main()
{
	powder Head;
	Head=creat();
	print(Head);
	return 0;
}