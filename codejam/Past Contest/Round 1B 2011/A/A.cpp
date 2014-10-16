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

const int MAXN = 110;
char s[256];
char buf[MAXN][MAXN];
double WP[MAXN], OWP[MAXN], OOWP[MAXN];
int L[MAXN], W[MAXN];


int main(int argc, char *argv[]) {
   int TC, N;
   gets(s);
   sscanf(s,"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
        gets(s);
        sscanf(s,"%d",&N);
        for(int i = 0; i < N; ++i) {
           gets(buf[i]);
           L[i] = W[i] = 0;
           WP[i] = OWP[i] = OOWP[i] = 0.0;
        }
        for(int i = 0; i < N; ++i) {
            int loss = 0;
            int wins = 0;
            for(int j = 0; j < N; ++j) {   
               if(buf[i][j]=='1') {
                  W[i] = ++wins;
               } else if(buf[i][j]=='0') {
                  L[i] = ++loss;
               }
            }
            if(wins+loss>0) WP[i] = double(wins)/double(wins+loss);
        }
         for(int i = 0; i < N; ++i) {
            double sum = 0;
            int cnt = 0;
            for(int j = 0; j < N; ++j) {   
               if(buf[i][j]=='1') {
                  if(W[j]+L[j] - 1 > 0) {
                     sum+=double(W[j])/double(W[j]+L[j] - 1);
                     cnt++;
                  } else {
                     cnt++;
                  }             
               } else if(buf[i][j]=='0') {
                  if(W[j]+L[j] - 1 > 0) {
                     sum+=double(W[j] - 1)/double(W[j]+L[j] - 1);
                     cnt++;
                  } else {
                     cnt++;
                  }
               }
            }
            if(cnt>0)
               OWP[i]=sum/double(cnt);
            else
               OWP[i]=0.0;
        }
        for(int i = 0; i < N; ++i) {
            double sum = 0.0;
            int cnt = 0;
            for(int j = 0; j < N; ++j) {   
               if(buf[i][j]=='1' || buf[i][j]=='0') {
                  sum+=OWP[j];
                  cnt++;
               }
            }
            if(cnt>0)
               OOWP[i]=sum/double(cnt);
            else
               OOWP[i]=0;
        }
        printf("Case #%d:\n",tc);
        for(int i = 0; i < N; ++i) {
           double RPI = 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i];
           printf("%lf\n",RPI);
        }
   }
   return 0;
}

