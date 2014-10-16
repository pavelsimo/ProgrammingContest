/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ RLM C++ "Ad Hoc" */
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

typedef unsigned long long ullong;

string decode_rtl(string s) {
    string res = "";
    int n = sz(s);
    for(int i = 1; i < n; i+=2)
        res+=string(s[i-1]-'0',s[i]);
    return res;
}

string encode_rtl(ullong x) {
    string s, res = "";
    stringstream out; out << x;
    s = out.str();
    int n = sz(s);
    for(int i = 0; i < n; ++i) {
        int j;
        for(j = 0; i+j < n && s[i] == s[i+j]; ++j);
        j = min(j,9);
        res+=('0'+j);
        res+=s[i];
        i = i+j-1;
    }
    return res;
}

int main(int argc, char *argv[]) {
    ullong a, b, c;
    string buf, s1, s2, opt;
    while(getline(cin,buf)) {
        istringstream in(buf);
        in >> s1 >> opt >> s2;
        sscanf(decode_rtl(s1).c_str(),"%llu",&a);
        sscanf(decode_rtl(s2).c_str(),"%llu",&b);
        if(opt[0]=='+') c = a+b;
        else if(opt[0]=='-') c = a-b;
        else if(opt[0]=='*') c = a*b;
        else if(opt[0]=='/') c = a/b;
        printf("%s = %s\n",buf.c_str(),encode_rtl(c).c_str());
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
