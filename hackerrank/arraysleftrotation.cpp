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
    int k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);        
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i) {
        int j = (n + i - k) % n;
        b[j] = a[i];
    }
    
    /*
    k = n % k;
    while(k-- > 0) {
        int tmp = a[0];
        for(int i = 0; i < n - 1; ++i) {
            a[i] = a[i+1];
        }
        a[n-1] = tmp;
    }
    */
    
    for(int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << endl;
    
    return 0;
}
