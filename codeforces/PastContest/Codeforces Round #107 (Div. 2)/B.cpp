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

string tonum(string s) {
   string res = "";
   for(int i = 0; i < sz(s); ++i)
      if(isdigit(s[i]))
         res+=s[i];
   return res;
}

bool is_taxi(string s) {
   sort(all(s));
   return s[0] == s[sz(s)-1];
}

bool is_pizza(string s) {
   for(int i = 0; i < sz(s) - 1; ++i)
      if(s[i] <= s[i + 1]) return false;
   return true;
}

vector<string> X;
int A[200][4];

int main(int argc, char *argv[]) {
   int n, m;
   int ntaxi, npizza, ngirls;
   string name, num;
   cin >> n;
   memset(A,0,sizeof(A));
   ntaxi = npizza = ngirls = 0;
   for(int i = 0; i < n; ++i) {
      cin >> m >> name;
      X.push_back(name);
      for(int j = 0; j < m; ++j) {
         cin >> num;
         num = tonum(num);
         if(is_taxi(num)) A[i][0]++;
         else if(is_pizza(num)) A[i][1]++;
         else A[i][2]++;
         ntaxi = max(ntaxi,A[i][0]);
         npizza = max(npizza,A[i][1]);
         ngirls = max(ngirls,A[i][2]);
      }
   }
   cout << "If you want to call a taxi, you should call:";
   for(int i = 0, j = 0; i < n; ++i) {
      if(A[i][0] == ntaxi) {
         if(j > 0) cout << ',';
         cout << ' ' << X[i];
         j++;
      }
   }
   cout << '.' << endl;
   cout << "If you want to order a pizza, you should call:";
   for(int i = 0, j = 0; i < n; ++i) {
      if(A[i][1] == npizza) {
         if(j > 0) cout << ',';
         cout << ' ' << X[i];
         j++;
      }
   }
   cout << '.' << endl;
   cout << "If you want to go to a cafe with a wonderful girl, you should call:";
   for(int i = 0, j = 0; i < n; ++i) {
      if(A[i][2] == ngirls) {
         if(j > 0) cout << ',';
         cout << ' ' << X[i];
         j++;
      }
   }
   cout << '.' << endl;
   return 0;
}

