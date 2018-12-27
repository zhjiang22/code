#include <cstdio>
#include <cstdlib>
using namespace std;

int Ns[]={3,5,7,10,100,100,100,100,100,100};
int Ms[]={2,10,50,80,80,100,100,100,100,100};
int Ts[]={3,5,7,9,11,1,10,20,64,64};

void make(int n,int m,int t){
	freopen("life.in","w",stdout);
	printf("%d %d %d\n",m,n,t);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
			putchar('0'+rand()%2);
		putchar('\n');
	}
	fclose(stdout);
}

main(){
	for(int i=0;i<10;++i){
		make(Ns[i],Ms[i],Ts[i]);
		char s[256];
		sprintf(s,"life && rename life.in life%d.in && rename life.out life%d.out",i,i);
		system(s);
	}
}
