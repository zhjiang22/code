#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> q;
stack<int> s;

int main()
{
	int n;
	q.push(1);
	q.push(2);
	q.push(3);
	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}

	s.push(1);
	s.push(2);
	s.push(3);
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	system("pause");
	return 0;
}
     