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

int A[200];
vector<string> S;

int main(int argc, char *argv[]) { 
   int N, M, res = 0;
   string grades;
   cin >> N >> M;
   memset(A,0,sizeof(A));
   for(int i = 0; i < N; ++i) {
      cin >> grades;
      S.push_back(grades);
      for(int j = 0; j < M; ++j) {
         A[j] = max(A[j], S[i][j] - '0');
      }
   }
   for(int i = 0; i < N; ++i) {
      int cnt = 0;
      for(int j = 0; j < M; ++j)
         if(S[i][j] - '0' >= A[j]) 
            cnt++;
      if(cnt > 0) res++;
   }
   printf("%d\n",res);
   return 0;
}

