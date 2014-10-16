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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())

int main() {
   int TC = 100;
   int N = 1000;
   printf("%d\n",TC);
   while(TC-- > 0) {
      printf("%d\n",N);
      srand(time(NULL));
      for(int i = 0; i < N; ++i) {
         if(i > 0) putchar(' ');
         int r = rand() % 1000000 + 1;
         printf("%d",r);
      }
      putchar('\n');
   }
   return 0;
}
