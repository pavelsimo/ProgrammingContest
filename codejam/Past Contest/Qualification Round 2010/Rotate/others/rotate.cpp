#include <cstdio>

using namespace std;

int N, K;
char B[52][52];
char T[52][52];
void rotate() {
   for (int r = 0; r < N; ++r)
      for (int c = 0; c < N; ++c)
         T[r][c] = B[N-1-c][r];

   for (int r = 0; r < N; ++r)
      for (int c = 0; c < N; ++c)
         B[r][c] = T[r][c];
}

void fall() {
   for (int c = 0; c < N; ++c) {
      for (int r = N-1; r >= 0; --r) {
         if (B[r][c] != '.') continue;
         int rr;
         for (rr = r; rr >= 0 && B[rr][c] == '.'; --rr);
         if (rr >= 0) {
            B[r][c] = B[rr][c];
            B[rr][c] = '.';
         }
      }
   }
}

void print() {
   for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c)
         putchar(B[r][c]);
      putchar('\n');
   }
   putchar('\n');
}


int dr[] = {-1, -1, -1,  0,  0, +1, +1, +1};
int dc[] = {-1,  0, +1, -1, +1, -1,  0, +1};

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d %d", &N, &K);
      for (int i = 0; i < N; ++i)
         scanf("%s", &B[i]);

//      print();

      rotate();

//     print();

      fall();

//      print();

      int winner = 0;
      for (int r = 0; r < N; ++r)
         for (int c = 0; c < N; ++c) {
            char ch = B[r][c];
            if (ch == '.') continue;
            for (int d = 0; d < 8; ++d) {
               int k;
               for (k = 0; k < K; ++k) {
                  int nr = r + dr[d]*k, nc = c + dc[d]*k;
                  if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                     break;
                  if (B[nr][nc] != ch)
                     break;
               }
               if (k >= K)
                  if (ch == 'B') {
                     winner |= 1;
                  //   printf("Blue %d %d  %d %d %d\n", r, c, d, dr[d], dr[c]);
                  }
                  else {
                     winner |= 2;
                  //   printf("Red %d %d  %d %d %d\n", r, c, d, dr[d], dr[c]);
                  }
            }
         }
      printf("Case #%d: ", tc);
      switch (winner) {
         case 0: puts("Neither"); break;
         case 1: puts("Blue"); break;
         case 2: puts("Red"); break;
         default: puts("Both");
      }
   }
   return 0;
}
