/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 10082  C++  "Ad Hoc" */
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

int main() {
    map<char, char> M; 
    string s;
    M['P'] = 'O';
    M['O'] = 'I';
    M['I'] = 'U';
    M['U'] = 'Y';
    M['Y'] = 'T';
    M['T'] = 'R';
    M['R'] = 'E';
    M['E'] = 'W';
    M['W'] = 'Q';
    M['L'] = 'K';
    M['K'] = 'J';
    M['J'] = 'H';
    M['H'] = 'G';
    M['G'] = 'F';
    M['F'] = 'D';
    M['D'] = 'S';
    M['S'] = 'A';
    M['M'] = 'N';
    M['N'] = 'B';
    M['B'] = 'V';
    M['V'] = 'C';
    M['C'] = 'X';
    M['X'] = 'Z';   
    M['='] = '-';
    M['-'] = '0';
    M['0'] = '9';
    M['9'] = '8';
    M['8'] = '7';
    M['7'] = '6';
    M['6'] = '5';
    M['5'] = '4';
    M['4'] = '3';
    M['3'] = '2';
    M['2'] = '1';
    M['1'] = '`';
    M['\''] = ';';
    M[';'] = 'L';
    M['\\'] = ']';
    M[']'] = '[';
    M['['] = 'P';
    M['/'] = '.';
    M['.'] = ',';
    M[','] = 'M';
    while(getline(cin,s)!=NULL) {
        int n = s.length();
        for(int i = 0; i < n; ++i) {
             if(M.find(s[i]) != M.end())
                s[i] = M[s[i]];
        }
        cout << s << endl;
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
