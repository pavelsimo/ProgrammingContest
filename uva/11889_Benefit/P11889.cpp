/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11889  C++  "LCM, Math, Number Theory" */
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

const int MAXN = 5000002;
vector<int> primes;
bool P[MAXN];

void sieve() {
   memset(P,false,sizeof(P));
   P[0] = true;
   P[1] = true;
   for(int i = 2; i < MAXN; ++i) {
      if(!P[i]) {
         primes.push_back(i);
         for(int j = i + i; j < MAXN; j+=i) 
            P[j] = true;
      }
   }   
}

int power(int n, int exp) {
   if(!exp) return 1;
   if(exp & 1) {
      return n * power(n, exp - 1);
   } else {
      int t = power(n, exp >> 1);
      return t*t;      
   }
}

int main(int argc, char *argv[]) {
   int TC, A, B, C;
   int a, c, fa, fc;
   sieve();
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&A,&C);
      if(C % A == 0) {
         a = A; B = 1; c = C; 
         for(int i = 0; primes[i]*primes[i] <= C; ++i) {
            fa = fc = 0;
            while(c % primes[i] == 0) {
               fc++;
               c/=primes[i];
            }
            while(a % primes[i] == 0) {
               fa++;
               a/=primes[i];
            }         
            if(fc > fa) B*=power(primes[i],fc);
         }
         if(c > 1 && a == 1) B*=c;
         printf("%d\n",B);
      } else {
         puts("NO SOLUTION");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
