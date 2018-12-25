/*
直接模拟啊，明天考试
今天撸点水平攒rp23333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int n,k;
int sum;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		sum+=n/2;
		n-=(n/2);
	}
	cout<<sum<<endl;
	return 0;
}
     