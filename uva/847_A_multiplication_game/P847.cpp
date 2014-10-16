/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  847  C++  "Game Theory" */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

llong n;

bool rec(llong p) {
   if(p >= n) 
      return false;
   return !rec(p * 9LL) || !rec(p * 2LL);
}

int main(int argc, char *argv[]) {
   while(1 == scanf("%lld", &n)) {
      if(rec(1LL)) puts("Stan wins.");
      else puts("Ollie wins.");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
