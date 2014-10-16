/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12532  C++  "Data Structure, Segment Tree, BIT" */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

#define DEBUG(x) cout << #x << ": " << x << endl

using namespace std;
typedef vector<int> VI;

const int MAXN = 1000002;
int zero[MAXN], neg[MAXN] , X[MAXN];

int read(int *tree, int idx) {
   int res = 0;
   while(idx > 0) {
      res+=tree[idx];
      idx-=(idx & -idx);
   }
   return res;
}

void update(int *tree, int idx, int val) {
   while(idx < MAXN) {
      tree[idx]+=val;  
      idx +=(idx & -idx);
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, q, x, ind, val, lo, hi;
   char cmd;
   while(cin >> n >> q) {
      memset(zero, 0, sizeof(zero)); 
      memset(neg, 0, sizeof(neg));
      for(int i = 1; i <= n; ++i) {
         cin >> x;
         if(x < 0) {
            // increase the cumulative frequency of the negative values
            update(neg,  i, +1);
         } else if(x == 0) {
            // increase the cumulative frequency of the zeros
            update(zero, i, +1);
         }
         X[i] = x;
      }
      while(q-- > 0) {
         cin >> cmd;
         if(cmd == 'C') {
            cin >> ind >> val;
            if(val < 0) {
               // negative value replace zero or positive
               // increase the negatives cumulative frequency
               if(X[ind] >= 0) update(neg,  ind, +1);
               
               // negative value replace zero
               // decrease the zeros cumulative frequency
               if(X[ind] == 0) update(zero, ind, -1);
            } else if(val == 0) {
               
               // zero value replace positive or negative
               // increase the zeros cumulative frequency
               if(X[ind] != 0) update(zero, ind, +1);
               
               // zero value replace positive or negative
               // decrease the negatives cumulative frequency
               if(X[ind] < 0) update(neg, ind, -1);
            } else {
               // positive value replace zero
               // decrease the zeros cumulative frequency
               if(X[ind] == 0) update(zero, ind, -1);
               
               // positive value replace negative
               // decrease the negatives cumulative frequency
               if(X[ind] < 0) update(neg, ind, -1);
            }
            X[ind] = val;
         } else {
            cin >> lo >> hi;
            
            // total count of zeros
            int z = read(zero, hi) - read(zero, lo - 1);
            
            // total count of negatives
            int m = read(neg, hi)  - read(neg, lo - 1);
            
            if(z > 0) cout << '0';
            else if(m & 1) cout << '-';
            else cout << '+';
         }
      }
      cout << '\n';
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
