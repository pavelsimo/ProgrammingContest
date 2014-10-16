/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12243  C++  "Ad Hoc" */
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

string buf, word;

int main(int argc, char *argv[]) {
   char ch;
   while(getline(cin,buf)) {
      if(buf[0] == '*') break;
      istringstream in(buf);
      bool tautogram = true;
      for(int i = 0; in >> word; ++i) {
         if(i == 0) {
            ch = tolower(word[0]);
         } else {
            if(tolower(word[0]) != ch) {
               tautogram = false;
               break;
            }
         }
      }
      puts(tautogram?"Y":"N");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
