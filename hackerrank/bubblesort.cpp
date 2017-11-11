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
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int tot_swaps = 0;
    for (int i = 0; i < n; ++i) {
        int cnt_swaps = 0;   
        for (int j = 0; j < n - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                cnt_swaps++;
            }
        }
        if (cnt_swaps == 0) {
            break;
        }        
        tot_swaps += cnt_swaps;        
    }

    cout << "Array is sorted in " << tot_swaps << " swaps.\n";
    cout << "First Element: " << a[0] << "\n";
    cout << "Last Element: " << a[n-1] << "\n";        
    
    return 0;
}
