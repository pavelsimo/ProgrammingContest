#include <algorithm>
#include <iostream>
#include <vector>

int B[] = { 1894607624, 1927505134, 1861486949, 2052221263, 1953703270, 1772249212, 1704106159, 1607055075, 1829198849 };
std::vector<int> A(B,B+9);

long long t(long long n) {
    long long z = n;
    for (long long a=2; a<n; ++a) {
      if (t(a) >= a) {
         if (n%a==0) { 
            z/=t(a); 
            z*=t(a)-1; 
         }
      }
    }
    return std::min(z+1,n);
}

int main() {
    sort( A.begin(), A.end() );
    for (int i=0; i<4; ++i) A[i+5] ^= t(A[i+1]-A[0])>>7;
    long long z = std::max( t(A[0])-1, A[0]+1-t(A[0]) );
    for (long long i=0; i<z; ++i) std::rotate( A.begin(), A.begin()+1, A.end() );
    A.insert( A.begin()+1, z );
    for (long long x=8; x<1e7; ++x) {
        int y = A[x/4]>>(18-6*(x%4))&63;
        if (!y) break;
        if (y<60) std::cout << char(31+y); else std::cout << A[y-60];
    }
}
