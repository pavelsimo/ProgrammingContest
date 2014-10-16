/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  580  C++  "Dynamic Programming, Math" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int memo[1000002][4][2];

int rec(int cubes, int uranium, int state) {
   if(cubes == 0) 
      return state;
   if(memo[cubes][uranium][state] >= 0)
      return memo[cubes][uranium][state];
   return memo[cubes][uranium][state] = rec(cubes - 1, (uranium + 1) % 4, state | (uranium==2)) + rec(cubes - 1, 0, state);
}

int main(int argc, char *argv[]) {
   int N;
   memset(memo,-1,sizeof(memo));
   while(1==scanf("%d",&N)) {
      if(N==0) break;
      printf("%d\n",rec(N,0,0));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
