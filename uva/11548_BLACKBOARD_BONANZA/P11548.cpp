/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11548  C++  "String, Substrings" */
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 74;
char dict[MAXN][MAXN];
int sz[MAXN];

int get_best_alignment(int si, int sj) {
   int res = 0, N = sz[si], M = sz[sj];
   char *s1 = dict[si], *s2 = dict[sj];
   for(int i = 0; i < M; ++i) {
      int cnt = 0;
      int k = i;
      for(int j = 0; j < N; ++j) {
         if(k >= M) k = 0, cnt = 0;
         if(s1[j] == s2[k]) cnt++;
         res = max(res, cnt);
         k++;
      }
   }
   return res;
}

int main(int argc, char *argv[]) { 
   int TC, n, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      for(int i = 0; i < n; ++i) {
         scanf("%s",dict[i]);
         sz[i] = strlen(dict[i]);
      }
      res = 0;
      for(int i = 0; i < n - 1; ++i) {
         for(int j = i + 1; j < n; ++j) {
            res = max(res, get_best_alignment(i, j));
         }
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
