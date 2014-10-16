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

bool lucky(int n) {
   int x = n;
   while(x > 0) {
      if(x%10!=7 && x%10!=4) return false;
      x/=10;
   }
   return true;
}

int main(int argc, char *argv[]) {
   int N;
   cin >> N;
   bool found = false;
   for(int i = 1; i <= N; ++i) {
      if(lucky(i) && N%i==0) {
         found = true;
         break;
      }
   }
   if(found) puts("YES");
   else puts("NO");
   return 0;
}

