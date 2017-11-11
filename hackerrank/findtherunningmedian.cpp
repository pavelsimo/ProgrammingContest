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
    scanf("%d", &n);

    int x;
    priority_queue<int> hi;   
    priority_queue<int, vector<int>, greater<int> > lo;    
    double m = 0;
    
    for(int i = 0; i < n; ++i) {        
        scanf("%d", &x);        

        if(x < m)
            hi.push(x);
        else
            lo.push(x);
       
        int hi_size = hi.size();
        int lo_size = lo.size();
       
        if (hi_size - lo_size > 1) {
            int t = hi.top();
            hi.pop();
            lo.push(t);
        }       
       
        if (lo_size - hi_size > 1) {
            int t = lo.top();
            lo.pop();
            hi.push(t);
        }       

        if ((i+1) % 2 == 0) {
            int a1 = lo.top();
            int a2 = hi.top();
            m = (a1 + a2) / 2.0;
        } else {
            int a1;
            if(hi.size() > lo.size())
                a1 = hi.top();
            else
                a1 = lo.top();
            m = a1;
        }
        
        printf("%.1f\n", m);
    }

    return 0;
}
