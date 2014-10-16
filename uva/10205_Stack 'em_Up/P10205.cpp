/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10205  C++  "Ad Hoc, Cards" */
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

const int MAXN = 102;
const int MAXD = 52;
int shuffles[MAXN][MAXD + 2];
int deck[MAXD + 2], p[MAXD + 2];
const char *rank[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
const char *suit[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

int main(int argc, char *argv[]) {
   string buf;
   int TC, N, k, c, i, j;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);   
   getline(cin,buf);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      getline(cin,buf);
      sscanf(buf.c_str(),"%d",&N);   
      j = 0; i = -1;
      while(j < N*MAXD && getline(cin,buf)) {
         istringstream in(buf);
         while(in >> c) {
            if(j%MAXD==0) i++;
            shuffles[i][j%MAXD] = --c;
            j++;
         }
      }
      for(i = 0; i < MAXD; ++i) deck[i] = i;
      while(getline(cin,buf)) {
         if(sscanf(buf.c_str(),"%d",&k) != 1) break;
         --k;
         for(i = 0; i < MAXD; ++i) p[i] = deck[shuffles[k][i]];
         for(i = 0; i < MAXD; ++i) deck[i] = p[i];
      }
      for(i = 0; i < MAXD; ++i)
         printf("%s of %s\n",rank[deck[i]%13],suit[deck[i]/13]);      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

