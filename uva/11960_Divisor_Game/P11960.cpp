/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11960  C++  "Math, Sieve" */
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

const int MAXN = 1000002;
int D[MAXN], A[MAXN];

void preproccess() {
   for(int i = 0; i < MAXN; ++i) {
      D[i] = 1; 
      A[i] = 0;
   }
   D[0] = 0;
   A[1] = 1;
   for(int i = 2; i < MAXN; ++i) {
      for(int j = i; j < MAXN; j+=i)
         D[j]++;
   }
   for(int i = 1; i < MAXN; ++i) {
      if(D[i] >= D[A[i - 1]]) A[i] = i;
      else A[i] = A[i-1];
   }
}

int main(int argc, char *argv[]) {
   preproccess();
   int TC, N;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      printf("%d\n",A[N]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
