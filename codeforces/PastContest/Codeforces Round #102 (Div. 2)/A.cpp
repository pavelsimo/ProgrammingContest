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
   int r1, r2, c1, c2, d1, d2;
   cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
   for(int a = 1; a <= 9; ++a) {
      for(int b = 1; b <= 9; ++b) {
         if(b == a) continue;
         for(int c = 1; c <= 9; ++c) {
            if(c == a || c == b) continue;
            for(int d = 1; d <= 9; ++d) {
               if(d == a || d == b || d == c) continue;
               if(a + b == r1 && c + d == r2 && a + d == d1 && b + c == d2 && a + c == c1 && b + d == c2) {
                  printf("%d %d\n",a,b);      
                  printf("%d %d\n",c,d);      
                  return 0;
               }
            }      
         }      
      }      
   }
   printf("-1\n");
   return 0;
}

