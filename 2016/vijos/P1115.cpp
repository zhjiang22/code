#include <iostream> 
#include <algorithm>
using namespace std; 
int n,m,martian[10001]; 

void print()  
{
  for(int i=0;i<n-1;i++) 
    cout<<martian[i]<<' '; 
  cout<<martian[n-1]<<"\n";   
}

int main()   
{   
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>martian[i];
  for(int i=1;i<=m;i++)
    next_permutation(martian,martian+n);     
  print();
  return 0; 
}