/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12050  C++  "Palindrome Numbers, Binary Search" */
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
vector<llong> P;

void preproccess() {
   llong sum = 0;
   llong pow9 = 9;
   P.push_back(0LL);
   for(int i = 1, j = 2; i <= 25; ++i) {
      sum+=pow9;
      P.push_back(sum);
      j--;   
      if(j == 0) {
         pow9*=10;
         j = 2;
      }
   }
}

int main(int argc, char *argv[]) {
   preproccess();
   string ans;
   llong N;
   while(1 == scanf("%lld",&N)) {
      if(!N) break;
      int digits = lower_bound(all(P),N) - P.begin();
      llong x = N - P[digits - 1] - 1;
      ans = "";
      char ch = (x%10) + '0';
      if(digits & 1) {
         ans+=ch;
         x/=10LL;         
      }
      for(int d = digits - (digits&1); d > 0; d-=2) {
         if(d == 2) ch = (x%10) + '1';
         else ch = (x%10) + '0';
         ans.insert(ans.begin(),ch);
         ans.insert(ans.end(),ch);
         x/=10;
      }
      if(digits == 1) ans[0]++;  
      printf("%s\n",ans.c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
