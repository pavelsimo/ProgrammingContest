/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10242  C++  "Geometry, Vectors, Translation Point" */
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

const double EPS = 1e-9;

struct point { 
   double x, y;
   point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

bool is_equal(point p1, point p2) {
   return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

struct vector_d { 
   double x, y;
   vector_d(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

vector_d to_vector(point p1, point p2) {
   return vector_d(p1.x - p2.x, p1.y - p2.y);
}

vector_d v_sum(vector_d a, vector_d b) {
   return vector_d(a.x + b.x, a.y + b.y);
}

vector_d v_scale(vector_d v, int c) {
   return vector_d(v.x * c, v.y * c);
}

point v_translate(point p, vector_d v) {
   return point(p.x + v.x, p.y + v.y);
}

int main(int argc, char *argv[]) {  
   vector_d ab, cd;
   point p1, p2, p3, p4;
   point A, B, C;
   while(8 == scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y)) {
      if(is_equal(p1,p3))      A = p2, C = p4, B = p1;
      else if(is_equal(p1,p4)) A = p2, C = p3, B = p1;
      else if(is_equal(p2,p3)) A = p1, C = p4, B = p2;
      else if(is_equal(p2,p4)) A = p1, C = p3, B = p2;
      C = v_translate(C,to_vector(A,B));
      printf("%.3lf %.3lf\n",C.x,C.y);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
