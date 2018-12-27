#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=1e5;
char a[MAXN];
int n;

void init(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

void work(){
	int front=1,rear=n;
	for(int i=1;i<=n;i++){
		int l=front,r=rear;
		while(a[l]==a[r]&&l<=r)	l++,r--;
		if(a[l]<a[r])
			putchar(a[front++]);
		else
			putchar(a[rear--]);
		if(i%80==0)	putchar('\n');
	}
}

int main(){
	init();
	work();
	return 0;
}
     