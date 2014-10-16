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

int main(int argc, char *argv[]) { 
   double a, b, c, d;
   scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
   double a_hit  = a/b;
   double a_miss = 1 - a_hit;
   double b_hit  = c/d;
   double b_miss = 1 - b_hit;
   double at_least_one_shoot = 1 - (a_miss * b_miss);
   printf("%lf\n",((a_hit * b_hit) + (a_hit * b_miss)) / at_least_one_shoot);
   return 0;
}
