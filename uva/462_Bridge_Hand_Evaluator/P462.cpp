/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  462  C++  "Ad Hoc, Cards" */
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

const char *S = "SHDC";
typedef vector<char> VC;

VC m_suit[256];
bool stopped[256];

int main(int argc, char *argv[]) {
   int pts, len;
   char best;
   string buf, card;
   while(getline(cin,buf)) {
      for(int i = 0; i < 4; ++i) {
         m_suit[int(S[i])].clear();
         stopped[int(S[i])] = false;
      }
      best = 'S';
      pts = len = 0;
      istringstream in(buf);
      while(in >> card) {
         /*
            1) Each ace counts 4 points. Each king counts 3 points. Each queen counts 2 points. Each jack counts one point.
         */
         switch(card[0]) {
            case 'A': pts++;
            case 'K': pts++;
            case 'Q': pts++;
            case 'J': pts++;
         }
         m_suit[int(card[1])].push_back(card[0]);
      }
      /*
         2) Subtract a point for any king of a suit in which the hand holds no other cards.
         3) Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
         4) Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
      */
      for(int i = 0; i < 4; ++i) {
         int s = int(S[i]);
         if(sz(m_suit[s]) > len) {
            best = S[i];
            len = sz(m_suit[s]);
         }
         for(int j = 0; j < sz(m_suit[s]); ++j) {
            /*
                A suit is stopped if it contains an ace, or if it contains a king and at least one other card, 
                or if it contains a queen and at least two other cards. 
            */
            if(m_suit[s][j]=='A') stopped[s] = true;
            else if(m_suit[s][j]=='K' && sz(m_suit[s]) >= 2) stopped[s] = true;
            else if(m_suit[s][j]=='Q' && sz(m_suit[s]) >= 3) stopped[s] = true;
            if(m_suit[s][j]=='K' && sz(m_suit[s]) == 1)  pts--;
            else if(m_suit[s][j]=='Q' && sz(m_suit[s]) <= 2)  pts--;
            else if(m_suit[s][j]=='J' && sz(m_suit[s]) <= 3)  pts--;
         }
      }
      // BID NO-TRUMP
      if(pts >= 16 && stopped['S'] && stopped['H'] && stopped['D'] && stopped['C']) {
         puts("BID NO-TRUMP");
         continue;
      }
      /*
         5) Add a point for each suit in which the hand contains exactly two cards.
         6) Add two points for each suit in which the hand contains exactly one card.
         7) Add two points for each suit in which the hand contains no cards. 
      */
      for(int i = 0; i < 4; ++i) {
         int s = int(S[i]);
         if(sz(m_suit[s]) == 2) pts++;
         else if(sz(m_suit[s]) <= 1) pts+=2;         
      }
      // PASS/BID SUIT
      if(pts < 14) puts("PASS");
      else printf("BID %c\n",best);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
