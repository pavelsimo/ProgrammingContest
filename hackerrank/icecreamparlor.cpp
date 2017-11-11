/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <bits/stdc++.h>
using namespace std;

class IceCream {
    
public: 
    int flavor; 
    int index;

    IceCream(int flavor_, int index_) : flavor(flavor_), index(index_) {
        
    }
};

bool cmp(const IceCream &lhs, const IceCream &rhs) {
    if (lhs.flavor != rhs.flavor)
        return lhs.flavor < rhs.flavor;
    return lhs.index < rhs.index;
}
    
int binarySearch(int first, int last, const vector<IceCream> &arr, int search) {
    int lo = first;
    int hi = last;    
    while (lo <= hi) {
        int mid = lo + ((hi - lo) / 2);
        if (arr[mid].flavor == search) {
            return arr[mid].index;
        } else if (search < arr[mid].flavor) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), cmp);
        
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;
                }
            }
        }

    }
}
