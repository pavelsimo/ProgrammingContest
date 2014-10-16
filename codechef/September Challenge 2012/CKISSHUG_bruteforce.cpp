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


void print_set(int X, int N) {
   printf("%02d: ", X);
   for(int i = 0; i < N; ++i)
      printf("%d", X & (1<<i) ? 1: 0);
   printf("\n");
}

bool check(int X, int N) {
   bool flag = true;
   for(int i = 0; i < N; ++i) {
      if(flag && X & (1<<i)) {
         flag = false;
         for(int j = i + 2; j < N; j+=2)
            if(!(X & (1<<j))) 
               return false;
      }
   }
   return true;
}

int main(int argc, char *argv[]) {  
   int N = 12;
   for(int k = 1; k <= N; ++k) {
      int cnt = 0;
      for(int mask = 0; mask < (1<<k); ++mask) {
         if(check(mask, k)) {
            //print_set(mask,k);
            cnt++;
         }
      }
      printf("f(%d) = %d\n",k, cnt);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
