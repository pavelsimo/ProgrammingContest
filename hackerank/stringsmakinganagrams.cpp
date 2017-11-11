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


const int MAXN = 26;

int main(){
    int freq[MAXN];
    
    string a;
    cin >> a;
    
    string b;
    cin >> b;

    for(int i = 0; i < MAXN; ++i) {
        freq[i] = 0;
    }
    
    for(int i = 0; i < a.size(); ++i) {
        freq[a[i]-'a']++;
    }

    for(int i = 0; i < b.size(); ++i) {
        freq[b[i]-'a']--;        
    }

    int res = 0;
    for(int i = 0; i < MAXN; ++i) {
        res += abs(freq[i]);
    }

    cout << res << endl;
    
    return 0;
}
