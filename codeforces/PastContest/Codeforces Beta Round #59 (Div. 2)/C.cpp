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

string guess[12];
int N, X[12], Y[12];

bool is_valid(string &ans, int ind) {
   int x = 0, y = 0;
   set<char> S(all(ans));
   for(int i = 0; i < 4; ++i) {
      if(ans[i] == guess[ind][i]) x++;
      else if(S.count(guess[ind][i])) y++;
   }
   return X[ind] == x && Y[ind] == y;
}

bool check(string &ans) {
   for(int i = 0; i < N; ++i)
      if(!is_valid(ans, i)) 
         return false;
   return true;
}

int main(int argc, char *argv[]) {
   string ans, s = "0000";
   cin >> N;
   for(int i = 0; i < N; ++i)
      cin >> guess[i] >> X[i] >> Y[i];
   int cnt = 0;
   for(int i = 0; i < 10; ++i) {
      for(int j = 0; j < 10; ++j) {
         if(j == i) continue;
         for(int k = 0; k < 10; ++k) {
            if(k == j || k == i) continue;
            for(int v = 0; v < 10; ++v) {
               if(v == i || v == j || v == k) continue;
               s[0] = '0' + i;  s[1] = '0' + j; s[2] = '0' + k; s[3] = '0' + v;
               if(check(s)) ans = s, cnt++;
            }
         }
      }
   }
   if(cnt == 0) cout << "Incorrect data" << endl;
   else if(cnt == 1) cout << ans << endl;
   else cout << "Need more data" << endl;
   return 0;
}
