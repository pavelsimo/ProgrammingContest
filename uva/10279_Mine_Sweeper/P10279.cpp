/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10279  C++  "Ad Hoc" */
#include <algorithm>
#include <cstdio>
#include <cstring>

char buf[128], board[16][16], played[16][16], ans[16][16];
int di[] = {+1,+0,-1,+0,+1,-1,+1,-1};
int dj[] = {+0,+1,+0,-1,+1,-1,-1,+1};

int main(int argc, char *argv[]) {
   int TC, N;
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      gets(buf);
      gets(buf);
      memset(ans, 0, sizeof(ans));
      sscanf(buf,"%d",&N);
      for(int i = 0; i < N; ++i)
         gets(board[i]);
      for(int i = 0; i < N; ++i)
         gets(played[i]);      
      int ok = 1;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            if(played[i][j] == 'x' && board[i][j] == '*') 
               ok = 0;
            ans[i][j] = 0;
            if(board[i][j] == '.') {
               for(int dir = 0; dir < 8; ++dir) {
                  int ni = i + di[dir];
                  int nj = j + dj[dir];
                  if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                  ans[i][j] += board[ni][nj] == '*';
               }               
            }
         }
      }
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            if(!ok && board[i][j] == '*') printf("*");
            else if(played[i][j] == 'x') printf("%d",ans[i][j]);
            else printf(".");
         }
         printf("\n");
      }
      if(TC) printf("\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
