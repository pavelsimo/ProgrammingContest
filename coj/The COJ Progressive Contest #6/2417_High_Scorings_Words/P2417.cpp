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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

inline bool is_vowel(char ch) {
   return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

inline int get_score(char *S, int N) {
   int v_cnt = 0, c_cnt = 0;
   int score = 0;
   for(int i = 0; i < N; ++i) {
      if(is_vowel(S[i])) v_cnt++;
      else c_cnt++;
      if(i + 1 < N)
         score += abs(S[i] - S[i + 1]);
   }
   if((v_cnt & 1) || (c_cnt & 1)) return -1;
   if(v_cnt != c_cnt) return -1;
   return score;
}

const int MAXN = 24;
char buf[64], X[MAXN], S[MAXN], res[MAXN];
const int MAX_C = 1 << 20;

int main(int argc, char *argv[]) { 
   vector<int> T;
   for(int i = 1; i < MAX_C; ++i) {
      if(__builtin_popcount(i) & 1) continue;
      T.push_back(i);
   }
   int TC, C, best, N, M, score;
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      gets(buf);
      sscanf(buf,"%d",&C);
      gets(buf);
      for(int i = 0; i < C; ++i)
         X[i] = buf[i * 2];
      sort(X, X + C);
      res[0] = '\0';
      best = -1;
      N = (1 << C);
      for(int i = 0; i < sz(T); ++i) {
         if(T[i] > N) break;
         M = 0;
         for(int j = 0; j < C; ++j) {
            if(T[i] & (1 << j)) 
               S[M++] = X[j];
         }
         S[M] = '\0';
         score = get_score(S, M);
         if(score > best) {
            strcpy(res, S);
            best = score;               
         } else if(score >= 0 && score == best 
            && strcmp(S, res) < 0) {
            strcpy(res, S);
         }
      }
      if(best >= 0) printf("%s %d\n",res, best);
      else puts("-1");
   }
   return 0;
}
