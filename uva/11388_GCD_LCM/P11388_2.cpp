/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11388  C++  "Math, GCD, LCM" */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int main(int argc, char *argv[]) {
   int TC, a, b;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&a,&b);   
      if(b % a == 0) printf("%d %d\n",a, b);
      else printf("-1\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
