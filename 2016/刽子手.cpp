#include<iostream>
#include<cstring>
using namespace std;

char a[100],b[100];
int lef,chance;
int win,lose;

void guess(char ch)
{
	int bad=1;
	for(int i=0;i<strlen(a);i++)
	if(a[i]==ch){ lef--; a[i]=' ';bad=0;}
			if(bad) 		--chance;
	if(!chance)		lose=1;
	if(!lef)  		win=1;
}


int main()
{
	int rnd;
	while(cin>>rnd&&rnd!=-1)
	{
		cin>>a;
		cin>>b;
		cout<<"Round "<<rnd<<endl;
		win=lose=0;
		lef=strlen(a);
		chance=7;
		for(int i=0;i<strlen(b);i++)
		{
			guess(b[i]);
			if(win||lose)
			break;			
		}
		if(win) cout<<"You win."<<endl;
		else if(lose) cout<<"You lose."<<endl;
		else cout<<"You chickened out."<<endl;
	}
	return 0;
}
