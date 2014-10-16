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
   string s, ans;
   cin >> s;
   int cnt = 0;
   for(int i = 0; i < sz(s); ++i)
      if(s[i] == '@') cnt++;
   ans = "";
   if(s[0] == '@' || s[sz(s)-1] == '@' || cnt == 0) {
      cout << "No solution" << endl;
      return 0;
   }
   for(int i = 0; i < sz(s); ++i) {
      if(s[i] == '@') cnt--;
      ans += s[i];
      if(cnt > 0 && i - 1 >= 0 && isalpha(s[i]) && s[i-1] == '@')
         ans += ",";
   }
   for(int i = 0; i < sz(ans); ++i) {
      if(ans[i] == '@') {
         int l, r;
         l = r = 0;
         if(i - 1 >= 0 && isalpha(ans[i-1])) l = 1;
         if(i + 1 < sz(ans) && isalpha(ans[i+1])) r = 1;
         if(!l || !r) {
            cout << "No solution" << endl;
            return 0;            
         }
      }
   }
   cout << ans << endl;
   return 0;
}

