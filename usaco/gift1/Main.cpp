/*
ID: 0000
PROG: gift1
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
    int NP,k,m,c;
    map<string, int> M;
    vector<string> v;
    string p, cp;
    ifstream fin("gift1.in");    
    ofstream fout("gift1.out");
    fin >> NP;
    for(int i = 0; i <= NP; ++i) {
        getline(fin,p);
        M[p] = 0;
        v.push_back(p);
    }
    for(int i = 0; i < NP; ++i) {
        getline(fin,p);
        fin >> m >> k;
        fin.ignore(1, '\n');
        if ( k == 0 ) continue;
        c = m/k;
        for(int j = 0; j < k; ++j) {
            getline(fin,cp);
            M[cp] += c;
            M[p]  -= c;
        }
    }
    for(int i = 1; i <= NP; ++i)
        fout << v[i] << " " << M[v[i]] << endl;
    return 0;
}
