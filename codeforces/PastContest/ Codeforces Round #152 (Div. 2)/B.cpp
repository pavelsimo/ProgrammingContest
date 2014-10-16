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
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   cin >> N;
   if(N < 3) {
     cout << -1 << endl;
   } else if(N == 3) {
     cout << 210 << endl; 
   } else {
      string s(N, '0');
      s[0] = '1';
      int p2 = N / 3;
      int p1 = N % 3;
      int sign = 1;
      if(p1 > 0) p2++;
      int a = 1;  
      if(p1 == 0) a = 100;
      else if(p1 == 2) a = 10;
      if(p2 % 2 == 0) sign = -sign;
      int k;
      for(k = 1; k <= 99; ++k) {
         int d1 = k % 10;
         int d2 = k / 10;
         if((k*10 + a*sign) % 7 == 0 
            && (d1 + d2 + 1) % 3 == 0) break;
      }
      s[N-2] = '0' + (k % 10);
      s[N-3] = '0' + (k / 10);
      cout << s << endl;
   }
   return 0;
}
