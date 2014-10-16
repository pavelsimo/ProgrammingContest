/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11742  C++  "Brute Force, Permutations" */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


const int MAXN = 12;
int A[MAXN];
vector<pair<int,pair<int,int> > > edges;

int main(int argc, char *argv[]) {  
   int n, m, u, v, c, res;
   while(2 == scanf("%d%d",&n,&m)) {
      if(!n && !m) break;
      edges.clear();
      for(int i = 0; i < n; ++i)
         A[i] = i;
      for(int i = 0; i < m; ++i) {
         scanf("%d%d%d",&u,&v,&c);
         edges.push_back(make_pair(u,make_pair(v,c)));
      }
      res = 0;
      do {
         int i;
         for(i = 0; i < (int)edges.size(); ++i) {
            int p1 = find(A, A + n, edges[i].first) - A;
            int p2 = find(A, A + n, edges[i].second.first) - A;
            int dist = edges[i].second.second;
            if(dist > 0 && abs(p1 - p2) > dist) break;
            else if(dist < 0 && abs(p1 - p2) < abs(dist)) break;
         }
         if(i == (int)edges.size()) res++;
      } while(next_permutation(A, A + n));
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
