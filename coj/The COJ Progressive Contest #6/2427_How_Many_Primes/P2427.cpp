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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

const int MAXN = 1000202;
bool P[MAXN];
int DP[MAXN];

void sieve() {
   memset(DP, 0, sizeof(DP));
   for(int i = 0; i < MAXN; ++i)
      P[i] = true;
   P[0] = false;
   P[1] = false;
   for(int i = 2; i < MAXN; ++i) {
      if(P[i]) {
         for(int j = i + i; j < MAXN; j+=i) 
            P[j] = false;
      }
   }
   DP[0] = DP[1] = 0;
   for(int i = 2; i < MAXN; ++i) {
      DP[i] = DP[i-1];
      if(P[i]) ++DP[i];
   }
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   sieve();
   int a, b;
   while(cin >> a >> b) {
      if(!a && !b) break;
      cout << DP[b] - DP[a - 1] << endl;
   }
   return 0;
}
