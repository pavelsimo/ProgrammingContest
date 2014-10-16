/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12083  C++  "Bipartite Matching" */
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

const int MAXN = 1024;
typedef vector<int> VI;
typedef vector<VI> VVI;
VI L, R;
VVI edges;
vector<bool> seen;
int N;

bool dfs(int cur) {
   if(seen[cur]) 
      return false;
   seen[cur] = true;
   for(int i = 0; i < sz(edges[cur]); ++i) {
      int nxt = edges[cur][i];
      if(R[nxt] == -1 || dfs(R[nxt])) {
         L[cur] = nxt;
         R[nxt] = cur;
         return true;  
      }
   }
   return false;
}

int match(int SZ) {
   int res = 0;
   bool aug_path;
   while(true) {  
      aug_path = false;
      seen = vector<bool>(SZ + 1);
      for(int i = 0; i < SZ; ++i) {
         if(L[i]==-1 && dfs(i))
            aug_path = true;
      }
      if(!aug_path) break;
   }
   for(int i = 0; i < SZ; ++i) 
      res+=(L[i]!=-1);
   return res;
}

struct Person {
    int height;
    string music_style, favourite_sport;
    Person(int _height, string _music_style, string _favourite_sport) : 
      height(_height), music_style(_music_style), favourite_sport(_favourite_sport) {}
};

vector<Person> W, M;

int main(int argc, char *argv[]) {
   int height;
   string sex, music_style, favourite_sport;
   int TC;
   cin >> TC;
   while(TC-- > 0) {
      cin >> N;
      M.clear(); W.clear();
      for(int i = 0; i < N; ++i) {
         cin >> height >> sex >> music_style >> favourite_sport;
         if(sex[0]=='M') M.push_back(Person(height,music_style,favourite_sport));
         else W.push_back(Person(height,music_style,favourite_sport));
      }
      L = VI(sz(M) + 1, -1);
      R = VI(sz(W) + 1, -1);
      edges = VVI(sz(M) + 1);
      for(int i = 0; i < sz(M); ++i) {
         for(int j = 0; j < sz(W); ++j) {
            if(abs(W[j].height-M[i].height) <= 40 && M[i].music_style == W[j].music_style 
                  && M[i].favourite_sport != W[j].favourite_sport) {
               edges[i].push_back(j);
            }
         }
      }
      printf("%d\n",N-match(sz(M)));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
