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

const int MAXN = 1000020;
int b[MAXN];  
string P;
string T;
int N, M;

void kmp_preprocess() {
   int i = 0, j = -1;
   b[0] = j;
   while(i < M) {
      while(j >= 0 && P[i] != P[j]) j = b[j];
      ++j; ++i;
      b[i] = j;
   }
}

bool kmp_search() {
   int i = 1, j = 0;
   while(i < N-1) {
      while(j >= 0 && T[i]!=P[j]) j = b[j];
      ++j; ++i;
      if(j == M) {
         j = b[j];
         return true;
      }      
   }
   return false;
}

int main(int argc, char *argv[]) {
   cin >> T;
   P = T;
   M = sz(P);
   N = sz(T);
   kmp_preprocess();
   int j = M;
   bool found = false;
   while(j >= 0) {
      P = T.substr(0,b[j]);
      M = sz(P);
      if(M > 0 && kmp_search()) {
         found = true;
         break;
      }
      j = b[j];
   }
   if(found) puts(P.c_str());
   else puts("Just a legend");
   return 0;
}

