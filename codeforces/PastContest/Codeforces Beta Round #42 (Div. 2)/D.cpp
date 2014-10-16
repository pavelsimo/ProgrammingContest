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

int main(int argc, char *argv[]) {
   int n, m;
   scanf("%d%d",&n,&m);
   if(n == 1 && m == 2) {
      printf("0\n");
      printf("1 1\n");
      printf("1 2\n");
      printf("1 1\n");
   } else if(n == 2 && m == 1) {
      printf("0\n");
      printf("1 1\n");
      printf("2 1\n");
      printf("1 1\n");      
   } else if(n == 1) { 
      printf("1\n");
      printf("1 %d 1 1\n",m);
      for(int j = 1; j <= m; ++j)
         printf("1 %d\n",j);
      printf("1 1\n");
   } else if(m == 1) { 
      printf("1\n");
      printf("%d 1 1 1\n",n);
      for(int i = 1; i <= n; ++i)
         printf("%d 1\n",i);
      printf("1 1\n");
   } else if(n % 2 == 0) {
      printf("0\n");
      for(int i = 1; i <= n; ++i) {
         int k = ((i != 1) && (i != n));
         if(i & 1) {
            for(int j = 1 + k; j <= m; ++j)
               printf("%d %d\n",i, j);            
         } else {
            for(int j = m; j >= 1 + k; --j)
               printf("%d %d\n",i, j);            
         }
      }
      for(int i = n - 1; i >= 1; --i)
         printf("%d 1\n",i);
   } else if(m % 2 == 0) {
      printf("0\n");
      for(int j = 1; j <= m; ++j) {
         int k = ((j != 1) && (j != m));
         if(j & 1) {
            for(int i = 1 + k; i <= n; ++i)
               printf("%d %d\n",i, j);            
         } else {
            for(int i = n; i >= 1 + k; --i)
               printf("%d %d\n",i, j);            
         }
      }
      for(int j = m - 1; j >= 1; --j)
         printf("1 %d\n",j);   
   } else {
      printf("1\n");
      printf("%d %d 1 1\n",n,m);
      for(int i = 1; i <= n; ++i) {
         if(i & 1) {
            for(int j = 1; j <= m; ++j)
               printf("%d %d\n",i,j);
         } else {
            for(int j = m; j >= 1; --j)
               printf("%d %d\n",i,j);
         }
      }
      printf("1 1\n");
   }
   return 0;
}

