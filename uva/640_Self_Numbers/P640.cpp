/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  640  C++  "Number Theory" */
#include <iostream>
#include <cstring> 
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 1000000;
int vis[1000010];

int main(int argc, char *argv[]) {
	memset(vis,0,sizeof(vis));
	int sum,x;
	for(int i = 1; i <= maxn; ++i) {
		x=i;
		sum=0; 
		while(x>0) {
			sum+=x%10;
			x/=10;
		}
		if(sum+i <= maxn)
			vis[sum+i]=1;
	}
	for(int i = 1; i <= maxn; ++i) {
		if(!vis[i])
			printf("%d\n",i);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

