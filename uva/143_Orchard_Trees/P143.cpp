/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  143  C++  "Geometry, Brute Force" */
#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 100;
const double eps = 1e-9;

double area2(double x0, double y0, double x1, double y1, double x2, double y2) {
  return fabs((x0*y1 + x2*y0 + x1*y2 - x2*y1 - x0*y2 - x1*y0));
}

bool is_equal(double a, double b) {
   if(fabs(a-b) < eps) return true;
   return false;
}

int main(int argc, char *argv[]) {  
   double x0,y0,x1,y1,x2,y2;
   while(scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&x2,&y2)==6) {
      if(x0==0.0 && y0==0.0 && x1==0.0 && y1==0.0 && x2==0.0 && y2==0.0) break;
      //printf("DEBUG x0=%lf y0=%lf x1=%lf y1=%lf x2=%lf y2=%lf area=%lf\n", x0,y0,x1,y1,x2,y2,area2(x0,y0,x1,y1,x2,y2));
      double area = area2(x0,y0,x1,y1,x2,y2);
      int ans = 0;
      for(int i = 0; i <= maxn; ++i) {
         for(int j = 0; j <= maxn; ++j) {
            /*
            if(is_equal(area,0.0)) {
                    if(is_equal(i*1.0,x0) && is_equal(j*1.0,y0)) ans++;
               if(is_equal(i*1.0,x1) && is_equal(j*1.0,y1)) ans++;
               if(is_equal(i*1.0,x2) && is_equal(j*1.0,y2)) ans++;
               continue;
            }
            */
            double x = (area2(i*1.0,j*1.0,x0,y0,x1,y1)+area2(i*1.0,j*1.0,x1,y1,x2,y2)+area2(i*1.0,j*1.0,x0,y0,x2,y2));
            if(is_equal(area,x)) ans++;            
         }
      }
      printf("%4d\n",ans);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */



