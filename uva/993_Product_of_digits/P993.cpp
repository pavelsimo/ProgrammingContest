/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  993  C++  "Math, Prime Factor" */
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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

const int MAXP = 33622;
vector<bool> P;
vector<int> primes;

void sieve() {
   P = vector<bool>(MAXP + 2, true);
   P[0] = P[1] = false;
   for(int i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(int j = i * i; j <= MAXP; j+=i) 
            P[j] = false;
      }
   }
}

char buf[32];

int main(int argc, char *argv[]) {
   sieve();
   int TC, n;
   string res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      vector<int> pf;
      scanf("%d",&n);
      int x = n;
      if(x >= 10) {
         while(x % 9 == 0) pf.push_back(9), x/=9;
         while(x % 8 == 0) pf.push_back(8), x/=8;
         while(x % 6 == 0) pf.push_back(6), x/=6;
         while(x % 4 == 0) pf.push_back(4), x/=4;
         for(int i = 0; primes[i]*primes[i] <= x && i < sz(primes); ++i) {
            while(x % primes[i] == 0) {
               pf.push_back(primes[i]);
               x/=primes[i];  
            }
         }
         if(x > 1) pf.push_back(x);
         sort(all(pf));
         res = "";
         for(int i = 0; i < sz(pf); ++i) {
            if(pf[i] > 9) {
               res = "-1";
               break;
            }
            sprintf(buf,"%d",pf[i]);
            res+=buf;
         }
         puts(res.c_str());  
      } else {
         printf("%d\n",n);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
