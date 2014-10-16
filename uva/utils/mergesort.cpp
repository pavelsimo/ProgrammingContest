#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define DEBUG 0

const int MAXN = 102;
int a[MAXN], b[MAXN];

void merge(int lo, int mid, int hi) {
   cout << mid - lo << ' ' << hi - mid + 1 << endl;
   int i, j, k;
   for(i = lo; i <= hi; ++i)
      b[i] = a[i];
   i = k = lo; 
   j = mid + 1;
   while(i <= mid && j <= hi) {
      if(b[i] <= b[j])
         a[k++] = b[i++];
      else
         a[k++] = b[j++];
   }
   while(i<=mid)
      a[k++] = b[i++];
}

void mergesort(int lo, int hi) {
   if(lo < hi) {
      int mid = lo + (hi - lo) / 2;      
      mergesort(lo, mid);
      mergesort(mid + 1, hi);
      merge(lo, mid, hi);
   }
}

int main(int argc, char *argv[]) {
   for(int i = 20; i >= 0; --i)
      a[20-i] = i;
   #if DEBUG
   for(int i = 0; i <= 20; ++i)
      cout << a[i] << ' ';
   #endif
   cout << endl;
   mergesort(0,20);
   #if DEBUG
   for(int i = 0; i <= 20; ++i)
      cout << a[i] << ' ';
   #endif
   return 0;
}
// END CUT HERE
