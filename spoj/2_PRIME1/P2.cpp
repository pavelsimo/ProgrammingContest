/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PRIME1 C++ "Graph Theory" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

vector<int> primes;
const int MAXN = 32000;
bool p[MAXN];

void sieve(int N) {
   memset(p,false,sizeof(p));
   for(int i = 0; i < N; ++i)
      p[i] = true;
   p[0] = false;
   p[1] = false;
   for(int i = 2; i < N; ++i) {
      if(p[i]) {
         primes.push_back(i);
         for(int j = i*i; j < N; j+=i) 
            p[j] = false;
      }
   }
}

int main(int argc, char *argv[]) {  
   int TC, n, m, res;
   sieve(MAXN);
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&m,&n);
      for(int i = m; i <= n; ++i) {
         bool isprime = true; 
         if(i==1) continue;
         for(int j = 2; j*j <= i; ++j) {
            if(p[j]) {
               if(i%j==0) {
                  isprime = false;
                  break;
               }
            }
         }
         if(isprime) printf("%d\n",i);
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
