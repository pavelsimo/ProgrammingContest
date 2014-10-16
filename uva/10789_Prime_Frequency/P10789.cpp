/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10789  C++  "Ad Hoc, Prime Numbers" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int maxn = 3000;
char buf[2048];
int f[260];
int prime[maxn+2];

void sieve(int n) {
   for(int i = 0; i <= n; ++i) prime[i] = 1;
   prime[0]=0;
   prime[1]=0;
   int m = (int)sqrt(n);
   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=0;
} 

int main(int argc, char *argv[]) {
	sieve(maxn);
	int TC, n, found;
	scanf("%d\n",&TC);
	for(int tc=1; tc <= TC; ++tc) {
		gets(buf);
		n = strlen(buf);
		memset(f,0,sizeof(f));
		for(int i = 0; i < n; ++i) f[buf[i]]++;
		found = 0;
		printf("Case %d: ",tc);
		for(int i = 0; i <= 255; ++i) {
			if(prime[f[i]]) {
				found = 1;
				printf("%c",i);
			}
		}
		if(!found)
			printf("empty");
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
