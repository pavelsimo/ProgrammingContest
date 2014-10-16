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

struct Integer {
  string s; 
  Integer(string _s = "") : s(_s) {}
  bool operator<(const Integer &T) const {
     if(s.size() != T.s.size()) return s.size() < T.s.size();
     return s < T.s;  
  }
};

Integer a[1002];

int main(int argc, char *argv[]) {
   int TC, n;
   cin >> TC;
   while(TC-- > 0) {  
      cin >> n;
      for(int i = 0; i < n; ++i)
         cin >> a[i].s;
      sort(a, a + n);
      for(int i = 0; i < n; ++i) {
         if(i > 0) cout << ' ';
         cout << a[i].s;
      }      
      cout << endl;
   }
   return 0;
}

