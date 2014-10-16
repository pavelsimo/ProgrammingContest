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

char board[2000][2000];

int main(int argc, char *argv[]) {
   int N, M;
   scanf("%d%d",&N,&M);
   for(int i = 0; i < N; ++i) {
      scanf("%s",board[i]);
      //puts(board[i]);
   }
   int res = -1;
   int cnt = 2;
   for(int i = 0; i < M; ++i) {
      for(int j = N-2; j >= 0; --
      if(board[0][i] == '.' && board[N-1][i] == '.') {
         cout << 2 << endl;
         return 0;  
      }
   }
   cout << res << endl;
   return 0;
}

