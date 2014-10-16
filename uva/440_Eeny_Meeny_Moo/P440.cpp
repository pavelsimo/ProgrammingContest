/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  440  C++  "Ad Hoc, Josephus Problem" */
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

bool josephus(int n, int k) {
   list<int> A;
   list<int>::iterator it;
   for(int i = 1; i <= n; ++i)
      A.push_back(i);
   it = A.begin();
   for(int i = 0; sz(A) > 1; ++i) {
      if(i % k == 0) {
         if(*it == 2) 
            return false;
         it = A.erase(it);
      } else {
         it++;
      }
      if(it==A.end())
         it = A.begin();
   }
   return A.front() == 2;
}

int A[] = {0,0,0,2,5,2,4,3,11,2,3,8,16,4,21,6,5,2,11,20,34,8,15,10,7,13,11,13,45,18,23,8,3,2,25,75,
42,13,5,23,13,50,16,18,89,38,8,39,30,29,38,7,45,23,137,46,63,17,48,5,46,34,140,33,39,2,28,29,
79,33,48,3,10,46,120,6,37,17,8,44,15,160,20,35,144,104,179,153,24,8,265,19,9,62,7,139,19,
44,93,182,27,158,185,193,17,82,3,11,43,55,21,41,146,29,80,59,8,29,66,19,160,59,28,129,127,
120,72,45,157,2,63,127,81,318,513,98,28,32,231,236,411,26,45,5,303,228,66,9,205,65,39};

int main(int argc, char *argv[]) {
   int n;
   while(1==scanf("%d",&n)) {
      if(n==0) break;
      printf("%d\n",A[n]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
