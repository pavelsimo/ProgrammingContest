/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  256  C++  "Brute Force" */
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

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI a;

void preproccess() {
   a = VVI(10);
   int pow10[] = {10,100,1000,10000}; 
   int digit[] = {2,4,6,8};
   for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < pow10[i]*pow10[i]; ++j) {
         int x = (j / pow10[i]) + (j % pow10[i]);
         if(x * x == j)
            a[digit[i]].push_back(j);
      }
   }
}

int main(int argc, char *argv[]) {
   preproccess();
   int N;
   while(1==scanf("%d",&N)) {
      for(int i = 0; i < sz(a[N]); ++i)
         printf("%0*d\n",N,a[N][i]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
