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
	cur->nxt=p;	p->nxt=cur->nxt;
	cur=p;
}

void print(Node *front)
{
	Node* cur=front;
	while(cur!=NULL)
	{
		printf("%d ",cur->x);
		cur=cur->nxt;
	}
}

void init()
{
	int x;
	cin>>n;
	front=new Node;	rear=new Node;
	front->nxt=rear;
	cur=front;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		Add(x);
	}
	print(front);
}

void work()
{
	
}

int main()
{
	init();
	work();
	return 0;
}
     