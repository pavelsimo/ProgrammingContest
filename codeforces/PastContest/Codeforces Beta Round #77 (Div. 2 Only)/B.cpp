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

typedef long long llong;

vector<llong> X;
int A[12];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   for(int i = 1; i <= 5; ++i) {
      int j, k;
      for(j = 0; j < i; ++j) A[j] = 4;
      for(k = 0; k < i; ++k) A[j + k] = 7;
      do {
         llong t = 0;
         for(j = 0; j < 2*i; ++j) 
            t = t*10LL + A[j]; 
         X.push_back(t);
      } while(next_permutation(A, A + 2*i));
   }
   llong n;
   cin >> n;
   int ind = int(lower_bound(all(X), n) - X.begin());
   cout << X[ind] << endl;
   return 0;
}

