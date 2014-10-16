#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

char buf[256];
int memo[256][256];
int n;

int d(int i, int j) {
	if(memo[i][j]>=0) return memo[i][j];
	int ans=0, isweet=0, isour=0;
	for(int k = i; k < j; ++k) {
		if(buf[k]=='1') isweet++;
		else isour++;
	}
	ans = isweet > isour? j-i: 0;
	for(int k = i+1; k < j; ++k)
		ans = max(ans,d(i,k)+d(k+1,j));
	return memo[i][j] = ans;
}

int main(int argc, char *argv[]) {
   int TC;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		memset(memo,-1,sizeof(memo));
		gets(buf);
		sscanf(buf,"%d",&n);
		gets(buf);
		printf("%d\n",d(0,n));
	}
	return 0;
}
