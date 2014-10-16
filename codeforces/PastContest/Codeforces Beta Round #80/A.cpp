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

int P[] = {2,3,4,5,6,7,8,9,10,10,10};

int main(int argc, char *argv[]) {
   int N, res = 0;
   cin >> N;
   for(int i = 0; i < 11; ++i)
      if(10 + P[i] == N) ++res;
   if( 11 == N || 21 == N) ++res;
   res = res * 4;
   if( 20 == N ) res+=3;
   cout << res << endl;
   return 0;
}

