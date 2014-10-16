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

int X[100002], Y[100002];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int M, N, A, B, a, b;
   cin >> M >> A;
   for(int i = 0; i < A; ++i) {
      cin >> a;
      X[a] = 1;
   }
   cin >> N >> B;
   for(int i = 0; i < B; ++i) {
      cin >> b;
      Y[b] = 1;
   }
   int p1 = 1, p2 = 1;
   while(p1 <= M) {
      if(X[p1]) {
         cout << "ENTER GUY " << p1 << endl;
         X[p1] = 0;
         p1++;
      } else {
         if(!X[p1]) {
            bool found = false;
            while(p2 <= N) {
               if(Y[p2]) {
                  cout << "GIVE GIRL " << p2 << " GUY " << p1 << endl;
                  Y[p2] = 0, X[p1] = 1;
                  found = true;
                  break;
               }
               p2++;
            }
            if(!found) {
               cout << "EXIT GUY " << p1 << endl;
               p1++;
            }
         }
      }
   } 
   return 0;
}

