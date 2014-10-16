/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11342  C++  "Math" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 50010;

struct square {
	int a;
	int b;
	int ab;
} s[maxn];

int ans[3];

bool psquare(int n) {
   if(n < 0) return false;
	int x = (int)sqrt(n);
	return n == x*x;
}

int main(int argc, char *argv[]) {

	int k = 0;
	for(int i = 0; i < 230; ++i) {
		for(int j = i; j < 230; ++j) {
		if(k >= maxn) break;
			s[k].a = i;
			s[k].b = j;
			s[k].ab = i*i + j*j;
			k++;
		}
	}
	
	int TC, n, found;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d",&n);
		found=0;
		for(int i = 0; i < k; ++i) {
			if(psquare(n-s[i].ab)) {
				int c = (int)sqrt(n-s[i].ab);
				if(s[i].ab + c == n) {
					ans[0] = s[i].a;
					ans[1] = s[i].b;
					ans[2] = c;
					sort(ans,ans+3);
					found=1;
					printf("%d %d %d\n",ans[0],ans[1],ans[2]);
					break;
				}
			}
		}
		if(!found) printf("-1\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

