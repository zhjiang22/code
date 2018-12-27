#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
string a,b;
int n;
int t;

void init(){
	cin>>n;
	cin>>a;	cin>>b;
}

void work(){
	char last=0;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]){
			last=a[i];
			break;
		}
	for(int i=n-1;i>=0;i--)
		if(a[i]!=b[i]){
			if(b[i]!=last){
				printf("NO\n");
				return;
			}
			last=a[i];
		}
	printf("YES\n");
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     