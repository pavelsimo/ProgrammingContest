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
   int TC;
   int e1, base1, e2, base2;
   string a, b;
   cin >> TC;
   while(TC-- > 0) {
      cin >> a >> b;  
      sscanf(a.c_str(),"%d^%d",&base1,&e1);
      sscanf(b.c_str(),"%d^%d",&base2,&e2);      
      if(e1 * log10(base1) > e2 * log10(base2))
         cout << a << endl;
      else
         cout << b << endl;
   }
   return 0;
}

