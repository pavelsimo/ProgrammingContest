/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &s1, const string &s2) {
    if (s1.size() != s2.size())
        return s1.size() < s2.size();
    return s1 < s2;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}
