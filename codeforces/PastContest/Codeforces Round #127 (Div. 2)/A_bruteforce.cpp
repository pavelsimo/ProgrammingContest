#include <iostream>

using namespace std;

bool ispal(const string &s) {
   int lo = 0, hi = s.size() - 1;
   while(lo < hi) {
      if(s[lo] != s[hi]) return false;
      lo++;
      hi--;
   }
   return true;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   string s, res = "";
   cin >> s;
   int n = s.size();
   for(int i = 0; i < (1 << n); ++i) {
      string cur = "";
      for(int j = 0; j < n; ++j) {
         if(i & (1 << j)) 
            cur+=s[j];
      }
      if(ispal(cur) && cur > res) 
         res = cur;
   }
   cout << res << endl;
   return 0;
}

