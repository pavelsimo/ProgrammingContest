/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ANARC08B C++ "Ad Hoc" */
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

char D[128];
string E[10];

int decode(string s) {
    string res = "";
    for(int i = 0; i < sz(s); i+=3) {
        string t = s.substr(i,3);
        int j = atoi(t.c_str());
        res+=D[j];
    }
    return atoi(res.c_str());
}

string encode(int n) {
    stringstream out;
    string res = "", s;
    out << n;
    s = out.str();
    for(int i = 0; i < sz(s); ++i) {
        int j = s[i]-'0';
        if(sz(E[j])==2) res+="0";
        res+=E[j];
    }
    return res;
}

int main(int argc, char *argv[]) {  
    string buf, a, b;
    D[63]  = '0'; E[0] = "63";
    D[10]  = '1'; E[1] = "10";
    D[93]  = '2'; E[2] = "93";
    D[79]  = '3'; E[3] = "79";
    D[106] = '4'; E[4] = "106";
    D[103] = '5'; E[5] = "103";
    D[119] = '6'; E[6] = "119";
    D[11]  = '7'; E[7] = "11";
    D[127] = '8'; E[8] = "127";
    D[107] = '9'; E[9] = "107";
    while(getline(cin,buf)) {
        if(buf[0]=='B') break;
        istringstream in(buf);
        getline(in,a,'+');
        getline(in,b,'=');
        int x = decode(a);
        int y = decode(b);
        cout << buf << encode(x+y) << endl;
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
