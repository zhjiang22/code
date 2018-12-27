//题目没有说明有多组数据，特别坑
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int x;
	Node *nxt;
	Node()
	{
		x=0;	nxt=NULL;
	}
};
int n,m;
Node *front,*rear;
Node *cur;

void Add(const int& x)
{
	Node* p=new Node;
	p->x=x;	
	p->nxt=cur->nxt;	cur->nxt=p;
	cur=p;
}

void print(Node *front)
{
	Node* cur=front;
	while(cur->nxt!=NULL)
	{
		if(cur->nxt->nxt!=NULL)
			printf("%d ",cur->x);
		else
			printf("%d",cur->x);
		cur=cur->nxt;
	}
}

int ans=0;

void Delete(const int& x)
{
	Node* cur=front->nxt;
	Node* Last=front;
	while(cur->nxt!=NULL)
	{
		if(cur->x==x)
		{
			Last->nxt=cur->nxt;
			delete cur;
			cur=Last->nxt;
			ans++;
		}
		else
		{
			cur=cur->nxt;
			Last=Last->nxt;
		}
	}
}

void init()
{
	int x;
	printf("%d\n",n);
	ans=0;
	front=new Node;	rear=new Node;
	front->nxt=rear;
	cur=front;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		Add(x);
	}
}

void work()
{
	print(front->nxt);
	printf("\n");
	cin>>m;
	Delete(m);
	printf("%d\n",n-ans);
	print(front->nxt);
	printf("\n");
	
}

int main()
{
	while(cin>>n)
	{
		init();
		work();
	}
	return 0;
}
     