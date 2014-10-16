/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10344  C++  "Brute Force" */
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

int op(int a, int b, int operation) {
   if ( operation == 0 ) 
       return a+b;
   else if ( operation == 1)
       return a-b;
   return a*b;
}
int eval(int a, int b, int c, int d, int e, 
            int op1, int op2, int op3, int op4) {
   int res = 0;
   res = op(a,b,op1);
   res = op(res,c,op2);
   res = op(res,d,op3);
   res = op(res,e,op4);
   return res;
}

int valid(int a, int b, int c, int d, int e) {

int perm[120][5] = { 
               {a, b, c, d, e}, {a, b, c, e, d}, {a, b, d, c, e}, {a, b, d, e, c},
               {a, b, e, c, d}, {a, b, e, d, c}, {a, c, b, d, e}, {a, c, b, e, d},
               {a, c, d, b, e}, {a, c, d, e, b}, {a, c, e, b, d}, {a, c, e, d, b},
               {a, d, b, c, e}, {a, d, b, e, c}, {a, d, c, b, e}, {a, d, c, e, b},
               {a, d, e, b, c}, {a, d, e, c, b}, {a, e, b, c, d}, {a, e, b, d, c},
               {a, e, c, b, d}, {a, e, c, d, b}, {a, e, d, b, c}, {a, e, d, c, b},
               {b, a, c, d, e}, {b, a, c, e, d}, {b, a, d, c, e}, {b, a, d, e, c},
               {b, a, e, c, d}, {b, a, e, d, c}, {b, c, a, d, e}, {b, c, a, e, d},
               {b, c, d, a, e}, {b, c, d, e, a}, {b, c, e, a, d}, {b, c, e, d, a},
               {b, d, a, c, e}, {b, d, a, e, c}, {b, d, c, a, e}, {b, d, c, e, a},
               {b, d, e, a, c}, {b, d, e, c, a}, {b, e, a, c, d}, {b, e, a, d, c},
               {b, e, c, a, d}, {b, e, c, d, a}, {b, e, d, a, c}, {b, e, d, c, a},
               {c, a, b, d, e}, {c, a, b, e, d}, {c, a, d, b, e}, {c, a, d, e, b},
               {c, a, e, b, d}, {c, a, e, d, b}, {c, b, a, d, e}, {c, b, a, e, d},
               {c, b, d, a, e}, {c, b, d, e, a}, {c, b, e, a, d}, {c, b, e, d, a},
               {c, d, a, b, e}, {c, d, a, e, b}, {c, d, b, a, e}, {c, d, b, e, a},
               {c, d, e, a, b}, {c, d, e, b, a}, {c, e, a, b, d}, {c, e, a, d, b},
               {c, e, b, a, d}, {c, e, b, d, a}, {c, e, d, a, b}, {c, e, d, b, a},
               {d, a, b, c, e}, {d, a, b, e, c}, {d, a, c, b, e}, {d, a, c, e, b},
               {d, a, e, b, c}, {d, a, e, c, b}, {d, b, a, c, e}, {d, b, a, e, c},
               {d, b, c, a, e}, {d, b, c, e, a}, {d, b, e, a, c}, {d, b, e, c, a},
               {d, c, a, b, e}, {d, c, a, e, b}, {d, c, b, a, e}, {d, c, b, e, a},
               {d, c, e, a, b}, {d, c, e, b, a}, {d, e, a, b, c}, {d, e, a, c, b},
               {d, e, b, a, c}, {d, e, b, c, a}, {d, e, c, a, b}, {d, e, c, b, a},
               {e, a, b, c, d}, {e, a, b, d, c}, {e, a, c, b, d}, {e, a, c, d, b},
               {e, a, d, b, c}, {e, a, d, c, b}, {e, b, a, c, d}, {e, b, a, d, c},
               {e, b, c, a, d}, {e, b, c, d, a}, {e, b, d, a, c}, {e, b, d, c, a}, 
               {e, c, a, b, d}, {e, c, a, d, b}, {e, c, b, a, d}, {e, c, b, d, a},
               {e, c, d, a, b}, {e, c, d, b, a}, {e, d, a, b, c}, {e, d, a, c, b},
               {e, d, b, a, c}, {e, d, b, c, a}, {e, d, c, a, b}, {e, d, c, b, a}};
    for(int op1 = 0; op1 < 3; ++op1)
        for(int op2 = 0; op2 < 3; ++op2)
            for(int op3 = 0; op3 < 3; ++op3)
                for(int op4 = 0; op4 < 3; ++op4)
                    for(int k = 0; k < 120; ++k)
                        if ( eval(perm[k][0],perm[k][1],perm[k][2],perm[k][3],perm[k][4],op1,op2,op3,op4) == 23 )
                            return 1;    
    return 0;
}

int main() {
    int a, b, c, d, e;
    while ( scanf("%d %d %d %d %d",&a,&b,&c,&d,&e) == 5  ) {
        if ( a==0 && b==0 && c==0 && d==0 && e==0 ) 
            break;
        if ( valid(a,b,c,d,e) ) 
            printf("Possible\n");
        else 
            printf("Impossible\n");
    }        
    return 0;
}
/* @END_OF_SOURCE_CODE */
