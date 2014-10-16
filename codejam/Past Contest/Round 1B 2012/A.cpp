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

const double EPS = 1e-6;
int J[502];
double ans[502];

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int TC, N;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      printf("Case #%d: ",tc);
      scanf("%d",&N);
      double X = 0, X2 = 0;
      for(int i = 0; i < N; ++i) {
         scanf("%d",&J[i]);   
         X+=J[i];
      }
      double p = (X * 1.0) / N;
      for(int i = 0; i < N; ++i)
         X2+=J[i]+p; 
      double p2 = (X2 * 1.0) / N;
      for(int i = 0; i < N; ++i) { 
         ans[i] = (p2 - J[i]) / X;
         if(i > 0) putchar(' ');
         printf("%.6lf",ans[i]*100.0);
      }
      printf("\n");
   }
   return 0;
}
