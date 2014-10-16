const char Directory[300] = "/Users/carlosjosetoribio/NetBeansProjects/Run/dist/Release/GNU-MacOSX/run";

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long Long;
typedef vector<Long> VL;

VL calc(Long n) {
    VL ret(10,0);
    if(n<0)return ret;
    for(int i = 0; i < 10 ; ++i) {
        for(Long p = 1; p < 1000000000; p*=10) {
            Long cn = n/p , mo = n%p;
            ret[i] += ((cn+9-i)/10)*p + ((cn%10==i) ? (mo)+1 : 0) ;
            if(i==0) {
                if(cn > 0)ret[i] -= p;
                else ret[i] -= (n+1);
            }
        }
    }
    return ret;
}

int main(int argc, char** argv) {
    Long a,b;
    for(int tc = 1 ; cin >> a >> b && !(a==0 && b==0); ++tc) {
        if(a>b)swap(a,b);
        VL ansa = calc(a-1);
        VL ansb = calc(b);
        for(int i = 0; i < 10; ++i) {
            if(i<9)cout << ansb[i] - ansa[i] << " ";
            else cout << ansb[i] - ansa[i] << endl;
        }
    }
    return 0;
}
