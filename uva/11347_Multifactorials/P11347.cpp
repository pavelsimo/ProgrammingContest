/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11347  C++  "Math, Prime Factor" */
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

const int MAXP = 32;
const llong MAXN = 1000000000000000000LL;
vector<bool> P;
vector<int> primes;

void sieve() {
   P = vector<bool>(MAXP + 10, true);
   P[0] = P[1] = false;
   for(int i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(int j = i * i; j <= MAXP; j+=i) {
            P[j] = false;
         }
      }
   }
}

char buf[256];
llong freq[1024];
llong solve(int n, int k) {
   memset(freq,0,sizeof(freq));
   llong res = 1LL;
   int m = (n % k == 0) ? k : (n % k);
   for(int i = n; i >= m; i-=k) {
      int x = i;
      for(int j = 0; primes[j]*primes[j] <= x && j < sz(primes); ++j) {
         while(x % primes[j] == 0) {
            freq[primes[j]]++;
            x/=primes[j];  
         }
      }
      if(x > 1) freq[x]++;     
   }
   for(int i = 2; i <= n; ++i) {
      if(res > MAXN) return 0;
      res*=(freq[i] + 1LL);
   }
   return res;
}

int main(int argc, char *argv[]) {
   sieve();
   llong res;
   int TC, n, k;
   string buf;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      getline(cin,buf);
      k = count(all(buf),'!');
      sscanf(buf.substr(0,buf.find('!')).c_str(),"%d",&n);
      res = solve(n, k);
      printf("Case %d: ",tc);
      if(res > 0) printf("%lld\n",res);
      else puts("Infinity");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
