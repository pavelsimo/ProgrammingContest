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

bool solve(string M, string N) {
   int t_cnt = 0;
   for(int i = 0; i < sz(M); ++i)
      if(M[i] == 'T') t_cnt++;
   if(t_cnt == 0) return false;
   for(int i = 0; i < sz(M); ++i) {
      for(int j = i + 1; j <= sz(M); ++j) {
         string X = M.substr(i, j - i);
         if(X == N) 
            return true;
      }
   }
   return false;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   string M, N;
   cin >> TC;
   while(TC-- > 0) {
      cin >> M >> N;
      cout << (solve(M, N) ? "Y": "N") << endl;
   }
   return 0;
}
