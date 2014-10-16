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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

string B[202];

int main(int argc, char *argv[]) { 
   int T;
   string s, t;
   while(cin >> T) {
      for(int i = 0; i < T; ++i) {
         B[i] = "";
         for(int j = 0; j < T; ++j) {
            cin >> s;
            B[i] += (s[0] == 'Y') ? '1': '0';
         }
      }
      bool found  = false;
      for(int i = 0; i < T; ++i) {
         string input = "";
         string output = B[i];
         for(int j = 0; j < T; ++j)
            input += (output == B[j]) ? '1' : '0';
         
         if(input == output) {         
            for(int j = 0; j < T; ++j) {
               if(input[j] == '1') cout << "YES" << endl;
               else cout << "NO" << endl;
            }
            found = true;
            break;
         }
      }
      if(!found) {
         for(int i = 0; i < T; ++i)
            cout << "NO" << endl;
      }
   }
   return 0;
}

