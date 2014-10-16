/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  855  C++  "Sorting, Median, 2D Grid" */
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

const int MAXN = 50010;
int streets[MAXN];
int avenues[MAXN];

int main(int argc, char *argv[]) {
   int TC, N, M, F, F2;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d%d",&N,&M,&F);
      for(int i = 0; i < F; ++i)
         scanf("%d%d",&streets[i],&avenues[i]);
      if(F & 1) F2 = F/2;
      else  F2 = (F-1)/2;
      nth_element(streets, streets + F2, streets + F);
      nth_element(avenues, avenues + F2, avenues + F);
      printf("(Street: %d, Avenue: %d)\n",streets[F2], avenues[F2]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
