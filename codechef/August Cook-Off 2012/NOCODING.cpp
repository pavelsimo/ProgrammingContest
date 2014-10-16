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

int main(int argc, char *argv[]) { 
   int TC;
   string s;
   getline(cin, s);
   sscanf(s.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin, s);
      int sum = sz(s) + 1;
      for(int i = 1; i < sz(s); ++i) {
         int cur = s[i] - 'a';
         int prev = s[i-1] - 'a';
         if(cur >= prev) sum += cur - prev;
         else sum += (26-prev) + cur;
      }
      if(sum <= sz(s) * 11) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
   return 0;
}

