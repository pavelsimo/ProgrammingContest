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

const int MAXN = 202;
typedef long long llong;

#define BITCOUNT(mask) ( __builtin_popcountll((mask)) )

int main(int argc, char *argv[]) { 
  int TC;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    vector<llong> outlets;
    vector<llong> devices;
    
    string X;
    int N, L;
    
    cin >> N >> L;
  
    for(int i = 0; i < N; ++i) {
      cin >> X;
      llong bin = 0;
      for(int j = 0; j < L; ++j) {
        if(X[j] == '1') bin += ((llong) 1LL << (L - j - 1LL));
      }
      outlets.push_back(bin);
    }

    for(int i = 0; i < N; ++i) {
      cin >> X;
      llong bin = 0;
      for(int j = 0; j < L; ++j) {
        if(X[j] == '1') bin += (1LL << ((llong) L - j - 1LL));
      }
      devices.push_back(bin);
    }
        
    
    int ans = 2*L;
    set<llong> S;
    
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        llong mask = outlets[i] ^ devices[j];
        S.insert(mask);
      }
    }
    
    foreach(it, S) {
      llong cur_mask = *it;
      set<llong> dset(devices.begin(), devices.end());
      for(int i = 0; i < N; ++i) {
        dset.erase(cur_mask ^ outlets[i]);
      }
      if(dset.empty()) {
        ans = min(ans, BITCOUNT(cur_mask));
      }
    }
    
    printf("Case #%d: ", tc);
    if (ans == 2*L) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
