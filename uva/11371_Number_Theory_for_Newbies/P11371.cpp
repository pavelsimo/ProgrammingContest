/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11371  C++  "Number Theory, Math" */
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

int main(int argc, char *argv[]) {
   llong hi, lo, x;
   string buf;
   while(getline(cin,buf)) {
      sort(all(buf));
      if(buf[0]=='0') {
         int i = 0;
         for(i = 1; i < sz(buf); ++i)
            if(buf[i]!='0') break;
         swap(buf[0],buf[i]);
      }
      sscanf(buf.c_str(),"%lld",&lo);
      sort(buf.rbegin(),buf.rend());
      sscanf(buf.c_str(),"%lld",&hi);
      x = hi - lo;
      printf("%lld - %lld = %lld = 9 * %lld\n",hi,lo,hi-lo,(hi-lo)/9LL);
   }   
   return 0;
}
/* @END_OF_SOURCE_CODE */
