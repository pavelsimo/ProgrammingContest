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
   int n;
   bool isamp, ok = false;
   string s, t = "";
   while(getline(cin,s)) {
      n = s.size();
      isamp = false;
      for(int j = 0; j < n; ++j) {
         if(isspace(s[j])) continue;
         else if(s[j] == '#') isamp = true;
         break;
      }
      if(isamp) {
         if(ok) cout << t << endl;
         cout << s << endl;
         ok = false;
         t = "";
      } else {
         for(int j = 0; j < n; ++j) {
            if(isspace(s[j])) continue;
            t+=s[j];
         }
         ok = true;
      }
   }
   if(ok) cout << t << endl;
   return 0;
}

