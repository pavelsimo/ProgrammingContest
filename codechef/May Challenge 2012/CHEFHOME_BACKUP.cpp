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

const llong INF = 1LL << 60LL;
set<int> PX, PY;
vector<int> AX, AY;
int X[1024], Y[1024];
llong S[1024];

int main(int argc, char *argv[]) {
   int TC, N;
   llong res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      PX.clear(); PY.clear(); AX.clear(); AY.clear();
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) {
         scanf("%d%d",&X[i],&Y[i]);
         PX.insert(X[i]); PY.insert(Y[i]);
      }
      vector<llong> X1(all(PX));
      vector<llong> Y1(all(PY));
      res = INF;
      int best = 0;
      for(int i = 0; i < sz(X1); ++i) {
         llong sum = 0;
         for(int k = 0; k < N; ++k) sum+=abs(X1[i]-X[k]);
         AX.push_back(sum);
      }
      for(int i = 0; i < sz(Y1); ++i) {
         llong sum = 0;
         for(int k = 0; k < N; ++k) sum+=abs(Y1[i]-Y[k]);
         AY.push_back(sum);
      }      
      for(int i = 0; i < sz(X1); ++i) {
         for(int j = 0; j < sz(Y1); ++j) {
            llong dist = AX[i] + AY[j];
            if(dist < res) {
               best = 1;
               res = dist;
            } else if(dist == res) {
               best++;
            }
         }
      }
      DEBUG(res);
      printf("%d\n",best);
   }
   return 0;
}
