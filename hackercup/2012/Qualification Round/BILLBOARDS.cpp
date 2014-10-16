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

vector<int> word_size;
int main(int argc, char *argv[]) {   
   string s, token;
   int TC, W, H, font_size, cur_w, cur_h, line, cnt;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      word_size.clear();
      getline(cin,s);
      istringstream in(s);
      in >> W >> H;
      while(in >> token)
         word_size.push_back(sz(token)); 
      for(font_size = 1200; font_size >= 0; --font_size) {
         cur_w = cur_h = 0;
         line = 1;
         cnt = 0;
         for(int i = 0; i < sz(word_size); ++i) {
            if(i > 0) {
               if(cur_w + font_size > W)
                  ++line, cur_w = 0;
               else
                  cur_w+=font_size;
            }
            if(cur_w + word_size[i]*font_size <= W) {
               cur_w+=word_size[i]*font_size;
               cnt++;
            } else {
               line++;
               cur_w = 0;
               if(word_size[i]*font_size <= W) {
                  cur_w = word_size[i]*font_size;
                  cnt++;   
               }
            }
         }
         if(cnt == sz(word_size) 
            && line * font_size <= H) break;
      }
      printf("Case #%d: %d\n",tc,font_size);
   }
   return 0;
}

