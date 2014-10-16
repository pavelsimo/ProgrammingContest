/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11729  C++  "Greedy, Sorting" */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int main(int argc, char *argv[]) {
   int N, b, j, sum, res;
   for(int tc = 1; 1 == scanf("%d",&N); ++tc) {
      if(!N) break;
      vector<pair<int,int> > S;
      for(int i = 0; i < N; ++i) {
         scanf("%d%d",&b,&j);
         S.push_back(make_pair(-j, b));
      }
      sort(all(S));
      res = sum = 0;
      for(int i = 0; i < N; ++i) {
         sum += S[i].second;
         res = max(res, sum + -S[i].first);
      }
      printf("Case %d: %d\n",tc, res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
