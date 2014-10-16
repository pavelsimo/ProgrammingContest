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

vector<int> a[52];
vector<int> C;
map<int,pair<int,int> > m_orig;
vector<pair<int,int> > res1, res2;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int nrows, ci, ai;
   cin >> nrows;
   for(int i = 0; i < nrows; ++i) {
      cin >> ci;
      C.push_back(ci);
   }
   ci = 1;
   for(int i = 0; i < sz(C); ++i) {
      for(int j = 0; j < C[i]; ++j) {
         cin >> ai;
         a[i].push_back(ai);
         m_orig[ai] = make_pair(i, j);
         ci++;
      }
   }
   ci = 1;
   for(int i = 0; i < sz(C); ++i) {
      for(int j = 0; j < C[i]; ++j) {
         if(a[i][j] != ci) {
            int r = m_orig[ci].first;
            int c = m_orig[ci].second;
            res1.push_back(make_pair(i,j));
            res2.push_back(make_pair(r,c));
            m_orig[ci] = make_pair(i, j);
            m_orig[a[i][j]] = make_pair(r,c);
            swap(a[i][j], a[r][c]);
         }
         ci++;
      }
   }
   cout << sz(res1) << endl;
   for(int i = 0; i < sz(res1); ++i) {
      cout << res1[i].first + 1 << " " << res1[i].second + 1 << " " 
         << res2[i].first + 1 << " " << res2[i].second + 1 << endl;
   }
   return 0;
}

