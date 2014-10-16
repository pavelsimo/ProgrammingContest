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

bool isvowel(char ch) {
   ch = tolower(ch);
   return ch == 'a' || ch == 'o' || ch == 'y' || ch == 'e' || ch == 'u' || ch == 'i';
}

int main(int argc, char *argv[]) {
   string s, t, res;
   cin >> s;
   res = t = "";
   for(int i = 0; i < sz(s); ++i) {
      if(!isvowel(s[i])) t+=s[i];
   }
   for(int i = 0; i < sz(t); ++i) {
      res+='.';
      res+=tolower(t[i]);
   }
   cout << res << endl;
   return 0;
}

