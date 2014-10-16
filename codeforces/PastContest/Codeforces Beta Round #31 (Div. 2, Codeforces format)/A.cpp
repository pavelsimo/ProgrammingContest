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

int a[102];
int main(int argc, char *argv[]) { 
   int n;
   scanf("%d",&n);
   for(int i = 0; i < n; ++i)
      scanf("%d",&a[i]);
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
         if(i == j) continue;
         for(int k = 0; k < n; ++k) {
            if(j == k) continue;
            if(a[i] == a[j] + a[k]) {
               printf("%d %d %d\n",i+1,j+1,k+1);
               return 0;
            }
         }   
      }
   }
   printf("-1\n");
   return 0;
}

