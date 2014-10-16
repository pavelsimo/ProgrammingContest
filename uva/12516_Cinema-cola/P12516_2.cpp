/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12516  C++  "Ad Hoc" */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int B[32][256];
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
      getline(cin, buf);
      sscanf(buf.c_str(),"%d",&P);
      while(P-- > 0) {
         getline(cin, buf);
         sscanf(buf.c_str(),"%c%d %c",&rch,&cn,&dir);
         int r = rch - 'A';
         int c = 2 * cn - 1;
         if(dir == '-') B[r][c-1] = 1;
         else B[r][c+1] = 1;
      } 
      getline(cin, buf);
      sscanf(buf.c_str(),"%d",&Z);
      vector<pair<int,int> > X;
      while(Z-- > 0) {
         getline(cin, buf);
         sscanf(buf.c_str(),"%c%d",&rch,&cn);
         int r = rch - 'A';
         int c = 2 * cn - 1;
         X.push_back(make_pair(r,c));
      }
      sort(all(X));
      bool ok = true;
      for(int i = 0; i < sz(X); ++i) {
         int r = X[i].first;
         int c = X[i].second;
         if(B[r][c - 1] == 0) {
            B[r][c - 1] = 1;
         } else if(B[r][c + 1] == 0) {
            B[r][c + 1] = 1;
         } else {
            ok = false;
            break;
         }
      }
      cout << (ok ? "YES": "NO") << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
