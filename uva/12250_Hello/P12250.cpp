/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12250  C++  "Ad Hoc" */
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
#define BUFSIZE (4*1024*1024)

string s;
int main(int argc, char *argv[]) {
   for(int tc = 1; getline(cin,s); ++tc) {
      if(s[0]=='#') break;
      printf("Case %d: ",tc);
      if(s=="HELLO") puts("ENGLISH");
      else if(s=="HOLA") puts("SPANISH");
      else if(s=="HALLO") puts("GERMAN");
      else if(s=="BONJOUR") puts("FRENCH");
      else if(s=="CIAO") puts("ITALIAN");
      else if(s=="ZDRAVSTVUJTE") puts("RUSSIAN");
      else puts("UNKNOWN");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
