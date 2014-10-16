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


int A[22];

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int TC, N;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      map<int, vector<int> > ans;
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) scanf("%d",&A[i]);
      int S = 1 << N;
      printf("Case #%d:\n",tc);
      bool found = false;
      for(int mask = 0; mask < S; ++mask) {
         int sum = 0;
         for(int j = 0; j < N; ++j) {
            if(mask & (1 << j))
               sum+=A[j];
         }
         ans[sum].push_back(mask);
         if(ans[sum].size() > 1) {
            int s1 = ans[sum][0];
            int s2 = ans[sum][1];
            bool first = true;
            for(int j = 0; j < N; ++j) {
               if(s1 & (1 << j)) {
                  if(!first) printf(" ");
                  printf("%d",A[j]);
                  first = false;
               }
                  
            }
            printf("\n");
            first = true;
            for(int j = 0; j < N; ++j) {
               if(s2 & (1 << j)) {
                  if(!first) printf(" ");
                  printf("%d",A[j]);
                  first = false;
               }   
            }
            printf("\n");
            found = true;
            break;
         }
      }
      if(!found) printf("Impossible\n");
   }
   return 0;
}
