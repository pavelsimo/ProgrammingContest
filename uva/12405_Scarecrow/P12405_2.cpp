/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12405  C++  "Greedy" */
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


int main(int argc, char *argv[]) {
   int TC, res, N;
   string S;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> N >> S;
      res = 0;
      vector<int> X;
      for(int i = 0; i < N; ++i)
         if(S[i] == '.') 
            X.push_back(i);
      int prev = -1, sum = 0, res = 0;
      for(int i = 0; i < sz(X); ++i) {
         if(prev == -1 || sum + (X[i] - prev) > 2)
            res++, sum = 0;
         else
            sum+=X[i]-prev;
         prev = X[i];
      }
      printf("Case %d: %d\n",tc,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

