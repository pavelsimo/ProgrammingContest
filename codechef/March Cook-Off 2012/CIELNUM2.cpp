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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

bool is_ceil(string &s) {
   int cnt3 = 0, cnt5 = 0, cnt8 = 0;
   for(int i = 0; i < sz(s); ++i) {       
      if(isspace(s[i])) continue;
      if(isdigit(s[i])) {
         if(s[i]=='3') {
            cnt3++;
            continue;
         } else if(s[i]=='5') {
            cnt5++;
            continue;
         } else if(s[i]=='8') {
            cnt8++;
            continue;
         }
      }
      return false;
   }
   if(cnt8==0 && cnt5==0 && cnt3==0) return false;
   return cnt8 >= cnt5 && cnt5 >= cnt3;
}

int main(int argc, char *argv[]) {
   string s, token;
   int TC, res;
   getline(cin, s);
   sscanf(s.c_str(),"%d", &TC);
   res = 0;
   while(TC-- > 0) {
      getline(cin, s);      
      reverse(all(s));
      s = s.substr(s.find_first_of("0123456789"));
      istringstream in(s);
      in >> token;
      if(is_ceil(token)) res++;
   }
   cout << res << endl;
   return 0;
}
