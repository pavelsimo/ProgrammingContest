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

vector<string> notes;

int get_pos(string s) {
   return int(find(all(notes), s) - notes.begin());
}

int dist(string s1, string s2) {
   int p = get_pos(s1);
   int q = get_pos(s2);
   if(q >= p) return q - p;
   return 12 - p + q;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   // C, C#, D, D#, E, F, F#, G, G#, A, B, H
   notes.push_back("C");  
   notes.push_back("C#"); 
   notes.push_back("D");  
   notes.push_back("D#"); 
   notes.push_back("E"); 
   notes.push_back("F");  
   notes.push_back("F#"); 
   notes.push_back("G");  
   notes.push_back("G#");
   notes.push_back("A");
   notes.push_back("B");
   notes.push_back("H");
     
   string s[3];
   cin >> s[0] >> s[1] >> s[2];
   sort(s, s + 3);
   
   do {
      if(dist(s[0], s[1]) == 3 && dist(s[1], s[2]) == 4) {
         cout << "minor" << endl;
         return 0;
      }
      if(dist(s[0], s[1]) == 4 && dist(s[1], s[2]) == 3) {
         cout << "major" << endl;
         return 0;
      }
   } while(next_permutation(s, s + 3));
   cout << "strange" << endl;
   return 0;
}

