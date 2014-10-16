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
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   string s;
   getline(cin, s);
   sscanf(s.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin, s);
      bool f = false; 
      bool r = false;
      if(sz(s) >= 5) {
         int lst = sz(s) - 1;
         if(s[0] == 'm' && s[1] == 'i' && s[2] == 'a' && s[3] == 'o' && s[4] == '.') 
            r = true;
         if(s[lst] == '.' && s[lst-1] == 'a' && s[lst-2] == 'l' && s[lst-3] == 'a' && s[lst-4] == 'l') 
            f = true;
      }
      if(f && !r) cout << "Freda's" << endl;
      else if(r && !f) cout << "Rainbow's" << endl;
      else cout << "OMG>.< I don't know!" << endl;
   }
   return 0;
}
