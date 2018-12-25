#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int mm=201;
char a[mm][mm];
int cmp(char *a,char *b)
{
 	if(strlen(a)>strlen(b))
 	return 1;
 	else if(strlen(a)<strlen(b))
 	return 0;
 	else
 	{
	 	if(strcmp(a,b)>=0)
	 	return 1;
	 	else
	 	return 0;
    }
}

    int main()
{
    int n;
    char b[205];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    if(cmp(a[i],a[j]))
    {
	 				  strcpy(b,a[i]);
	 				  strcpy(a[i],a[j]);
	 				  strcpy(a[j],b);
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
    system("pause");
    return 0;
}
