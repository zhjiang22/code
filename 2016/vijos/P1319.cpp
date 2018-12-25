/*
直接模拟就可以了竟然还想了半天
真是太弱了
还有一种二进制的做法很高大上但是懒得学了
毕竟我太弱
*/
/*
#include <iostream>
#include <cmath>
using namespace std;

long long a[1001];
int n,k,m=1;

int main()
{
      cin>>k>>n;
      for(int i=0;i<1000;i++)
      {
            int t=m;
          	for(int j=0;j<t;j++)
          	{
                a[m]=pow(k,i)+a[j];
                if(m==n)
                {
                   cout<<a[m]<<endl;
                   return 0;
            	}
                else m++;
            }
      }
      return 0;
}
*/
#include<iostream>
using namespace std;

int ans;
int k, N;

int main ()
{
    cin >> k >> N;
    int p = 1;
    for (int i = 0; i < 10; i++) {
        if (N & (1 << i)) ans += p;
        p *= k;
    }
    cout << ans;
    return 0;
}