/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12060  C++  "Ad Hoc, average" */
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

char buf[32];

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

int len(int n) {
   sprintf(buf,"%d",abs(n));
   return strlen(buf);
}

int main(int argc, char *argv[]) {
   int N, n, sum, a, b, c, hyphen_len, a_len, neg_len, div;
   int tc = 0;
   while(1 == scanf("%d",&N)) {
      if(!N) break;
      sum = 0;
      printf("Case %d:\n",++tc);
      for(int i = 0; i < N; ++i) {
         scanf("%d",&n);
         sum+=n;
      }
      if(sum % N == 0) {
         a = sum / N;
         if(a < 0) printf("- ");
         printf("%d\n",abs(a));
      } else if(abs(sum) >= N) {
         a = (sum - (sum%N)) / N;
         b = sum % N;
         c = N;
         div = gcd(b,c);
         b/=div; c/=div;
         hyphen_len = len(c);
         a_len = len(a);
         neg_len = ((sum<0)?2:0);
         printf("%*d\n",a_len + hyphen_len + neg_len,abs(b));
         if(sum < 0) printf("- ");
         printf("%d%s\n",abs(a),string(hyphen_len,'-').c_str());
         printf("%*d\n",a_len + hyphen_len + neg_len, abs(c));
      } else {
         b = sum;
         c = N;
         div = gcd(b,c);
         b/=div; c/=div;
         hyphen_len = len(c);
         neg_len = ((sum<0)?2:0);
         printf("%*d\n",hyphen_len + neg_len,abs(b));
         if(sum < 0) printf("- %s\n",string(hyphen_len,'-').c_str());
         else printf("%s\n",string(hyphen_len,'-').c_str());         
         printf("%*d\n",hyphen_len + neg_len,abs(c));
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
