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

int F[10];
int memo[2][5][5][5][5][5][5];
const string lbl[] = {"A","B"};

int rec(int player, int f1, int f2, int f3, int f4, int f5, int f6) {
   if(f1*1 + f2*2 + f3*3 + f4*4 + f5*5 + f6*6 > 31) 
      return 1; 
   if(memo[player][f1][f2][f3][f4][f5][f6] != -1) 
      return memo[player][f1][f2][f3][f4][f5][f6];
   int res = 0;
   if(f1 <= 3) res|=!rec(player^1, f1 + 1, f2, f3, f4, f5, f6);
   if(f2 <= 3) res|=!rec(player^1, f1, f2 + 1, f3, f4, f5, f6);
   if(f3 <= 3) res|=!rec(player^1, f1, f2, f3 + 1, f4, f5, f6);
   if(f4 <= 3) res|=!rec(player^1, f1, f2, f3, f4 + 1, f5, f6);
   if(f5 <= 3) res|=!rec(player^1, f1, f2, f3, f4, f5 + 1, f6);
   if(f6 <= 3) res|=!rec(player^1, f1, f2, f3, f4, f5, f6 + 1);
   return memo[player][f1][f2][f3][f4][f5][f6] = res;
}

int main(int argc, char *argv[]) {   
   int player;
   string s;
   while(cin >> s) {
      player = 1;
      memset(F,0,sizeof(F));
      memset(memo,-1,sizeof(memo));
      for(int i = 0; i < sz(s); ++i) {
         player^=1;
         ++F[s[i]-'0'];
      }
      if(rec(player,F[1],F[2],F[3],F[4],F[5],F[6])) player^=1;
      printf("%s %s\n",s.c_str(),lbl[player].c_str());
   }   
   return 0;
}

