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

int main(int argc, char *argv[]) { 
  int TC;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    vector<int> outlets;
    vector<int> devices;
    
    string X;
    int N, L;
    cin >> N >> L;
    
    for(int i = 0; i < N; ++i) {
      cin >> X;
      int bin = 0;
      for(int j = 0; j < L; ++j) {
        int bit = X[j] - '0';
        if(bit) bin += (1 << (L - j - 1));
      }
      //cout << "outlet: "  << bin << endl;
      outlets.push_back(bin);
    }

    for(int i = 0; i < N; ++i) {
      cin >> X;
      int bin = 0;
      for(int j = 0; j < L; ++j) {
        int bit = X[j] - '0';
        if(bit) bin += (1 << (L - j - 1));
      }
      //cout << "device: "  << bin << endl;
      devices.push_back(bin);
    }
    
    sort(outlets.begin(), outlets.end());
    sort(devices.begin(), devices.end());
    
    int ans = L * 2;
    for(int i = 0; i < (1 << L); ++i) {
      vector<int> new_outlets;
      int j;
      for(j = 0; j < N; ++j) {
        int nout = outlets[j] ^ i;
        new_outlets.push_back(nout);
      }
      sort(new_outlets.begin(), new_outlets.end());
      for(j = 0; j < N; ++j) {
        if(new_outlets[j] != devices[j]) break;
      }
      if(j == N) {
        ans = min(ans, __builtin_popcount(i));
      }
    }
    printf("Case #%d: ", tc);
    if (ans == L*2) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
