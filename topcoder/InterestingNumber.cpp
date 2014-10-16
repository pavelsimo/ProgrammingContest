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

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(__typeof__((c).begin()) it=(c).begin();it!=(c).end();++it)


class InterestingNumber {
public:


   string isInteresting( string x ) {
     
     int freq[12];
     memset(freq, 0, sizeof(freq));
     for(int i = 0; i < SZ(x); ++i) {
       freq[x[i]-'0']++;
     }
     for(int i = 0; i <= 9; ++i) {
       if(freq[i] == 0) continue;
       if(freq[i] != 2) return "Not interesting";
     }
     set<char> S;
     for(int i = 0; i < SZ(x); ++i) {
       if (S.count(x[i]) == 0) { 
         S.insert(x[i]);
         for(int j = i + 1; j < SZ(x); ++j) {
           if(x[j] == x[i]) {
             if(j - i - 1 != (x[i] - '0')) return "Not interesting";
             break;
           }
         }
       }
     }
     return "Interesting";
   }
};




// Powered by FileEdit
// Powered by moj 4 beta 2 [modified TZTester]
// Powered by CodeProcessor
