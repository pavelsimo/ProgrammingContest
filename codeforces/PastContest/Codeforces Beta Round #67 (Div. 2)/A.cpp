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

string go(string s) {
   string res = "";
   for(int i = 0; i < sz(s); ++i) {
      if(s[i] == '0') continue;
      res += s[i];
   }
   return res;
}

int main(int argc, char *argv[]) { 
   string a, b, c2, a2, b2;
   int c;
   cin >> a >> b;
   a2 = go(a); b2 = go(b);
   c = atoi(a.c_str()) + atoi(b.c_str());
   c2 = go(tostr(c));
   if(atoi(a2.c_str()) + atoi(b2.c_str()) == atoi(c2.c_str()))
      cout << "YES" << endl;
   else
      cout << "NO" << endl;
   return 0;
}

