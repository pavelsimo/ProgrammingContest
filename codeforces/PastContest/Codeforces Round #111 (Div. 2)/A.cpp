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

vector<int> X;
int main(int argc, char *argv[]) { 
   int N, a, sum = 0, x = 0, res = 0;
   cin >> N;
   for(int i = 0; i < N; ++i) {
      cin >> a;
      X.push_back(a);
      sum+=a;
   }
   sort(X.rbegin(),X.rend());
   for(int i = 0; i < N; ++i) {
      res++;
      x+=X[i];
      sum-=X[i];
      if(x > sum) break;
   }
   cout << res << endl;
   return 0;
}

