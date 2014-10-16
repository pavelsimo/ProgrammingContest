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

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int TC, N;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      int res = -1;
      for(int x = 0; x <= N; ++x) {
         if(4*x > N) break;
         int y = N - 4*x;
         if(y % 7 == 0) {
            res = y;
            break;
         }
      }
      printf("%d\n",res);
   }
   return 0;
}
