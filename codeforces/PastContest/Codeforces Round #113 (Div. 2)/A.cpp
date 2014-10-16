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

struct Team {
   int p, t;
   bool operator<(const Team &T) const {
      if(p != T.p) return p > T.p;
      return t < T.t;
   }
};

const int MAXN = 102;
Team A[MAXN];

int main(int argc, char *argv[]) { 
   int N, K, res = 0;
   cin >> N >> K;
   K--;
   for(int i = 0; i < N; ++i)
      cin >> A[i].p >> A[i].t;
   sort(A, A + N);
   int point = A[K].p;
   int time = A[K].t;
   for(int i = 0; i < N; ++i) {
      if(A[i].t == time && A[i].p == point) 
         res++;
   }
   cout << res << endl;
   return 0;
}

