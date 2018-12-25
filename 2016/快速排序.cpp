#include<iostream>  
using namespace std;  
void quickSort(int a[],int,int);  
int main()  
{  
    int a[100];
    int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i]; 
    quickSort(a,0,n);  
    cout<<"The sorted arrayare:"<<endl;  
    for(int k=0;k<n;k++)  
        cout<<a[k]<<",";  
    cout<<endl;  
    system("pause");  
    return 0;  
}  
  
void quickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // 递归调用  
        quickSort(s, i + 1, r);  
    }  
}  
