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

const int MAXN = 15;
llong P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   llong N;
   while(cin >> N) {
      if(!N) break;
      llong prod = 1LL;
      for(int i = 0; i < MAXN; ++i) {
         if(P[i] > N) break;
         prod *= P[i];
      }
      cout << prod << endl;
   }
   return 0;
}