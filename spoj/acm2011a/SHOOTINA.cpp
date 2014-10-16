/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ SHOOTINA C++ "Ad Hoc" */
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

int main(int argc, char *argv[]) {
   string buf;
   int TC, N, made3, made2, miss3, miss2, madeft, missft;
   double res;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin,buf);
      sscanf(buf.c_str(),"%d",&N);
      made3 = made2 = miss3 = miss2 = madeft = missft = 0;
      while(N-- > 0) {
           getline(cin,buf);
           if(buf=="Made 2 point field goal") made2++;
           else if(buf=="Missed 2 point field goal") miss2++;
           else if(buf=="Made 3 point field goal") made3++;
           else if(buf=="Missed 3 point field goal") miss3++;
           else if(buf=="Made free throw") madeft++;
           else if(buf=="Missed free throw") missft++;
      }
      res = 1.0*(made2*2 + made3*3 + madeft)/((made2+miss2+made3+miss3)+0.5*(madeft+missft));
      printf("%lf\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
