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
   string board[3];
   int n = 3;
   for(int i = 0; i < n; ++i)
      cin >> board[i];
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {   
         if(board[i][j] == 'X' && board[n-i-1][n-j-1] == '.') {
            cout << "NO" << endl;
            return 0;
         }
      }
   }
   cout << "YES" << endl;
   return 0;
}

