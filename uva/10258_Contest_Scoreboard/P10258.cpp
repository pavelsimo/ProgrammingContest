/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10258  C++  "Ad Hoc" */
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
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define pb push_back

char buf[256];
bool solved[102][12], vis[102];
int penalty[102][12], u_rank[102], u_penalty[102];

struct Node {
  int user;
  Node(int _user) : user(_user) { }
  bool operator<(const Node &T) const { 
     if(u_rank[T.user]!=u_rank[user]) return u_rank[T.user] < u_rank[user];
     if(u_penalty[T.user]!=u_penalty[user]) return u_penalty[T.user] > u_penalty[user];
     return T.user > user;
  }
};

int main(int argc, char *argv[]) {
   int TC, user, problem, time;
   char ch;
   gets(buf);
   sscanf(buf,"%d",&TC);
   gets(buf);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc>0) putchar('\n');
      memset(penalty,0,sizeof(penalty));
      memset(solved,false,sizeof(solved));
      memset(vis,false,sizeof(vis));
      memset(u_rank,0,sizeof(u_rank));
      memset(u_penalty,0,sizeof(u_penalty));
      vector<Node> a;
      while(gets(buf)) {
         if(strlen(buf)==0) break;  
         sscanf(buf,"%d %d %d %c",&user,&problem,&time,&ch);         
         if(!vis[user]) a.push_back(Node(user));
         vis[user]=true;
         if(ch=='C') {
            if(!solved[user][problem]) {
               penalty[user][problem]+=time;
               solved[user][problem]=true;
               u_rank[user]++;
               u_penalty[user]+=penalty[user][problem];
            }
         } else if(ch=='I') {
            penalty[user][problem]+=20;
         }
      }
      sort(all(a));
      for(int i = 0; i < sz(a); ++i) {
         printf("%d %d %d\n",a[i].user,u_rank[a[i].user],u_penalty[a[i].user]);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
