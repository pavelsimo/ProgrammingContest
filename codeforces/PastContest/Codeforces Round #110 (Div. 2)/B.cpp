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

const double EPS = 1e-6;
const double PI = acos(-1.0);
const int MAXN = 2000;
int R[MAXN];

int main(int argc, char *argv[]) {
   double res = 0.0;
   int x = 1;
   int N;
   cin >> N;
   for(int i = 0; i < N; ++i)
      cin >> R[i];
   sort(R, R + N);   
   for(int i = N - 1; i >= 0; --i) {
      if(x)
         res+=PI*R[i]*R[i];
      else
         res-=PI*R[i]*R[i];
      x^=1;
   }
   printf("%lf\n",res);
   return 0;
}

