#include <algorithm>
#include <iostream>

using namespace std;

#define sz(a) int((a).size())

bool isvowel(char ch) {
   return ch == 'a' || ch == 'e' || 
      ch == 'i' || ch == 'o' || ch == 'u';
}

int main(int argc, char *argv[]) { 
   int TC, N;
   string S;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> S >> N;
      int res = 0;
      for(int i = 0; i < sz(S); ++i) {
         for(int j = i; j < sz(S); ++j) {
            int cntC = 0;
            bool ok = false;
            for(int k = i; k <= j; ++k) {
               if(!isvowel(S[k])) cntC++;
               else cntC = 0;
               if(cntC >= N) {
                  ok = true;
                  break;
               }
            }
            if(ok) res++;
         }
      }
      cout << "Case #" << tc << ": " << res << endl;
   }
   return 0;
}
