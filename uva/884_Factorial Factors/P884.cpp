/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  884  C++  "Math, Factorial" */
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

const int MAXN = 1000000;
int A[MAXN+10];

void sieve() {
   memset(A,0,sizeof(A));
   for(int i = 2; i <= MAXN; ++i) {
      if(!A[i]) {
         for(int j = i; j <= MAXN; j+=i) { 
            int x = j;
            while(x % i == 0) {
               A[j]++;
               x/=i;
            }   
         }
      }  
   }
   for(int i = 2; i <= MAXN; ++i) 
      A[i]+=A[i-1];
}


int main(int argc, char *argv[]) {
   sieve();
   int n;
   while(1 == scanf("%d",&n)) {
      printf("%d\n",A[n]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
