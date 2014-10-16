/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1246  C++  "Math, Prime Factor" */
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

typedef long long llong;

const int MAXP = 1000000;
vector<bool> P;
vector<int> D;

void sieve() {
   P = vector<bool> (MAXP + 2, true);
   D = vector<int>(MAXP + 2, 1);
   P[0] = P[1] = false;
   for(int i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         D[i] = 2;
         for(int j = i + i; j <= MAXP; j+=i) {
            P[j] = false;
            int x = j;
            int cnt = 0;
            while(x % i == 0) {
               cnt++;
               x/=i;
            }
            D[j]*=(cnt + 1);
         }
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int TC;
   int lo, hi;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&lo,&hi);   
      bool found = false;
      for(int i = lo; i <= hi; ++i) {
         if(P[D[i]]) {
            if(found) putchar(' ');
            printf("%d",i);
            found = true;
         }
      }
      if(!found) puts("-1");
      else putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
