/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11349  C++  "Ad Hoc, Greedy" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

typedef long long llong;
llong A[102][102];

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC, N;
   string s;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> s >> s >> N;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            cin >> A[i][j];
         }
      }
      bool ok = true;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j, --jj) {
            if(A[i][j] < 0 || A[i][j] != A[N-i-1][N-j-1]) 
               ok = false; 
         }
      }
      cout << "Test #" << tc << ": " 
         <<  (ok ? "Symmetric." : "Non-symmetric.") << '\n';
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */
