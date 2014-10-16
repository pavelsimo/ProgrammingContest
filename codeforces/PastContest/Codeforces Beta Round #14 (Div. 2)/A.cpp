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

const int INF = 200;
char a[52][52];

int main(int argc, char *argv[]) { 
   int n, m;
   cin >> n >> m;
   int min_i = INF;
   int max_i = 0;
   int min_j = INF;
   int max_j = 0;
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {  
         cin >> a[i][j];
         if(a[i][j] == '*') {
            min_i = min(min_i, i);
            min_j = min(min_j, j);
            max_i = max(max_i, i);
            max_j = max(max_j, j);
         }
      }
   }
   for(int i = min_i; i <= max_i; ++i) {
      for(int j = min_j; j <= max_j; ++j) {  
         cout << a[i][j];  
      }
      cout << endl;
   }
   return 0;
}

