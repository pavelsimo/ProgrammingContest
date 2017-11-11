/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    
    long long n;
    cin >> n;

    long long freq = 0;
    for(int i = 0; i < s.length(); ++i) {
        if (s[i] == 'a') ++freq;
    }

    long long cnt = (n / s.length()) * freq;
    long long rem = n % s.length();
    for (int i = 0; i < rem; ++i) {
        if (s[i] == 'a') cnt++;        
    }
    cout << cnt << endl;
    
    return 0;
}
