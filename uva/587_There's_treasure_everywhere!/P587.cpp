/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  587  C++  "Geometry, Vectors" */
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

const double EPS = 1e-6;

struct point { 
   double x, y;
   point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
   double operator*(const point &T) const { 
      // dot product
      return x * T.x + y * T.y;  
   }
   point operator*(const double &T) const { 
      // scale
      return point(x * T, y * T);  
   }
   point operator-(const point &T) const {
      // substraction
      return point(x - T.x, y - T.y);
   }
   point operator+(const point &T) const {
      // translation
      return point(x + T.x, y + T.y);
   }
   double operator^(const point &T) const {
      // cross product
      return x * T.y - T.x * y;
   }
};

const double C = sqrt(2.0);
const point N(0.0,1.0), S(0.0,-1.0), E(1.0,0.0), W(-1.0,0.0);

double read(const string &str) {
   double res;
   sscanf(str.c_str(),"%lf",&res);
   return res;
}

point translate(const point &p, const string &cmd) {
   point x;
   size_t pos;
   double scale;
   if((pos = cmd.find("NE")) != string::npos) {
      scale = read(cmd.substr(0,pos));
      scale*=C;
      scale/=2.0;
      x = (N + E) * scale;
   } else if((pos = cmd.find("SE")) != string::npos) {
      scale = read(cmd.substr(0,pos));
      scale*=C; scale/=2.0;
      x = (S + E) * scale;
   } else if((pos = cmd.find("SW")) != string::npos) {
      scale = read(cmd.substr(0,pos));
      scale*=C; scale/=2.0;
      x = (S + W) * scale;
   } else if((pos = cmd.find("NW")) != string::npos) {
      scale = read(cmd.substr(0,pos));
      scale*=C; scale/=2.0;
      x = (N + W) * scale;
   } else if((pos = cmd.find("N")) != string::npos) {
      scale = read(cmd.substr(0,pos));
      x = N * scale;
   } else if((pos = cmd.find("E")) != string::npos) {
      scale = read(cmd.substr(0,pos));
      x = E * scale;
   } else if((pos = cmd.find("S")) != string::npos) {
      scale = read(cmd.substr(0,pos));
      x = S * scale;
   } else if((pos = cmd.find("W")) != string::npos) {
      scale = read(cmd.substr(0,pos));
      x = W * scale;
   }
   return p + x;
}

double dist(point p1, point p2) {
   double dx = p1.x - p2.x;
   double dy = p1.y - p2.y;
   return sqrt(dx*dx + dy*dy);
}

int main(int argc, char *argv[]) {
   string buf, cmd;
   int tc = 0;
   while(getline(cin,buf)) {
      if(buf=="END") break;
      istringstream in(buf);
      point p(0,0);   
      while(getline(in,cmd,','))
         p = translate(p,cmd);
      printf("Map #%d\n",++tc);
      printf("The treasure is located at (%.3lf,%.3lf).\n",p.x,p.y);
      printf("The distance to the treasure is %.3lf.\n\n",dist(point(0,0), p));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

