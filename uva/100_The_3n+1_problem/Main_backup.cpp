/* @BEGIN_OF_SOURCE_CODE */
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct node {
  string k;
  int v;
  node(string nk, int nv) {
    k = nk;
    v = nv;
  }
};
bool operator<(const node &a, const node &b) {
  if ( a.v != b.v ) 
    return b.v < a.v;
  return false;
}

int get_key(vector<node> &Q, vector<string> &qry, map<string, int> &D) {
    int best = Q[0].v;
    string t;
    for(int i = qry.size()-1; i >= 0; --i) {
        if ( D[qry[i]] == best ) {
            t = qry[i];
            break;
        }
    }
    for(int i = 0; i < Q.size(); ++i)
        if ( t == Q[i].k ) return i;
    return 0;
}


int main() {
    int n,m;
    string s;
    scanf("%d\n",&n);
    for(int i = 0; i < n; ++i) {
        map<string, int> D; 
        vector<string> memo;
        vector<string> querys;
        vector<node> Q;
        scanf("%d\n",&m);
        // iterate search engines
        for(int j = 0; j < m; ++j) {
            getline(cin,s);
            memo.push_back(s);
            D[s] = 0;
        }
        scanf("%d\n",&m);
        // iterate querys
        for(int j = 0; j < m; ++j) {
            getline(cin,s);
            D[s] = D[s]+1;
            querys.push_back(s);
            //cout << s << " " << D[s] <<  endl;
        }
        // iterate costs
        for(int j = 0; j < memo.size(); ++j) {
            Q.push_back(node(memo[j],D[memo[j]]));
            //cout << memo[j] << " " << D[memo[j]] <<  endl;
        }
        sort(Q.rbegin(),Q.rend());
        string top = Q[get_key(Q,querys,D)].k;
        int cnt = 0;
        for(int j = 0; j < querys.size(); ++j) {
            //cout << querys[j] << " == " << top <<  endl;    
            D[querys[j]]--;
            if ( querys[j] == top ) {
                cnt++;
                Q.clear();
                for(int k = 0; k < memo.size(); ++k)
                    Q.push_back(node(memo[k],D[memo[k]]));
                sort(Q.rbegin(),Q.rend());
                top = Q[get_key(Q,querys,D)].k;
            }   
            
            // DEBUG
            /*if ( i == 2 ) {
            cout << "top = " << top << endl;
            printf("query %d :\n",j+1);
            for(int j2 = 0; j2 < memo.size(); ++j2) {
                Q.push_back(node(memo[j2],D[memo[j2]]));
               cout << memo[j2] << " " << D[memo[j2]] <<  endl;
            }
            cout << "switch=" << cnt << endl;    
            cout << endl;
            }*/
            // END DEBUG
        }
        printf("Case #%d: %d\n",i+1,cnt);

    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
