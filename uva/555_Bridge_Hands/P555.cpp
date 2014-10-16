/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  555  C++  "Ad Hoc, Cards" */
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

const char *dir = "ESWN", *suit = "CDSH", *rank = "23456789TJQKA";

struct Card {
  char s, r; 
  Card(char _s, char _r) : 
   s(_s), r(_r) {}
  bool operator<(const Card &T) const {
     if(s != T.s) return strchr(suit,s) - suit < strchr(suit,T.s) - suit;
     return strchr(rank,r) - rank < strchr(rank,T.r) - rank;
  }
};

vector<Card> A[4];

int main(int argc, char *argv[]) {
   string buf;
   int id_player;
   while(cin >> buf) {
      if(buf[0] == '#') break;
      for(int i = 0; i < 4; ++i) 
         A[i].clear();
      id_player = strchr(dir,buf[0]) - dir;
      for(int k = 0; k < 2; ++k) {
         cin >> buf;
         for(int i = 0; i < sz(buf); i+=2) {
            A[id_player].push_back(Card(buf[i],buf[i+1]));
            id_player = (id_player + 1) % 4;
         }
      }
      for(int i = 0; i < 4; ++i) {
         sort(all(A[i]));
         printf("%c:",dir[(i + 1)%4]);
         for(int j = 0; j < sz(A[i]); ++j) {
            putchar(' ');
            printf("%c%c",A[i][j].s,A[i][j].r);
         }
         putchar('\n');
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
