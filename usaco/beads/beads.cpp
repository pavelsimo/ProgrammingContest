/*
ID: 0000
PROG: beads
LANG: C++
*/
#include <cstring>
#include <algorithm>
#include <numeric>
#include <fstream>
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
#define DEBUG
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;


int main() {
    ifstream fin("beads.in");    
    ofstream fout("beads.out");
    int N,best=0;
    fin >> N;
    string s;
    fin.ignore(1 ,'\n');
    getline(fin,s);
    s = s + s;
    for(int i = 0; i < N; ++i) {
        int cnt = 0;
        char c = ' ';
        int e = 0;
        for(int j = 0; j < N; ++j) {
            if ( s[i+j] == 'w' ) { 
                cnt++;
                continue;
            }
            if ( c == ' ' ) c = s[i+j];
            if ( s[i+j] != c ) {
                c = s[i+j];
                if ( ++e == 2 ) break;
            }
            cnt++;
        }
        best = max(best,cnt);
    }
    fout << best << endl;
    return 0;
}
