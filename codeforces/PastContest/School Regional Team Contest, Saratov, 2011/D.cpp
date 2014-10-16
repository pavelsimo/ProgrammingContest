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

int board[55][55], rows[55], cols[55];

bool check(int a, int b, int c, int A, int B, int C) {
   vector<int> x, y; 
   x.push_back(a); x.push_back(b); x.push_back(c);
   y.push_back(A); y.push_back(B); y.push_back(C);
   sort(all(x));
   sort(all(y));
   return x[0]==y[0] && x[1]==y[1] && x[2]==y[2];
}

int main(int argc, char *argv[]) {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int N, M, A, B, C;
   memset(rows,0,sizeof(rows));
   memset(cols,0,sizeof(cols));
   scanf("%d%d",&N,&M);
   int res = 0;
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < M; ++j) {   
         scanf("%d",&board[i][j]);
      }
   }
   scanf("%d%d%d",&A,&B,&C);
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < M; ++j) {   
         rows[i]+=board[i][j];
      }
   }
   for(int j = 0; j < M; ++j) {
      for(int i = 0; i < N; ++i) {
         cols[j]+=board[i][j];
      }
   }
   for(int i = 1; i < N; ++i) {
      for(int j = i+1; j < N; ++j) {
         int a = 0, b = 0, c = 0;
         for(int k = 0; k < i; ++k) a+=rows[k];
         for(int k = i; k < j; ++k) b+=rows[k];
         for(int k = j; k < N; ++k) c+=rows[k];
         if(check(a,b,c,A,B,C)) res++;
      }
   }
   for(int i = 1; i < M; ++i) {
      for(int j = i+1; j < M; ++j) {
         int a = 0, b = 0, c = 0;
         for(int k = 0; k < i; ++k) a+=cols[k];
         for(int k = i; k < j; ++k) b+=cols[k];
         for(int k = j; k < M; ++k) c+=cols[k];
         if(check(a,b,c,A,B,C)) res++;
      }
   }
   cout << res << endl;
   return 0;
}
/* @END_OF_SOURCE_CODE */
