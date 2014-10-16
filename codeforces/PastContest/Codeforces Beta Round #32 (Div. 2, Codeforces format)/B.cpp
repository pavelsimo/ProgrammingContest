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
   string s, ans = "";;
   cin >> s;
   for(int i = 0; i < sz(s); ++i) {
      if(s[i] == '.') ans += "0";
      else if(i + 1 < sz(s) && s[i] == '-' && s[i+1] == '.') ans += "1", i = i + 1;
      else if(i + 1 < sz(s) && s[i] == '-' && s[i+1] == '-') ans += "2", i = i + 1;
   }
   cout << ans << endl;
   return 0;
}

