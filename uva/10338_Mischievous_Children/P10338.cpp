/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10338  C++  "Math, Factorial, Combinations with Repetitions" */
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

llong fact(int n) {
   llong res = 1LL;
   for(int i = 1LL; i <= n; ++i)
      res*=llong(i);
   return res;
}

char buf[32];

int main(int argc, char *argv[]) {
   int TC, n;
   llong res;
   gets(buf);
   sscanf(buf,"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      gets(buf);   
      n = strlen(buf);
      map<char,int> freq;
      for(int i = 0; i < n; ++i)freq[buf[i]]++;
      res = fact(n);
      foreach(it,freq) res/=fact(it->second);
      printf("Data set %d: %lld\n",tc,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
