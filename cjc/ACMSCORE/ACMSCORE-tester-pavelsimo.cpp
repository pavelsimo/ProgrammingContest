#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 1002;
int T[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int TC, D, P, n, t_elapsed, penalty;
   cin >> TC;
   
   assert(TC <= 1000);
   
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> D >> P;
      for(int i = 0; i < P; ++i) {
         cin >> T[i];
         assert(T[i] >= 1 && T[i] <= 1000);
      }
         
      assert(P >= 1 && P <= 15);
      assert(D >= 60 && D <= 300 && D % 10 == 0);
      
      sort(T, T + P);
      
      t_elapsed = 5;
      penalty = 0;
      for(n = 0; n < P; ++n) {
         if(t_elapsed + T[n] > D) break;
         t_elapsed += T[n];
         penalty += t_elapsed;
      }
      cout << "Case #" << tc << ": " << n << " " << penalty << endl;
   }
   return 0;
}

