/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  435  C++  "Ad Hoc, Bits" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

const int MAXN = 1048580;
int V[22], S[MAXN];

int main(int argc, char *argv[]) {
   int TC, P, ma;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&P);
      ma = 0;
      for(int i = 0; i < P; ++i) {
         scanf("%d",&V[i]);
         ma += V[i]; 
      }
      ma /= 2;
      for(int i = 0; i < (1 << P); ++i) {
         int sum = 0;
         for(int j = 0; j < P; ++j) {
            if(i & (1 << j)) sum += V[j];
         }
         S[i] = sum;
      }
      for(int k = 0; k < P; ++k) {
         int pind = 0;
         for(int i = 0; i < (1 << P); ++i) {
            if(i & (1 << k)) {
               if(S[i] - V[k] <= ma && S[i] > ma)
                  pind++;               
            }
         }         
         printf("party %d has power index %d\n", k + 1, pind);
      }
      printf("\n");
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */
