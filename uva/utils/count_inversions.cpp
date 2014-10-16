#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define DEBUG 1
typedef long long llong;

const int MAXN = 100000;
int a[MAXN + 10], b[MAXN + 10];

/* 
   consider the following case, where i, j represent 
   pointers in both halfs of the array:
      i     j
   [1 3 5] [2 4 6]
   because the 2 is going to be in front of the 
   3 and the 5 we count the number of remaining 
   elements as the number of inversions. The variable
   mid points to the end of the first half that's is
   why the number of remaining elements in this halfs
   is represented by the formula (mid - i) + 1.

*/
llong merge_and_count(int lo, int mid, int hi) {
   llong res = 0LL;
   int i, j, k;
   for(i = lo; i <= hi; ++i)
      b[i] = a[i];
   i = k = lo; 
   j = mid + 1;
   while(i <= mid && j <= hi) {
      if(b[i] <= b[j])
         a[k++] = b[i++];
      else {
         a[k++] = b[j++];
         res += mid - i + 1;
      }
   }
   while(i<=mid)
      a[k++] = b[i++];
   return res;
}

llong sort_and_count(int lo, int hi) {
   llong res = 0LL;
   if(lo < hi) {
      int mid = lo + (hi - lo) / 2;      
      res =sort_and_count(lo, mid);
      res+=sort_and_count(mid + 1, hi);
      res+=merge_and_count(lo, mid, hi);      
   }
   return res;
}

int main(int argc, char *argv[]) {
   for(int i = 0; i < MAXN; ++i)
      scanf("%d",&a[i]);
   printf("%lld\n",sort_and_count(0,MAXN-1));
   //for(int i = 0; i < MAXN; ++i)
   //   printf("%d\n",a[i]);
   return 0;
}
// END CUT HERE
