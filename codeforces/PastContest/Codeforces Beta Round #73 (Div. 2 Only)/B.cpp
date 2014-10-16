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

int D[26];
vector<pair<int,int> > C[26];
vector<pair<int,int> > shift;
 
int dist_sqr(pair<int,int> &p1, pair<int, int> &p2) {
   int di = p1.first - p2.first;
   int dj = p1.second - p2.second;
   return di*di + dj*dj;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   
   memset(D, 0x3f, sizeof(D));
   
   int n, m, x, q, res = 0;
   string keyboard[120], text;
   cin >> n >> m >> x;
   for(int i = 0; i < n; ++i) {
      cin >> keyboard[i];
      for(int j = 0; j < m; ++j) {
         if(keyboard[i][j] == 'S') 
            shift.push_back(make_pair(i + 1, j + 1));
         else
            C[keyboard[i][j] - 'a'].push_back(make_pair(i + 1, j + 1));
      }
   }
   cin >> q >> text;
   
   for(int k = 0; k < 26; ++k) {
      for(int i = 0; i < sz(C[k]); ++i) {
         for(int j = 0; j < sz(shift); ++j) {
            D[k] = min(D[k], dist_sqr(C[k][i], shift[j]));
         }
      }             
   }
   for(int i = 0; i < sz(text); ++i) {
      if(sz(C[tolower(text[i])-'a']) == 0) {
         cout << "-1" << endl;
         return 0;
      }
      if(isupper(text[i])) {
         if(sz(shift) == 0) {
            cout << "-1" << endl;
            return 0;
         }
         char ch = tolower(text[i]);
         if(D[ch - 'a'] > x * x) res++;
      }
   }
   cout << res << endl;
   return 0;
}

