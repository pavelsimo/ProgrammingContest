/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11849  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	int n,m,x,ans;
   while(scanf("%d%d",&n,&m)==2) {
		if(n==0 && m==0) break;
		set<int> jack;
		ans=0;
		for(int i = 0; i < n; ++i) {
			scanf("%d",&x);
			jack.insert(x);
		}
		for(int i = 0; i < m; ++i) {
			scanf("%d",&x);
			if(jack.count(x)>0)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

