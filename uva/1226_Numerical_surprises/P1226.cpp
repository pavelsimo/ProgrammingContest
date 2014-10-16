/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1180  C++  "Number Theory, Perfect Numbers" */
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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

int N, M;
char buf[2020];

int main(int argc, char *argv[]) {
   int TC, res;
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      gets(buf);
      sscanf(buf,"%d",&N);
      gets(buf);
      M = strlen(buf);
      res = 0;
      for(int i = 0; i < M; ++i)
         res = (res * 10 + (buf[i] - '0')) % N;
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
