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
   ios_base::sync_with_stdio(0);
   string a, b, t1, t2;
   cin >> a >> b;
   t1 = a;
   t2 = b;
   sort(all(t1));
   sort(all(t2));
   if(t1 == t2) {
      int cnt = 0;
      for(int i = 0; i < sz(a); ++i)
         if(a[i] != b[i]) cnt++;
      if(cnt == 2)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   } else {
      cout << "NO" << endl;
   }
   return 0;
}

