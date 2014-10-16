#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

llong to_decimal(int bin) {
   llong res = 0;
   for(int i = 11; i >= 0; --i)
      res = res * 10 + ((bin & (1 << i)) ? 1: 0);
   return res;
}

int main(int argc, char *argv[]) {
   llong n, res = 0;
   cin >> n;
   for(int i = 1; i < (1 << 12); ++i) {
      llong x = to_decimal(i);
      if(x <= n) res++;
   }
   cout << res << endl;
   return 0;
}

