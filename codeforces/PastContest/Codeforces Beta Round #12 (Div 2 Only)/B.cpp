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
   string a, b;
   cin >> a >> b;
   sort(all(a));
   if(a.size() >= 2 && a[0] == '0') {
      int ind = 1;
      for(int i = 1; i < sz(a); ++i) {
         if(a[i] >= '1' && a[i] <= '9' && a[i] < a[ind])
            ind = i;
      }
      swap(a[0], a[ind]);
   }
   if(a == b) cout << "OK" << endl;
   else cout << "WRONG_ANSWER" << endl;
   return 0;
}

