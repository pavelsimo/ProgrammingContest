/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MIRRORED C++ "Ad Hoc" */
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


int main(int argc, char *argv[]) {
   string buf;
   puts("Ready");
   while(getline(cin,buf)) {
      if(isspace(buf[0]) && isspace(buf[1])) break;
      if(tolower(buf[0])=='p'&& tolower(buf[1])=='q') puts("Mirrored pair");
      else if(tolower(buf[0])=='q'&& tolower(buf[1])=='p') puts("Mirrored pair");
      else if(tolower(buf[0])=='b'&& tolower(buf[1])=='d') puts("Mirrored pair");
      else if(tolower(buf[0])=='d'&& tolower(buf[1])=='b') puts("Mirrored pair");
      else puts("Ordinary pair");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

