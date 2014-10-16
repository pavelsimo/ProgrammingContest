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

vector<int> A[6002];

int main(int argc, char *argv[]) { 
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int N, ai;
   cin >> N;
   for(int i = 0; i < 2 * N; ++i) {
      cin >> ai;
      A[ai].push_back(i + 1);
   }
   for(int i = 1; i <= 5000; ++i) {
      if(sz(A[i]) % 2 == 0) continue;
      cout << -1 << endl;
      return 0;      
   }
   for(int i = 1; i <= 5000; ++i) {
      for(int j = 0; j < sz(A[i]); j+=2) {
         cout << A[i][j] << " " << A[i][j+1] << endl;
      }
   }
   return 0;
}
