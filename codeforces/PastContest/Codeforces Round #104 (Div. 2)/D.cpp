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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

string solve(int cnt4, int cnt7, int cnt47, int cnt74) {
   int p1, p2;
   string res = "";
   if(abs(cnt47 - cnt74) > 1)
      return "-1";
   if(cnt47 == cnt74) {
      for(int i = 0; i < cnt47; ++i) {
        res+="47"; cnt4--; cnt7--;
        if(i > 0) cnt74--;
      }
      for(int i = 0; i < cnt74; ++i) {
         if(i > 0) {                  
            res+="74"; cnt4--; cnt7--;                  
         } else {
            if(cnt4 - 1 >= 0) cnt4--, res+="4";
            else if(cnt7 - 1 >= 0) cnt7--, res="7"+res;
            else return "-1";
         }
      }  
   } else if(cnt47 > cnt74) {
      for(int i = 0; i < cnt47; ++i) {
        res+="47"; cnt4--; cnt7--; 
      } 
   } else {
      for(int i = 0; i < cnt74; ++i) {
         res+="74"; cnt4--; cnt7--;
      }
   }
   if(cnt4 < 0 || cnt7 < 0) return "-1";
   string rem4 = string(cnt4, '4');
   string rem7 = string(cnt7, '7');
   p1 = res.find("4");
   res = res.substr(0, p1) + rem4 + res.substr(p1);
   p2 = res.rfind("7");
   res = res.substr(0, p2) + rem7 + res.substr(p2);
   return res;
}


int main(int argc, char *argv[]) {
   string res = "";
   int c4, c7, c47, c74;
   cin >> c4 >> c7 >> c47 >> c74;
   cout << solve(c4,c7,c47,c74) << endl;
   return 0;
}

