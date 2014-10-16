/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11475  C++  "String Matching, KMP" */
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

const int MAXN = 100010;
int b[MAXN];
string text, pattern;

void kmp_preprocessing() {
   int i = 0, j = -1;
   b[i] = j;
   while(i < sz(pattern)) {
      if(j >= 0 && pattern[i] != pattern[j]) j = b[j];
      ++i; ++j;      
      b[i] = j;
   }
}

int kmp_search() {
   int i = 0, j = 0;
   while(i < sz(text)) {
      while(j >= 0 && text[i] != pattern[j]) j = b[j];
      ++i; ++j;
      if(j == sz(pattern)) return j;
   }
   return j;
}

int main(int argc, char *argv[]) {
   int pos;
   while(getline(cin,text)) {
      pattern = text;
      reverse(all(pattern));
      kmp_preprocessing();
      pos = kmp_search();
      printf("%s%s\n",text.c_str(),pattern.substr(pos).c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
