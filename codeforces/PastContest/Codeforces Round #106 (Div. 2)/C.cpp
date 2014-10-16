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

typedef pair<int,int> PII;
PII A[100010];
vector<int> res[2];

int main(int argc, char *argv[]) {
   int n;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> A[i].first;
      A[i].second = i + 1;
   }
   sort(A, A + n);
   for(int i = 0; i < n; ++i)
      res[i % 2].push_back(A[i].second);
   printf("%d\n",sz(res[0]));
   for(int i = 0; i < sz(res[0]); ++i) {
      if(i > 0) putchar(' ');
      printf("%d",res[0][i]);
   }
   printf("\n");
   printf("%d\n",sz(res[1]));
   for(int i = 0; i < sz(res[1]); ++i) {
      if(i > 0) putchar(' ');
      printf("%d",res[1][i]);
   }
   printf("\n");
   return 0;
}

