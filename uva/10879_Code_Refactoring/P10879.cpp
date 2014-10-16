/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10879  C++  "Math, Number Theory, Factors" */
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> ans[2];

int main(int argc, char *argv[]) {  
   int TC, n, k, m;
   scanf("%d",&TC);   
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&n);
      k = 0;
      m = (int)sqrt(n);
      for(int i = 2; i <= m; ++i) {
         if(n % i == 0 && i != n/i)
            ans[k++] = make_pair(i, n / i);
         if(k == 2) break;         
      }
      printf("Case #%d: %d = %d * %d = %d * %d\n", tc, n, ans[0].first, ans[0].second, ans[1].first, ans[1].second);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
