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

const double PI = 3.14159265359;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int TC;
   int N, r, h;
   scanf("%d",&TC);
   while(TC-- > 0) {
      double res = 0.0;
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) {
         scanf("%d%d",&r,&h);
         res += (PI * r * r * h);
      }
      printf("%.2lf\n", res);
   }
   return 0;
}

