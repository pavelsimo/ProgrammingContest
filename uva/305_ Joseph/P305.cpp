/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  305  C++  "Ad Hoc, Josephus Problem" */
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

bool josephus(int K, int M) {
   int N = K+K;
   int index = 0;
   for(int i = 0; i < K; ++i) {
      index = (index+M-1)%N;
      if(index < K) 
         return false;
      N--;         
      if(index == N) 
         index = 0;
   }
   return true;
}

int A[] = {1,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main(int argc, char *argv[]) {
   int K;
   while(1==scanf("%d",&K)) {
      if(K==0) break;
      printf("%d\n",A[K]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
