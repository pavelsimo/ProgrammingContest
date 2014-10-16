/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10295  C++  "Ad Hoc, Map, Set" */
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

typedef long long llong;
map<string,llong> m_salary;
char job[32];

int main(int argc, char *argv[]) {
   string buf, s;
   int N, M;
   llong salary, res;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d%d",&N,&M);
   while(N-- > 0) {
      getline(cin,buf);
      sscanf(buf.c_str(),"%s %lld",job,&salary);
      m_salary[job] = salary;
   }
   while(M-- > 0) {
      res = 0LL;
      while(getline(cin,buf)) {
         if(buf[0]=='.') break;
         istringstream in(buf);
         while(in >> s) res+=m_salary[s];
      }
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
