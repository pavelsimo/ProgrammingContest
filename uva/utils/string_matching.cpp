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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int MAXN = 128;
int b[MAXN];  
//char P[MAXN], T[MAXN];
char P[MAXN] = "abcd";
char T[MAXN] = "abcd";
int N, M;

void kmp_preprocess() {
   int i = 0, j = -1;
   b[0] = j;
   while(i < M) {
      while(j >= 0 && P[i] != P[j]) j = b[j];
      ++j; ++i;
      b[i] = j;
   }
   //for(i = 0; i <= M; ++i) DEBUG(b[i]);
   //DEBUG(N - b[M]);
}

void kmp_search() {
   int i = 0, j = 0;
   while(i < N) {
      while(j >= 0 && T[i]!=P[j]) j = b[j];
      ++j; ++i;
      if(j == M) {
         //printf("P is found at index: %d\n",i - j);
         j = b[j];
      }      
   }
}


int main(int argc, char *argv[]) {
   N = strlen(T);
   M = strlen(P);
   kmp_preprocess();
   kmp_search();
   return 0;
}
// END CUT HERE
