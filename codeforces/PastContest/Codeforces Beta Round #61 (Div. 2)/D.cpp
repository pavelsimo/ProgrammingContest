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

const int MAXN = 1002;
bool prime[MAXN];
vector<llong> PF;

void sieve() {
   for(int i = 0; i < MAXN; ++i)
      prime[i] = true;
   prime[0] = prime[1] = false;
   for(int i = 2; i < MAXN; ++i) {
      if(prime[i]) {
         PF.push_back(i);
         for(int j = i + i; j < MAXN; j += i)
            prime[j] = false;
      }
   }
}

typedef long long llong;

int main(int argc, char *argv[]) {
   sieve();
   int n;
   cin >> n;
   if(n == 2) {
      cout << -1 << endl;
   } else {     
      vector<llong> X;
      for(int i = 0; i < n; ++i) {
         llong prod = 1LL;
         for(int j = i, k = 0; k < 2 && j < sz(PF); ++j, ++k)
            prod *= PF[j];
         X.push_back(prod);
      }
      for(int i = 0; i < n; ++i) {
         for(int j = i + 2; j < n; ++j) 
            X[j] *= PF[i];
      }
      for(int i = 0; i < n; ++i)
         cout << X[i] << endl;
   }
   return 0;
}

 
