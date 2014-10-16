/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  160  C++  "Factorial, Prime Factors, Simple Math" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <bitset>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 100;

int prime[maxn+2];
int factors[maxn+2];

void sieve(int n) {
   memset(prime,0,sizeof(prime));
   prime[0]=1;
   prime[1]=1;
   int m = (int)sqrt(n);
   for (int i=2; i<=m; i++)
      if (!prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=1;
} 

int main() {
	int n, maxp, c;
	sieve(maxn);
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		memset(factors,0,sizeof(factors));
		maxp=0;
		printf("%3d! =",n);		
		for(int i = 1; i <= n; ++i) {
			int m = i;
			for(int j = 2; j <= maxn; ++j) {
				if(!prime[j]) { // !prime (means is prime)
					while(m % j == 0) {
						factors[j]++;
						m /= j;
						if(j > maxp) maxp = j;
					}
				}
			}
		}
		c = 0;
		for(int i = 2; i <= maxp; ++i) {
			if(c==15) {
				printf("\n      ");
				c=0;
			}
			if(factors[i]) {
				putchar(' ');
				printf("%2d",factors[i]);
				c++;
			}
		}
		putchar('\n');	
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
