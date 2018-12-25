#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;

int main()
{
	int n,x;
	while(cin>>n&&n!=0)
	{
		if(n==1)
		{
			cin>>x;
			q.push(x);
		}
		else	if(n==2)
		{
			q.pop();
		}
		else 	if(n==3)
			cout<<q.top();
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}