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
   list<int> A;
   list<int>::iterator it;
   if(K==0) return true;
   for(int i = 1; i <= K+K; ++i) 
      A.push_back(i);
   it = A.begin();
   for(int i = 1; sz(A) > K; ++i) {
      if(i % M == 0) {
         if(*it <= K) 
            return false;
         it = A.erase(it);
      } else {
         it++;
      }
      if(it == A.end()) it = A.begin();
   }
   return true;
}

int main(int argc, char *argv[]) {
   int K;
   while(1==scanf("%d",&K)) {
      if(K==0) break;
      for(int i = 0; i < 3000000; ++i) {
         if(josephus(K,i)) {
            printf("%d\n",i);
            break;
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
