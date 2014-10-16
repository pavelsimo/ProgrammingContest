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


string format(string s) {
   string res = "";
   for(int i = s.size() - 1, j = 0; i >= 0; --i, ++j) {
      if(j > 0 && j % 3 == 0)
         res = tostr(",") + res;
      res = tostr(s[i]) + res;
   }
   res = tostr("$") + res;
   return res;
}

string fix(string s) {
   if(s.size() < 2) return s + "0";
   return s.substr(0,2);
}

int main(int argc, char *argv[]) {
   string s, res;
   cin >> s;
   int pos;
   bool isneg = false;
   if(s[0] == '-')
      s = s.substr(1), isneg = true;
   if((pos = s.find('.')) >= 0)
      res = format(s.substr(0,pos)) + "." + fix(s.substr(pos+1)); 
   else
      res = format(s) + ".00";
   if(isneg)
      res = "(" + res + ")";
   cout << res << endl;
   return 0;
}

