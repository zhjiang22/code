#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=10;
int p[MAXN];

int main()
{
 	int n;
 	cin>>n;
 	for(int i=0;i<n;i++)
 	cin>>p[i];
 	sort(p,p+n);
 	do
 	{
	  			for(int i=0;i<n;i++)
	  			cout<<p[i];
                cout<<endl;
    }
    while(next_permutation(p,p+n));
    system("pause");
    return 0;
}
	  			
 	 
