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

typedef pair<int,int> PII;
char B[1010][1010];
int acc[1010][1010];
int dx[] = {+0,+0,-1,+1};
int dy[] = {-1,+1,+0,+0};
const string dir = "NSEO";

int main(int argc, char *argv[]) {
   int N, M, K, steps;
   char ch_dir;
   vector<int> S;
   scanf("%d%d",&N,&M);
   for(int i = 0; i < N; ++i) {
      scanf("%s",B[0]);
      for(int j = 0; j < M; ++j) {
         if(B[i][j] >= 'A' && B[i][j] <= 'Z') {
            S.push_back(make_pair(i,j));
         }
      }
   }
   
   scanf("%d",&K);
   for(int i = 0; i < K; ++i) {
      scanf("%c %d",&ch_dir,&steps);
      /*
      int d = dir.find(ch_dir);
      for(int j = 0; j < sz(S); ++j) {
         
         
         
      }
      */
   }
   return 0;
}

