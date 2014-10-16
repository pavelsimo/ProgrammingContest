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
   set<string> alcohol;
   alcohol.insert("ABSINTH");
   alcohol.insert("BEER");
   alcohol.insert("BRANDY");
   alcohol.insert("CHAMPAGNE");
   alcohol.insert("GIN");
   alcohol.insert("RUM");
   alcohol.insert("SAKE");
   alcohol.insert("TEQUILA");
   alcohol.insert("VODKA");
   alcohol.insert("WHISKEY");
   alcohol.insert("WINE");
   int n, res = 0;
   string s;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> s;
      if(alcohol.count(s) != 0) {
         res++;
      } else if(isdigit(s[0])) {
         int a = atoi(s.c_str());
         if(a < 18) res++;
      }
   }
   cout << res << endl;
   return 0;
}

 
