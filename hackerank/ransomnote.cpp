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
    int m;
    int n;
    cin >> m >> n;

    string s;
    map<string, int> magazine;
    for(int i = 0;i < m; ++i){
        cin >> s;
        magazine[s]++;
    }

    bool res = true;    
    for(int i = 0; i < n; ++i){
        cin >> s;
        if(magazine.find(s) != magazine.end()) {
            if(magazine[s] > 0) {
                magazine[s]--;
            } else {
                res = false;
            }
        } else {
            res = false;
        }
    }
    
    if(res)
        cout << "Yes\n";
    else
        cout << "No\n";
    
    return 0;
}
