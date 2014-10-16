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

typedef pair<int, pair<string,string> > Person;

Person a[102];

int rank(const string &s) {
   if(s == "rat") return 0;
   else if(s == "woman" || s == "child") return 1;
   else if(s == "man") return 2;
   return 3;
}

bool cmp(const Person &a, const Person &b) {
   if(rank(a.second.second) != rank(b.second.second)) 
      return rank(a.second.second) < rank(b.second.second);
   return a.first < b.first;
}

int main(int argc, char *argv[]) {
   int N;
   cin >> N;
   for(int i = 0; i < N; ++i) {
      cin >> a[i].second.first >> a[i].second.second;
      a[i].first = i;
   }
   sort(a, a + N, cmp);
   for(int i = 0; i < N; ++i)
      cout << a[i].second.first << endl;
   return 0;
}

 
