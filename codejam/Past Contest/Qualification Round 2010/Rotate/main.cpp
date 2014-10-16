#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
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


char a[52][52];
char b[52][52];
int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,1,1,-1,-1};

int dfs(int i, int j, int n, char c, int k, int dx, int dy) {
  int ans = 1;
  int sx = i+dx;
  int sy = j+dy;
  for(int t = 1; t < k; ++t) {
      if ( sx >= n || sx < 0 || sy >= n || sy < 0 || b[sx][sy] != c ) {
           ans = 0;
           break;
      }
      sx = sx+dx;
      sy = sy+dy;
  }
  return ans;
}

int main() {
	int T,n,k;

	scanf("%d\n",&T);
	for(int c = 1; c <= T; ++c) {
        int winner = 0;
        scanf("%d %d\n",&n, &k);

        for(int i = 0; i < n; ++i)
            scanf("%s",&a[i]);
        
        // rotate
        int col = 0;
        for(int i = n-1; i >= 0; --i) {
            for(int j = 0; j < n; ++j) {
                b[j][col] = a[i][j];     
            }        
            col++;
        }
        
        // gravity
        for(int i = n-1; i >= 0; --i) {
            for(int j = 0; j < n; ++j) {
                if ( b[i][j] != '.' ) {
                    int sx = i;
                    while (true) {
                        if ( sx+1 >= n ) break;
                        if ( b[sx+1][j] != '.' ) break;
                        sx++;
                    }
                    char t = b[i][j];
                    b[i][j] = b[sx][j];
                    b[sx][j] = t;
                }
            }        
        }
   
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if ( b[i][j] != '.' ) {
                   for(int d = 0; d < 8; ++d) { 
                        if ( b[i][j] == 'B' ) {
                            if ( dfs(i,j, n,'B',k,dx[d],dy[d]) ) winner |= 1;     
                        } else {
                            if ( dfs(i,j, n,'R',k,dx[d],dy[d]) ) winner |= 2;                                 
                        }
                    }      
                }
            }        
        }
        
        switch(winner) {
            case 0:
                printf("Case #%d: Neither\n",c);
            break;
            case 1:
                printf("Case #%d: Blue\n",c);
            break;      
            case 2:
                printf("Case #%d: Red\n",c);
            break;    
            default:
                printf("Case #%d: Both\n",c);     
        }
    }
    return 0;
}
