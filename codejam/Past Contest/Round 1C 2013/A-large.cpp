#include <algorithm>
#include <iostream>

using namespace std;

typedef long long llong;

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
      llong res = 0LL, p = -1;
      int cntC = 0;
      for(int i = 0; i < sz(S); ++i) {      
         if(!isvowel(S[i])) cntC++;
         else cntC = 0;
         if(cntC >= N) {
            llong l = i - N + 1 - p;
            llong r = sz(S) - i;
            res += l * r;
            p = i - N + 1;
         }
      }
      cout << "Case #" << tc << ": " << res << endl;
   }
   return 0;
}
