#include <cstring>
#include "a.h"
int parseBinary(const char * const binaryString) 
{
	int l=strlen(binaryString);
	int i;
	int cur=1;
	int ans=0;
	for(i=l-1;i>=0;i--)
	{
		ans+=cur*(binaryString[i]-'0');
		cur<<=1;
	}
	return ans;
}