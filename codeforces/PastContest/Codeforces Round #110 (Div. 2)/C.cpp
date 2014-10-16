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

int cost(string s1, string s2) {
   int best = 0;
   for(int i = 0; i < sz(s1); ++i) {
      int match = 0;
      for(int j = 0; j < sz(s2); ++j) {
         if(i + j >= sz(s1)) break;
         if(s1[i + j] == s2[j]) match++;
      }
      best = max(match,best);
   }   
   return best;
}

int main(int argc, char *argv[]) {
   string s1, s2, t, u;
   cin >> s1 >> s2;
   t = s1;
   u = s2;
   int best = max(cost(s1,s2),cost(s2,s1));
   cout << sz(u) - best << endl;
   return 0;
}
// END CUT HERE
