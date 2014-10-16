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

bool islucky(string s) {
   for(int i = 0; i < sz(s); ++i)
      if(s[i] != '4' && s[i] != '7') 
         return false;
   return true;
}

bool isluckyticket(string s) {
   if(!islucky(s)) 
      return false;
   int lo = 0, hi = sz(s) - 1, sum1 = 0, sum2 = 0;
   while(lo < hi) {
      sum1+=s[lo]-'0', sum2+=s[hi]-'0';
      lo++;
      hi--;
   }
   return sum1 == sum2;
}

int main(int argc, char *argv[]) { 
   string t, s;
   cin >> t >> s;
   if(isluckyticket(s)) puts("YES");
   else puts("NO");
   return 0;
}

