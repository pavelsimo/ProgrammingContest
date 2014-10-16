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

typedef pair<int,int> card;
const int MAXN = 1002;
vector<card> X;

int main(int argc, char *argv[]) {
   int N, ai, bi;
   cin >> N;
   for(int i = 0; i < N; ++i) {
      cin >> ai >> bi;
      X.push_back(make_pair(bi,ai));
   }
   sort(X.rbegin(),X.rend());
   int M = 1, res = 0;
   for(int i = 0; i < N; ++i) {
      if(!M) break;
      M+=X[i].first;
      res+=X[i].second;
      M--;
   }
   cout << res << endl;
   return 0;
}

