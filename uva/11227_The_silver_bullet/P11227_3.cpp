/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11227  C++  "Geometry, Vectors, Collinear Points" */
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

typedef pair<int,int> PII;
typedef pair<int,PII> PIP;
struct Point{
        int x,y;
        Point(int a=0,int b=0){
                x=a,y=b;
        }
        int operator^(const Point &P)const{
                return x*P.y - y*P.x;
        }
        bool operator<(const Point &P)const{
                return (x!=P.x)?(x<P.x):(y<P.y);
        }
};
 
int toInt(string A)
{
        int n = 0;
        bool si = (A[0]=='-');
        if(si)A = A.substr(1);
        for(int i = 0; i < sz(A); ++i) {
                if(A[i]>='0' && A[i]<='9')
                        n  = 10*n + A[i]-'0';
        }
        return si ? -n : n;
}
 
PII Aligned(vector<Point> &V)
{
        sort(V.begin(),V.end());
        vector<Point> P;
        int ma = 0;
        for(int i = 0; i < sz(V); ++i) {
                if(i==0 || V[i].x != V[i-1].x || V[i].y!=V[i-1].y)
                        P.push_back(V[i]);
        }
        if(P.size()==1)return PII(1,1);
        map<PIP,int> M;
        for(int i = 0; i < sz(P); ++i) {
                for(int j = 0; j < sz(P); ++j) {
                        if(i==j)continue;
                        int a = P[i].x-P[j].x , b = -(P[i].y-P[j].y) ,
                                c = a*P[i].y - b*P[j].x;
                        int gc = __gcd(__gcd(a,b),c);
                        a/=gc;
                        b/=gc;
                        c/=gc;
                        if(a<0 || (a==0 && b<0)){a*=-1 , b*=-1 , c*=-1;}
                        ma = max(++M[PIP(a,PII(b,c))] , ma);
                }
        }
        // n*(n-1) = ma
        return PII(P.size(),(1 + int(sqrt(1 + 4*ma)))/2);
}
 
int main()
{
   int TC, N, tc = 1;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      vector<Point> V(N);
      for(int i = 0; i < N; ++i) {
          int a,b;
          string A,B;
          cin>>A>>B;
          a = toInt(A);
          b = toInt(B);
          V[i] = Point(a,b);
      }
      PII ans = Aligned(V);
      if(ans.first==ans.second && ans.first==1)
         printf("Data set #%d contains a single gnu.\n",tc);
      else 
         printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n",tc,ans.first,ans.second);
      tc++;
   }
}
/* @END_OF_SOURCE_CODE */
