/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ SBANK C++ "Ad Hoc" */
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

char buf[64];
map<string, int> m_accounts;

int main(int argc, char *argv[]) {
   int TC, N;
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      m_accounts.clear();
      gets(buf);
      sscanf(buf,"%d",&N);
      for(int i = 0; i < N; ++i) {
         gets(buf);
         m_accounts[string(buf)]++;
      }
      foreach(it,m_accounts)
         printf("%s %d\n",it->first.c_str(),it->second);
      putchar('\n');
      gets(buf);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
