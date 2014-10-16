/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12195  C++  "Ad Hoc, Music" */
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

string buf;

int getduration(char ch) {
   if(ch=='W') return 64;  
   if(ch=='H') return 32;
   if(ch=='Q') return 16;
   if(ch=='E') return 8;
   if(ch=='S') return 4;
   if(ch=='T') return 2;
   if(ch=='X') return 1;
   return 0;
}

int main(int argc, char *argv[]) {
   int res;
   string notes;
   while(getline(cin,buf)) {
      if(buf[0]=='*') break;
      istringstream in(buf);
      res = 0;
      while(getline(in,notes,'/')) {
         int measure = 0;
         for(int i = 0; i < sz(notes); ++i)
            measure+=getduration(notes[i]);
         if(measure == 64) res++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
