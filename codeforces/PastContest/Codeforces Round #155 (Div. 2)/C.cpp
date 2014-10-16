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

const int MAXN = 26;
int freq[MAXN];
int D[100020][MAXN];

int main(int argc, char *argv[]) { 
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
   string A, B;
   cin >> A >> B;
   for(int i = 0, j = sz(A) - 1; i < sz(A); ++i, --j) {
      freq[A[i] - 'A']++, freq[B[i] - 'A']--;
      for(int k = 0; k < MAXN; ++k)
         D[j][k] = D[j][k];
      D[j][A[i]-'A']++;
   }
   int res = 0;
   for(int i = 0; i < sz(A); ++i) {
      int ind_ch = A[i] - 'A';
      if(freq[ind_ch]) {
         for(int j = 0; j < MAXN; ++j) {
            if(ind_ch == j) continue;
            if(freq[j] < 0) {
               if(j < ind_ch) {
                  res++;
                  A[i] = ('A' + j);
                  freq[j]++;
                  freq[ind_ch]--;
               } else {
                  if(D[i][ind_ch] < freq[ind_ch]) {
                     res++;
                     A[i] = ('A' + j);
                     freq[j]++;
                     freq[ind_ch]--;                     
                  }                  
               }
            }
         }
      }
   }
   cout << res << endl;
   cout << A << endl;
   return 0;
}
