#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define DEBUG 1
typedef long long llong;

const int MAXN = 100000;
int a[MAXN + 10];

llong cnt = 0LL;

int mid(int *X, int i, int j, int k) {  
  if(X[i] > X[j] && X[j] > X[k]) return j;
  else if(X[j] > X[i] && X[i] > X[k]) return i;
  else if(X[i] > X[k] && X[k] > X[j]) return k;
  else if(X[j] > X[k] && X[k] > X[i]) return k;
  else if(X[k] > X[i] && X[i] > X[j]) return i;
  return j;
}

int partition(int *X, int l, int r) {
  int i, j;
  int m = l + ((r - l) / 2);
  swap(X[l], X[mid(X, l, r, m)]);
  int pivot = X[l];
  cnt+=r-l;
  for(j = i = l + 1; j <= r; ++j) {
    if(X[j] < pivot) {
      swap(X[i],X[j]);      
      i++;
    }
  }
  swap(X[l], X[i - 1]);
  return i - 1;
}

void quick_sort(int *X, int l, int r) {
  if(l >= r) return;
  int p = partition(X, l, r);
  quick_sort(X, l, p - 1);
  quick_sort(X, p + 1, r);
}

int main(int argc, char *argv[]) {
   int N = 0;
   while(scanf("%d",&a[N]) == 1) ++N;
   quick_sort(a,0,N-1);
   cout << cnt << endl;
   //for(int i = 0; i < N; ++i) printf("%d\n",a[i]);
   return 0;
}
// END CUT HERE
