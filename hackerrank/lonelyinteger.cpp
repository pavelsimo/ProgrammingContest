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


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
       cin >> a[i];
    }

    int res = a[0];
    for(int i = 1; i < n; ++i) {
        res ^= a[i];
    }
    
    cout << res << endl;   
        
    return 0;
}
