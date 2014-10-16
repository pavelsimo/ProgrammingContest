/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11776  C++  "Sorting, intervals collisions" */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<pair<int,int> > X;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
   if(a.second != b.second) return a.second < b.second;
   return a.first < b.first;
}

int main(int argc, char *argv[]) {  
   int N, u, v, res, cnt;
   while(1 == scanf("%d",&N)) {
      if(N == -1) break;
      X.clear();
      for(int i = 0; i < N; ++i) {
         scanf("%d%d",&u,&v);
         X.push_back(make_pair(u,v));
      }
      sort(X.begin(), X.end(), cmp);
      cnt = 1; res = 0;
      //int mi = X[0].second;
      printf("%d %d *\n", X[0].first, X[0].second);
      for(int i = 1; i < N; ++i) {
         //mi = min(mi, X[i].second);
         if(X[i].second >= X[i - 1].first) {
            printf("%d %d\n", X[i].first, X[i].second);
            
            
         } else {
            cnt = 1;
         }
      }
      cout << res << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
