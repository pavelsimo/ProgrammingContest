#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

string B[102];
int DL[102][10002];
int DR[102][10002];
const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   memset(DL, 0x3f, sizeof(DL));
   memset(DR, 0x3f, sizeof(DR));
   
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < n; ++i)
      cin >> B[i];
      
   for(int i = 0; i < n; ++i) {
      
      int first = B[i].find('1');
      int last  = B[i].rfind('1');

      if(first == -1) {
         cout << -1 << endl;
         return 0;
      }
      
      int prev = first;
      for(int j = 0; j < m; ++j) {
         if(B[i][j] == '1') {
            DL[i][j] = 0;
            prev = j;
         } else {
            DL[i][j] = min(abs(prev - j), m - last + j);
         }
      }
      
      prev = last;
      for(int j = m - 1; j >= 0; --j) {
         if(B[i][j] == '1') {
            DR[i][j] = 0;
            prev = j;
         } else {
            DR[i][j] = min(abs(prev - j), first + m - j);
         }
      }
   }
   
   int res = INF;
   for(int j = 0; j < m; ++j) {
      int sum = 0;
      for(int i = 0; i < n; ++i) {
         sum += min(DL[i][j], DR[i][j]);
      }
      res = min(res, sum);
   }
   cout << res << endl;
   return 0;
}

