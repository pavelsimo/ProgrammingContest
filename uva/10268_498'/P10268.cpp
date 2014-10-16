/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10268  C++  "Ad Hoc, Math" */
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

vector<int> C;
int main(int argc, char *argv[]) {
   int x, token, res, powX;
   string buf;
   while(getline(cin,buf)) {
      C.clear();
      sscanf(buf.c_str(),"%d",&x);
      getline(cin,buf);
      istringstream in(buf);
      while (in >> token) C.push_back(token);
      res = 0;
      powX = 1;
      for(int i = sz(C) - 2; i >= 0; --i) {
         res+=C[i]*powX*(sz(C)-i-1);
         powX*=x;
      }
      printf("%d\n",res);
   }   
   return 0;
}
/* @END_OF_SOURCE_CODE */
