#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
 
vector<long long> A;
int main(int argc, char *argv[]) { 
   long long n;
   cin >> n;
   for(long long i = 1; true; ++i) {
      long long X = (i * (i + 1LL)) / 2LL;
      if(X >= n) break;
      A.push_back(X);
   }
   for(int i = 0; i < sz(A); ++i) {
      if(n >= A[i]) {
         if(binary_search(all(A), n - A[i])) {
            cout << "YES" << endl;
            return 0;
         }
      } else {
         break;
      }
   }
   cout << "NO" << endl;
   return 0;
}

