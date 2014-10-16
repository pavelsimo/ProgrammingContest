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

struct Node {
  int a, b, c; 
  Node(int _a = 0, int _b = 0, int _c = 0) :
   a(_a), b(_b), c(_c) {}
};

vector<Node> X;
int a[100002];

int main(int argc, char *argv[]) {
   int n;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   sort(a, a + n);
   int i, j, k;
   i = 0;
   j = i + 1;
   k = i + 2;
   while(i < n && j < n && k < n) {
      if(i == k) {
         i++;
         j++;
         k++;
      } else if(i == j) {
         j++;
         k++;
      } else if(j == k) {
         j++;
         k++;
      } else {
         X.push_back(Node(a[k], a[j], a[i]));
         i+=3;
         j+=3;
         k+=3;
      }
   }
   cout << sz(X) << endl;
   for(int i = 0; i < sz(X); ++i) {
      cout << X[i].a << ' ' << X[i].b << ' ' << X[i].c << endl;      
   }
   return 0;
}

