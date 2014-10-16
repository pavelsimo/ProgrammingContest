/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11512  C++  "Suffix Array" */
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

const int MAXN = 1024;

char buf[MAXN];
int S[MAXN], N;

bool cmp(const int i, const int j) {
   return strcmp(buf + i, buf + j) < 0;
}

int main(int argc, char *argv[]) {
	int TC, res, best, prev, ma_rep;
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      gets(buf);
      N = strlen(buf);
      for(int i = 0; i < N; ++i)
         S[i] = i;
      sort(S, S + N, cmp);
      ma_rep = best = res = prev = 0;
      for(int i = 1; i < N; ++i) {
         int M = min(N - S[i], N - S[i-1]);
         int j;
         for(j = 0; j < M; ++j)
            if(*(buf + S[i] + j) != *(buf + S[i-1] + j)) 
               break;
         if(j > res) {
            res = j;
            best = S[i];
            ma_rep = 2;
         } else if(j == res && j == prev) {
            ++ma_rep;
         }
         prev = j;
      }
      if(res >= 1) {
         for(int i = 0; i < res; ++i)
            printf("%c",*(buf + best + i));
         printf(" %d\n",ma_rep);
      } else {
         printf("No repetitions found!\n");
      }
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */

