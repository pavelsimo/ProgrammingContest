/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PUCMM025 C++ "Ad Hoc, String Manipulation" */
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

char s[1024];
int main(int argc, char *argv[]) {
   int n;
   while(gets(s)) { 
      n = strlen(s);
      bool upper = true;
      for(int i = 0; i < n; ++i) {
         if(isalpha(s[i]) && upper) 
            s[i] = toupper(s[i]), upper = false;
         if(s[i] == '.') upper = true;
      }
      puts(s);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
