#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1002;
int A[MAXN];

int main(int argc, char *argv[]) {
   int n, res;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> A[i];
   res = min(A[0],A[n-1]);
   for(int i = 0; i < n - 1; ++i)
      res = min(res, max(A[i],A[i+1]));   
   cout << res << endl;
   return 0;
}

