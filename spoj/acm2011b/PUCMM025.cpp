/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PUCMM025 C++ "Number Theory, Math" */
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

char s[1024];
int divide[10];

int main(int argc, char *argv[]) {
   int n, res;
   while(gets(s)) {
      n = strlen(s);
      memset(divide,0,sizeof(divide));
      divide[1] = 1;
      for(int i = 2; i <= 9; ++i) {
         int rem = 0;
         for(int j = 0; j < n; ++j)
            rem = (rem*10 + (s[j]-'0')) % i;
         divide[i]=(rem == 0);
      }
      res = 0;
      for(int i = 0; i < n; ++i)
         res+=divide[(s[i]-'0')];
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
