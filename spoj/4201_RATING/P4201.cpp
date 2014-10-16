/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10810  C++  "Fenwick Tree, BIT, Sorting, Merge Sort, Couting Inversions" */
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

const int MAXN = 200002;
vector<llong> A, H;
llong t1[MAXN], t2[MAXN];
map<llong,llong> freqA, freqH;

llong read(llong *tree, llong idx){
	llong sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(llong *tree, llong idx ,llong val){
	while (idx <= MAXN){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main(int argc, char *argv[]) {
   int N;
   llong ai, hi, c1, c2, c3, c4;
   while(1 == scanf("%d",&N)) {
      memset(t1, 0, sizeof(t1));
      memset(t2, 0, sizeof(t2));
      A.clear(), H.clear(), freqA.clear(), freqH.clear();
      for(int i = 0; i < N; ++i) {
         scanf("%lld%lld",&ai, &hi);
         A.push_back(ai);
         H.push_back(hi);
         freqA[ai]++;
         freqH[ai]++;
         update(t1, ai, 1);
         update(t2, hi, 1);
      }
      for(int i = 0; i < N; ++i) {
         
         
         c1 = read(t1, A[i] - 1);
         c2 = read(t2, H[i] - 1);
         
         c3 = read(t1, H[i] - 1);
         c4 = read(t2, A[i] - 1);
         
         llong c5 = min(min(c1,c3), min(c2,c4));
         
         DEBUG(c1);
         DEBUG(c3);
         DEBUG(c2);
         DEBUG(c4);
         
         printf("%lld\n",c5);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

