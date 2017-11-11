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
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; ++i){
       cin >> c[i];
    }

    int k = 0;
    int res = 0;
    while(k < n - 1) {
        if(k + 2 < n && !c[k+2]) k += 2;
        else if(!c[k+1]) ++k;
        ++res;
    }

    cout << res << endl;
    
    return 0;
}
