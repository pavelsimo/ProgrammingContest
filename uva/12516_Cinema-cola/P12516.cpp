/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12516  C++  "Ad Hoc" */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int B[32][128], used[32][128];
string buf;

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int R, C, P, Z, cn;
   char rch, dir;
   while(getline(cin, buf)) {
      sscanf(buf.c_str(), "%d%d",&R,&C);
      if(!R && !C) break;
      memset(B, 0, sizeof(B));
      memset(used, 0, sizeof(used));
      getline(cin, buf);
      sscanf(buf.c_str(),"%d",&P);
      while(P-- > 0) {
         getline(cin, buf);
         sscanf(buf.c_str(),"%c%d %c",&rch,&cn,&dir);
         int r = rch - 'A';
         int c = cn;
         if(dir == '-') B[r][c-1] = 1;
         else B[r][c] = 1;
      } 
      getline(cin, buf);
      sscanf(buf.c_str(),"%d",&Z);
      while(Z-- > 0) {
         getline(cin, buf);
         sscanf(buf.c_str(),"%c%d",&rch,&cn);
         int r = rch - 'A';
         int c = cn;
         used[r][c] = 1;
      }
      bool ok = true;
      for(int i = 0; i < R && ok; ++i) {
         for(int j = 1; j <= C; ++j) {
            if(used[i][j]) {
               if(B[i][j-1] == 0) B[i][j-1] = 1;
               else if(B[i][j] == 0) B[i][j] = 1;
               else { 
                  ok = false; 
                  break; 
               }
            }
         }
      }
      cout << (ok ? "YES": "NO") << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
