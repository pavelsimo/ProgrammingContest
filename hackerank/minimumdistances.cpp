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
    vector<int> A(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }


    int res = n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (i != j && A[i] == A[j]) {
                res = min(res, abs(i - j));
            }
        }
    }

    cout << (res < n ? res : -1) << endl;
    
    return 0;
}
