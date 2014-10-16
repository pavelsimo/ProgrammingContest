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

map<int, vector<int> > meal;

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int N, K, ctime, res;
   cin >> N >> K;
   for(int i = 0; i < N; ++i) {
      cin >> ctime;
      meal[ctime].push_back(i);
   }
   res = 0;
   foreach(it, meal) {
      vector<int> a = it->second;
      for(int i = 0; i < sz(a); ++i) {
         res++;
         int j;
         int hi = a[i] + K - 1;
         for(j = i + 1; j < sz(a); ++j)
            if(a[j] > hi) break;
         i = j - 1;
      }
   }
   cout << res << endl;
   return 0;
}

