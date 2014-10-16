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


class RotatedClock {
public:
   string getEarliest(int hourHand, int minuteHand ) {
      string res = "";
      char buf[16];
      for(int d = 0; d <= 360; d+=30) {
         int H = ((((hourHand + d)%360) * 720) / 360)/60;
         int M = (((minuteHand + d)%360) * 60) / 360;
         int hourHandRotate = (hourHand + d)%360;
         int minuteHandRotate = (minuteHand + d)%360;
         if((hourHandRotate%30)*12 == minuteHandRotate) {
            sprintf(buf,"%02d:%02d",H,M);   
            res = string(buf);
         }
      }
      return res;
   }
};




// Powered by FileEdit
// Powered by moj 4 beta 2 [modified TZTester]
// Powered by CodeProcessor
