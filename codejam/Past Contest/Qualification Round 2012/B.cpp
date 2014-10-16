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

vector<int> A;

int solve(int P, int S)  {
   int res = 0;
   int used = S;
   for(int i = 0; i < sz(A); ++i) {
      int score = A[i] / 3;
      if(A[i] < 3) {
         if(A[i] == 0 && A[i] >= P) res++;
         else if(A[i] == 1 && A[i] >= P) res++;    
         else if(A[i] == 2 && 1 >= P) res++;
         else if(A[i] == 2 && used > 0 && 2 >= P) used--, res++;
      } else if(A[i] % 3 == 0) {
         if(score >= P) res++;
         else if(used > 0 && score + 1 >= P) used--, res++;
      } else if (A[i] % 3 == 1) {
         if(score + 1 >= P) res++;
      } else {
         if(score + 1 >= P) res++;
         else if(used > 0 && score + 2 >= P) used--, res++;
      }
   }
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int TC, N, S, p, ti, res;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      A.clear();
      res = 0;
      cin >> N >> S >> p;
      for(int i = 0; i < N; ++i) {
         cin >> ti;
         A.push_back(ti);
      }
      sort(all(A));
      printf("Case #%d: %d\n",tc, solve(p,S));
   }
   return 0;
}

