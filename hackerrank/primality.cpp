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
    int p;
    cin >> p;
    for(int i = 0; i < p; ++i) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "Not prime\n";
        } else if (n == 2) {
            cout << "Prime\n";
        } else if (n % 2 == 0) {
            cout << "Not prime\n";
        } else {
            bool isprime = true;
            for(long long x = 3; x * x <= n; x += 2) {
                if(n % x == 0) {
                    isprime = false;
                    break;
                }
            }
            cout << (isprime ? "Prime" : "Not prime") << "\n";            
        }
    }        
    return 0;
}
