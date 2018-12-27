#include<bits/stdc++.h>
using namespace std;

const int MAXN=15;
struct Student
{
	int a,b,c;
}s[MAXN];
set<string> Set;
int Case;
int OK;
int n;
string stu;

void init(){
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
}

bool pre_work(){
	stu.clear();
	for(int i=1;i<=n;i++)
		stu+=s[i].c+'0';
	if(Set.count(stu))	return 0;
	Set.insert(stu);	return 1;
}

bool doit(int& t){
	if(!pre_work())	return 0;
	int sleep=0,wake=0;
	for(int i=1;i<=n;i++)
		if(s[i].c<=s[i].a)	wake++;
		else	sleep++;
	if(wake==n){
		OK=1;	return 0;
	}
	if(wake>=sleep){
		int k=0;
		for(int i=1;i<=n;i++)
			if(s[i].c>s[i].a)
				k=max(k,s[i].a+s[i].b+1-s[i].c);
		t+=k;	OK=1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s[i].c++;
		if(s[i].c==s[i].a+s[i].b+1)	s[i].c=1;
	}
	return 1;
}

void work(){
	int t=0;	OK=0;
	Set.clear();
	while(doit(++t))	;
	if(OK)	printf("Case %d: %d\n",++Case,t);
	else	printf("Case %d: -1\n",++Case);
}

int main(){
	while(scanf("%d",&n)&&n){
		init();
		work();
	}
	return 0;
}
     