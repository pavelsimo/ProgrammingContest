/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  151  C++  "Ad Hoc, Josephus Problem" */
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

int josephus(int N, int M) {
   list<int> A;
   list<int>::iterator it;
   for(int i = 1; i <= N; ++i) 
      A.push_back(i);
   it = A.begin();
   for(int i = 0; A.size() > 1; ++i) {
      if(it == A.end()) 
         it = A.begin();
      if(i % M == 0)
         it = A.erase(it);
      else
         it++;
   }
   return A.front();
}


int main(int argc, char *argv[]) {
   int N;
   while(1==scanf("%d",&N)) {
      if(N==0) break;
      for(int i = 1; i <= 100; ++i) {
         if(josephus(N,i) == 13) {
            printf("%d\n",i);
            break;
         }
      }      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
