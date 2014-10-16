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

vector<string> archive[55];
int p[55];
vector<string> problem;
map<string, int> ord;

int get_inv(vector<string> &a) {
   int res = 0;
   for(int i = 0; i < sz(a); ++i) {
      for(int j = i + 1; j < sz(a); ++j) {
         if(ord[a[j]] < ord[a[i]]) res++;  
      }
   }
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int n, m, k;   
   string s;
   memset(p, 0, sizeof(p));
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> s;
      problem.push_back(s);
      ord[s] = i;
   }
   cin >> m;
   for(int i = 0; i < m; ++i) {
      cin >> k;
      for(int j = 0; j < k; ++j) {
         cin >> s;
         archive[i].push_back(s);
      }
   }
   int p = 0;
   int best = 0;
   for(int i = 0; i < m; ++i) {
      int j;
      vector<int> ind;
      for(j = 0; j < sz(problem); ++j) {
         int pos = find(all(archive[i]), problem[j]) - archive[i].begin();
         if(pos == sz(archive[i])) break;
         ind.push_back(pos);
      }
      sort(all(ind));
      if(j == sz(problem)) {
         vector<string> arch;
         for(int k = 0; k < sz(ind); ++k) {
            arch.push_back(archive[i][ind[k]]);
         }
         int t = ((n*(n-1))/2) - get_inv(arch) + 1;
         if(t > p) {
            p = t;
            best = i;   
         }
      }
   }
   if(p > 0) {
      cout << best + 1 << endl;
      cout << "[:" << string(p, '|') << ":]" << endl;
   } else cout << "Brand new problem!" << endl;
   return 0;
}

