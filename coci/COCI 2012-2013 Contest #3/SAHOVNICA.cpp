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

char X[502][502];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int R, C, A, B;
   cin >> R >> C >> A >> B;
   for(int i = 0; i < R * A; ++i) {
      for(int j = 0; j < C * B; ++j) {
         X[i][j] = '.';
      }
   }
   for(int i = 0, k = 0; i < R * A; i += A, ++k) {
      for(int j = k & 1 ? B: 0; j < C * B; j += 2 * B) {
         for(int ii = 0; ii < A; ++ii) {
            for(int jj = 0; jj < B; ++jj) {
               X[i+ii][j+jj] = 'X';
            }
         }
      }
   }
   for(int i = 0; i < R * A; ++i) {
      for(int j = 0; j < C * B; ++j) {
         printf("%c",X[i][j]);
      }
      printf("\n");
   }
   return 0;
}

