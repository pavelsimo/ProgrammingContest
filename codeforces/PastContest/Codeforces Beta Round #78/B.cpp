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

int a[1024];

int main(int argc, char *argv[]) {
   int N, sum, avg;
   cin >> N;
   sum = 0;
   for(int i = 0; i < N; ++i) {
      cin >> a[i];
      sum+=a[i];
   }
   if(sum%N!=0) {
      puts("Unrecoverable configuration.");
   } else {
      avg = sum / N;
      int cnt = 0;
      for(int i = 0; i < N; ++i)
         if(a[i]!=avg) cnt++;
      if(cnt >= 3) {
         puts("Unrecoverable configuration.");
      } else if(cnt==0) {
         puts("Exemplary pages.");
      } else if(cnt==2) {
         int x1 = -1, x2 = -1;
         for(int i = 0; i < N; ++i) {
            if(a[i]==avg) continue;
            if(x1 >= 0 && a[i]!=a[x1]) x2 = i;
            if(x1 < 0) x1 = i;
         }
         if(a[x2] > a[x1]) swap(x1,x2);
         if(a[x1]-avg <= 0) puts("Unrecoverable configuration.");
         else printf("%d ml. from cup #%d to cup #%d.\n",a[x1]-avg,x2 + 1,x1 + 1);          
      }
   }
   return 0;
}
