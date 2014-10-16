/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  944  C++  "Math, Cycle, Happy Numbers" */
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

int H[100000];
set<int> seen;

void preprocess() {
   for(int i = 1; i <= 99999; ++i) {
      seen.clear();
      bool is_happy = true;
      int X = i;
      seen.insert(X);
      while(X != 1) {
         int sum = 0;
         while(X > 0) {
            int d = (X%10);
            sum += d*d;
            X/=10;
         }
         X = sum;
         if(seen.count(X) != 0) {
            is_happy = false;
            break;
         }
         seen.insert(X);
      }
      if(is_happy) H[i] = sz(seen);
      else H[i] = 0;      
   }
}

int main(int argc, char *argv[]) {
   int a, b;
   preprocess();
   for(int tc = 0; 2 == scanf("%d%d",&a,&b); ++tc) {
      if(tc > 0) printf("\n");
      for(int i = a; i <= b; ++i)
         if(H[i]) printf("%d %d\n",i, H[i]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

