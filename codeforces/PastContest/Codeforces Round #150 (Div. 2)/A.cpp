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

vector<int> A[1002];
bool used[1002];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k, ai;
   cin >> n >> k;
   for(int i = 0; i < k; ++i) {
      cin >> ai;
      used[ai] = true;
      A[i].push_back(ai);
   }
   for(int i = 1, j = 0; i <= n*k; ++i) {
      if(used[i]) continue;
      if((int)A[j].size() == n) j++;
      A[j].push_back(i);
   }
   for(int i = 0; i < k; ++i) {
      for(int j = 0; j < sz(A[i]); ++j) {
         if(j > 0) cout << ' ';
         cout << A[i][j];
      }
      cout << endl;
   }
   return 0;
}

