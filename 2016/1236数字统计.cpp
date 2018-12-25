#include<iostream>
using namespace std;
int z(int x)
{
 	int ans=0;
 	while(x>0)
 	{
	 		   if(x%10==2)
	 		   ans++;
	 		   x/=10;
    }
    return ans;
}
			   
			   
int main()
{
 	int  l,r,m=0;
 	cin>>l>>r;
 	for(int i=l;i<=r;i++)
 	m+=z(i);
    cout<<m;
	system("pause");
	return 0;
}		 
