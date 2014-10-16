/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FAKETSP C++ "Ad Hoc, Simple Math" */
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

double dist(double x1, double x2, double y1, double y2) {
   double dx = x1-x2;
   double dy = y1-y2;
   return sqrt(dx*dx + dy*dy);
}

int main(int argc, char *argv[]) {
   string buf, s;
   double x1, y1, x2, y2, d=0.0;
   for(int tc = 0; getline(cin,buf); ++tc) {
      s="";
      for(int i = sz(buf)-2; i >= 0; --i) {
         s = buf[i] + s;
         if(buf[i]=='(') break;
      }
      sscanf(s.c_str(),"(%lf, %lf)",&x1,&y1);
      if(tc > 0) {
         d+=dist(x1,x2,y1,y2);
         printf("The salesman has traveled a total of %.3lf kilometers.\n",d);
      }
      x2=x1;
      y2=y1;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

