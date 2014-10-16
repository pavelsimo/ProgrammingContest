/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ AE00 C++ "Ad Hoc" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int main(int argc, char *argv[]) {
   int N,res;
   while(scanf("%d",&N)==1) {
      res = N; 
      for(int i = 2; i*i <= N; ++i) {
         for(int j = i*i; j <= N; j+=i)
            res++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
