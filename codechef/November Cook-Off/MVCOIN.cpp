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

const int MAXN = 1020;
int A[MAXN];
int N, K;

int get_next(int 

int main(int argc, char *argv[]) {
   int TC, ind;
   scanf("%d",&TC);
   while(TC-- > 0) {
      memset(A,0,sizeof(A));
      scanf("%d%d",&N,&K);
      for(int i = 0; i < N; ++i) {
         scanf("%d",&ind);
         A[ind] = 1;
      }
      
   }
   return 0;
}

