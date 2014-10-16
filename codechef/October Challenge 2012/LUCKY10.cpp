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

int freq[2][10];
int id[2][8] = {{6,5,3,2,1,0,4,7},{3,2,1,0,4}};

void go(int n, int from, int to) {
   int k = (n == 7) ? 0: 1;
   int m = (n == 7) ? 8: 5;
   while(true) {
      bool done = true;
      if(freq[from][n] > 0) {
         for(int i = 0; i < m; ++i) {
            int mi = min(freq[to][id[k][i]], freq[from][n]);
            for(int j = 0; j < mi; ++j) {
               cout << n;
               done = false;
            }
            freq[to][id[k][i]] -= mi;
            freq[from][n] -= mi;
         }
      }
      if(done) break;
   }
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   string S[2];
   cin >> TC;
   while(TC-- > 0) {
      memset(freq, 0, sizeof(freq));
      cin >> S[0] >> S[1];
      for(int k = 0; k < 2; ++k) {
         for(int i = 0; i < sz(S[k]); ++i) {
            freq[k][S[k][i] - '0']++;
         }         
      }
      go(7, 0, 1);
      go(7, 1, 0);
      go(4, 0, 1);
      go(4, 1, 0);
      cout << endl;
   }
   return 0;
}

