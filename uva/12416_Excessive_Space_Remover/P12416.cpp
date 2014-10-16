/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12416  C++  "Ad hoc, Math, String" */
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {  
   string s;
   int k, n, best, res;
   while(getline(cin, s)) {
      n = s.size();
      best = res = k = 0;
      for(int i = 0; i < n; ++i) {
         k = isspace(s[i]) ? k + 1: 0;
         best = max(best, k);
      }
      for(int pow2 = 1; pow2 < best; pow2*=2)
         res++;
      printf("%d\n",res);
   }   
   return 0;
}
/* @END_OF_SOURCE_CODE */
