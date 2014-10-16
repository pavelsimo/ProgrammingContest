/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  256  C++  "Brute Force" */
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

int lo[] = {0,0,0,0,3,0,8,0,13};
int hi[] = {0,0,3,0,8,0,13,0,22};

char res[30][10] = {"00","01","81",
   "0000","0001","2025","3025","9801",
   "000000","000001","088209","494209","998001",
   "00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001" };

void preproccess() {
   // 2-digits
   for(int a = 0; a <= 9; ++a)
   for(int b = 0; b <= 9; ++b) {
      int t1 = a + b;
      int x1 = t1*t1;
      int x2 = a*10 + b;
      if(x1 == x2) {
         printf("%02d\n",x1);
      }
   }
   // 4-digits
   for(int a = 0; a <= 9; ++a)
   for(int b = 0; b <= 9; ++b)
   for(int c = 0; c <= 9; ++c)
   for(int d = 0; d <= 9; ++d) {
      int t1 = a*10 + b + c*10 + d;
      int x1 = t1*t1;
      int x2 = a*1000 + b*100 + c*10 + d;
      if(x1 == x2) {
         printf("%04d\n",x1);
      }
   }
   // 6-digits
   for(int a = 0; a <= 9; ++a)
   for(int b = 0; b <= 9; ++b)
   for(int c = 0; c <= 9; ++c)
   for(int d = 0; d <= 9; ++d)
   for(int e = 0; e <= 9; ++e)
   for(int f = 0; f <= 9; ++f) {
      int t1 = a*100 + b*10 + c + d*100 + e*10 + f;
      int x1 = t1*t1;
      int x2 = a*100000 + b*10000 + c*1000 + d*100 + e*10 + f;
      if(x1 == x2) {
         printf("%06d\n",x1);
      }
   }
   // 8-digits
   for(int a = 0; a <= 9; ++a)
   for(int b = 0; b <= 9; ++b)
   for(int c = 0; c <= 9; ++c)
   for(int d = 0; d <= 9; ++d)
   for(int e = 0; e <= 9; ++e)
   for(int f = 0; f <= 9; ++f)
   for(int g = 0; g <= 9; ++g)
   for(int h = 0; h <= 9; ++h) {
      int t1 = a*1000 + b*100 + c*10 + d + e*1000 + f*100 + g*10 + h;
      int x1 = t1*t1;
      int x2 = a*10000000 + b*1000000 + c*100000 + d*10000 + e*1000 + f*100 + g*10 + h;
      if(x1 == x2) {
         printf("%08d\n",x1);
      }
   }   
}

int main(int argc, char *argv[]) {
   //preproccess();
   int N;
   while(1==scanf("%d",&N)) {
      for(int i = lo[N]; i < hi[N]; ++i)
         puts(res[i]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
