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

const int MAXN = 102;

priority_queue<int,vector<int>, greater<int> > I[MAXN];
priority_queue<int> F[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC, n, m, chakra, lvl, res;
   cin >> TC;
   while(TC-- > 0) {
      cin >> n >> m;
      // clean
      for(int i = 0; i < MAXN; ++i) {
         while(!I[i].empty()) I[i].pop();
         while(!F[i].empty()) F[i].pop();
      }
      for(int i = 0; i < n; ++i) {
         cin >> chakra >> lvl;
         I[lvl].push(chakra);
      }
      for(int i = 0; i < m; ++i) {
         cin >> chakra >> lvl;
         F[lvl].push(chakra);
      }
      res = 0;
      for(int l = 1; l <= 100; ++l) {
         while(!I[l].empty() && !F[l].empty()) {
            int ci = I[l].top();
            int cf = F[l].top();
            I[l].pop(); 
            F[l].pop();
            if(ci > cf) {
               I[l].push(ci - cf);
            } else {
               int d = cf - ci;
               if(I[l].empty()) {
                  res += d;
                  if(!F[l].empty()) I[l].push(1), ++res;
               } else {
                  if(d > 0) F[l].push(d);
               }
            }
         }
      }
      cout << res << endl;
   }
   return 0;
}

