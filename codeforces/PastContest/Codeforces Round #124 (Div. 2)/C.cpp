#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define sz(a) int((a).size())

vector<int> a[26];
int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   string s, res = "";
   cin >> s;
   for(int i = 0; i < sz(s); ++i)
      a[s[i]-'a'].push_back(i);
   int ind = -1;
   for(int i = 25; i >= 0; --i) {
      for(int j = 0; j < sz(a[i]); ++j) {
         if(a[i][j] > ind) res+=(char)('a' + i);
         ind = max(ind, a[i][j]);
      }
   }
   cout << res << endl;
   return 0;
}
