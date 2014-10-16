/*
ID: 0000
PROG: friday
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

int leap(int year) {
    if ((year%400)==0) return 1;
    else if ((year%100)==0) return 0;
    else if ((year%4)==0) return 1;
    return 0;
}

int main() {
    ifstream fin("friday.in");    
    ofstream fout("friday.out");
    int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int weeks[] = {0,0,0,0,0,0,0};
    int N, sy=1900, w=1;
    fin >> N;
    for(int i = sy; i < sy+N; ++i) {
        if ( leap(i) ) months[2] = 29;
        else months[2] = 28;
        for(int cm = 1; cm <= 12; cm++) {
            for(int d = 1; d <= months[cm]; ++d) {
                if (d==13) weeks[w]++;  
                w++;
                w%=7;              
            }
        }
    }
    fout << weeks[6] << " " 
         << weeks[0] << " " 
         << weeks[1] << " " 
         << weeks[2] << " " 
         << weeks[3] << " " 
         << weeks[4] << " " 
         << weeks[5] 
         <<  endl;
    return 0;
}
