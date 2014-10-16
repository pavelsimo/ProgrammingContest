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


int main(int argc, char *argv[]) {
   string s;
   cin >> s;
   if(s.size() < 3 || (s.size() == 3 && s <= "127")) cout << "byte" << endl;
   else if(s.size() < 5 || (s.size() == 5 && s <= "32767")) cout << "short" << endl;
   else if(s.size() < 10 || (s.size() == 10 && s <= "2147483647")) cout << "int" << endl;
   else if(s.size() < 19 || (s.size() == 19 && s <= "9223372036854775807")) cout << "long" << endl;
   else cout << "BigInteger" << endl;
   return 0;
}

 
