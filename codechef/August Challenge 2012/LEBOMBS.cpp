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

typedef long long llong;

bool seen[1002];

int main(int argc, char *argv[]) {
   int TC, n, res;
   string s;
   cin >> TC;
   while(TC-- > 0) {
      memset(seen, false, sizeof(seen));
      cin >> n >> s;
      for(int i = 0; i < n; ++i) {
         if(s[i]-'0') {
            seen[i] = true;
            if(i - 1 >= 0) seen[i-1] = true;
            if(i + 1 < n) seen[i+1] = true;
         }
      }
      res = 0;
      for(int i = 0; i < n; ++i)
         if(!seen[i]) res++;
      cout << res << endl;
   }   
   return 0;
}

