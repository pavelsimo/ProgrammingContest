/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ TWOSQRS C++ "Ad Hoc, Math" */
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


typedef long long llong;

int main(int argc, char *argv[]) {
   int TC;
   llong n;
   scanf("%d",&TC);   
   while(TC-- > 0) {
      scanf("%lld",&n);
      bool ok = true;
      for(llong i = 2LL; i*i <= n; ++i) {
         int cnt = 0;
         while(n%i==0) {
            cnt++;
            n/=i;
         }
         /* Explicacion: 
          * 
          * http://www.math.hmc.edu/funfacts/ffiles/20008.5.shtml
          * http://en.wikipedia.org/wiki/Fermat%27s_theorem_on_sums_of_two_squares
          * 
          * para poder expresar un numero n como la suma de dos cuadrados
          * todos sus factores primos de la forma p = (4x + 3) deben aparecer una par cantidad de veces
          * ejemplo 49 = 7 * 7 donde 49 = (4(1) + 3)*(4(1) + 3), la frequencia del 7 es 2 por lo tanto
          * 49 puede ser expresado como el cuadrado de dos numeros.
          */
         if(i%4==3 && cnt%2==1) {
            ok = false;
            break;
         }
      }
      /* 
       * si resta un factor primo y es de la forma 4x + 3 significa que aparecera una cantidad de veces
       * impares, por lo tanto, el numero n no se puede expresar como un producto de dos cuadrados.
       */
      if(n%4==3) ok = false;
      if(ok) puts("Yes");
      else puts("No");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
