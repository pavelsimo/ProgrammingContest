/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  162  C++  "Ad Hoc, Cards" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

bool hasface(char ch) {
   return ch=='A' || ch=='K' || ch=='Q' || ch=='J';
}

int main(int argc, char *argv[]) {
   bool ok;
   int turn, steps, prev;
   string card;
   while(cin >> card) {
      if(card[0]=='#') break;
      deque<string> deck;
      deque<string> A[2];
      A[0].push_front(card);
      for(int i = 1; i < 52; ++i) {
         cin >> card;
         A[i % 2].push_front(card);
      }
      steps = 1;
      prev = -1;
      turn = 0;
      ok = true;
      while(ok) {
         while(steps-- > 0) {
            if(A[turn].empty()) {
               printf("%d%3d\n",turn + 1, A[turn ^ 1].size());
               ok = false;
               break;
            }
            string card = A[turn].front();
            A[turn].pop_front();
            deck.push_back(card);
            if(hasface(card[1])) {
               if(card[1]=='J') steps = 1;
               else if(card[1]=='Q') steps = 2;
               else if(card[1]=='K') steps = 3;
               else if(card[1]=='A') steps = 4;
               prev=turn;
               turn^=1;
            }
         }
         if(ok) {
            if(prev >= 0) {
               A[prev].insert(A[prev].end(),all(deck));
               deck.clear();
            }
            steps=1;
            prev=-1;
            turn^=1;
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

