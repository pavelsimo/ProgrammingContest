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

const int MAXN = 102, INF = 0x3f3f3f3f;
int A[MAXN][MAXN], R[MAXN], C[MAXN];

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   memset(R, 0x3f, sizeof(R));
   memset(C, 0, sizeof(C));
   int N, M;
   cin >> N >> M;
   for(int r = 0; r < N; ++r) {
      for(int c = 0; c < M; ++c) {
         cin >> A[r][c];
         R[r] = min(R[r], A[r][c]);
         C[c] = max(C[c], A[r][c]);
      }
   }
   for(int r = 0; r < N; ++r) {
      for(int c = 0; c < M; ++c) {
         if(R[r] == C[c]) {
            cout << R[r] << endl;
            return 0;
         }      
      }
   }
   cout << "GUESS" << endl;
   return 0;
}

