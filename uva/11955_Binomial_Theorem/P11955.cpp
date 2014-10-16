/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11955  C++  "Ad Hoc" */
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

const int MAXN = 55;
typedef long long llong;
llong nCr[MAXN][MAXN];
string buf, a, b;

void preproccess() {
   nCr[0][0] = 1;
   for(int i = 1; i < MAXN; ++i) {
      for(int j = 0; j <= i; ++j) {
         if(j - 1 >= 0) 
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
         else
            nCr[i][j] = 1;
      }  
   }
}

int main(int argc, char *argv[]) {
   preproccess();
   int TC, n;
   size_t p1, p2, p3;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      getline(cin,buf);
      p1 = buf.find('+');
      p2 = buf.find(')');
      p3 = buf.find('^');
      a = buf.substr(1,p1-1);
      b = buf.substr(p1+1,p2-p1-1);
      n = atoi(buf.substr(p3+1).c_str());
      printf("Case %d: ",tc);
      for(int k = 0; k <= n; ++k) {
         if(k > 0) putchar('+');
         
         if(nCr[n][k] > 1) printf("%lld*",nCr[n][k]);
         
         if(n-k == 1) printf("%s",a.c_str());
         else if(n-k > 1) printf("%s^%d",a.c_str(),n-k);
         
         if(n-k > 0 && k > 0) putchar('*');
         
         if(k == 1) printf("%s",b.c_str());
         else if(k > 1) printf("%s^%d",b.c_str(),k);
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
