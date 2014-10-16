/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10298  C++  "String Matching, KMP" */
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

const int MAXN = 1000100;
int b[MAXN];
char s[MAXN];

int kmp_preprocessing() {
   int i = 0, j = -1;
   int M = strlen(s);
   b[i] = j;
   while(i < M) {
      while(j >= 0 && s[i] != s[j]) j = b[j];
      ++i; ++j;      
      b[i] = j;
   }
   return M - b[M];
}

int main(int argc, char *argv[]) {
   int n;
   while(gets(s)) {
      if(s[0]=='.') break;
      n = kmp_preprocessing();
      printf("%d\n",strlen(s)/n);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
