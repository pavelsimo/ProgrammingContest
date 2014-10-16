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
   int TC, N, M, F;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d%d",&N,&M,&F);
      for(int i = 0; i < F; ++i)
         scanf("%d%d",&streets[i],&avenues[i]);
      sort(streets, streets + F);
      sort(avenues, avenues + F);
      if(F%2==0) 
         printf("(Street: %d, Avenue: %d)\n",streets[(F-1)/2], avenues[(F-1)/2]);
      else 
         printf("(Street: %d, Avenue: %d)\n",streets[F/2], avenues[F/2]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
