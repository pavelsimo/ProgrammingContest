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

vector<int> A;

int main(int argc, char *argv[]) {
   int N, X, u, res = 0;
   cin >> N >> X;
   for(int i = 0; i < N; ++i) {
      cin >> u;
      A.push_back(u);
   }
   sort(all(A));
   while(A[(sz(A) - 1)/2] != X) {
      A.push_back(X);
      res++;
      sort(all(A));
   }
   cout << res << endl;
   return 0;
}