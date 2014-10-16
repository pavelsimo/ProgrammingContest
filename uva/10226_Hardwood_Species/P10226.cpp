/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10226  C++  "Ad Hoc" */
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

char buf[32];

int main(int argc, char *argv[]) {
   int TC, N;
   gets(buf);
   sscanf(buf,"%d",&TC);   
   gets(buf);
   for(int tc = 0; tc < TC; ++tc) { 
      if(tc > 0) putchar('\n');
      N = 0;
      map<string,int> freq;
      while(gets(buf)) {
         if(strlen(buf)==0) break;
         freq[buf]++;
         N++;
      }
      foreach(it,freq)
         printf("%s %.4lf\n",it->first.c_str(),100.0*it->second/N);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
