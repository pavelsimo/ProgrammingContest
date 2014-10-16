/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10887  C++  "Ad hoc, String, Brute Force" */
#include <cstdio>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

string X[2002], Y[2002];
int main(int argc, char *argv[]) {  
   int TC, n, m;
   string buf;
   getline(cin, buf);
   sscanf(buf.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      getline(cin, buf);
      sscanf(buf.c_str(),"%d%d",&n,&m);
      set<string> S;
      for(int i = 0; i < n; ++i)
         getline(cin, X[i]);
      for(int i = 0; i < m; ++i)
         getline(cin, Y[i]);
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < m; ++j) {
            S.insert(X[i] + Y[j]);
         }
      }
      cout << "Case " << tc << ": " << S.size() << "\n";
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
