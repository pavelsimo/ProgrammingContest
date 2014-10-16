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
   int n, space;
   cin >> n;
   space = 2*n;
   for(int i = 0; i <= n; ++i) {
      printf("%s",string(space,' ').c_str());
      bool flag = false;
      for(int j = 0; j < i; ++j) {
         if(j > 0) putchar(' ');
         printf("%d",j);
         flag = true;
      }
      for(int j = i; j >= 0; --j) {
         if(flag) putchar(' ');
         printf("%d",j);
         flag = true;
      }
      space-=2;
      putchar('\n');
   }
   space = 2;
   for(int i = n - 1; i >= 0; --i) {
      printf("%s",string(space,' ').c_str());
      bool flag = false;
      for(int j = 0; j < i; ++j) {
         if(j > 0) putchar(' ');
         printf("%d",j);
         flag = true;
      }
      for(int j = i; j >= 0; --j) {
         if(flag) putchar(' ');
         printf("%d",j);
         flag = true;
      }
      space+=2;
      putchar('\n');
   }
   return 0;
}

