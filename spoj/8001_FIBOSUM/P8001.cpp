/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FIBOSUM C++ "Ad Hoc" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

const llong MOD = 1000000007LL;

template <class T>
class Matrix {
public:
   vector<vector<T> > mat;
   size_t rows, cols;
   Matrix( vector<vector<T> > _mat, size_t _N, size_t _M)  {
      mat = _mat;
      rows = _N;
      cols = _M;
   }
   Matrix(size_t _N = 1, size_t _M = 1) {
      mat = vector<vector<T> >(_N,vector<T>(_M));
      rows = _N;
      cols = _M;
   }
   
   Matrix<T> mult(const Matrix<T> &a, const Matrix<T> &b);
   Matrix<T> sum(const Matrix<T> &a, const Matrix<T> &b);
   Matrix<T> get_identity(const int N);
   Matrix<T> matrix_pow(const Matrix<T> &cur, int exp);
   void print();
   
   // operators
   template <typename TT>
   Matrix<TT> operator*(const Matrix<TT> &a) { return mult(*this,a); }
   template <typename TT>
   Matrix<TT> operator+(const Matrix<TT> &a) { return sum(*this,a); }
   vector<T>& operator[](const T a){ return mat[a]; }
};

template <class T>
Matrix<T> Matrix<T>::mult(const Matrix<T> &a, const Matrix<T> &b) {
   Matrix<T> ans(a.rows,b.cols);
   for(int k = 0; k < int(a.cols); ++k) {
      for(int i = 0; i < int(a.rows); ++i) {
         for(int j = 0; j < int(b.cols); ++j) {
            ans.mat[i][j] += ((a.mat[i][k]%MOD)*(b.mat[k][j]%MOD))%MOD;
         }
      }
   }
   return ans;
}

template <class T>
Matrix<T> Matrix<T>::sum(const Matrix<T> &a, const Matrix<T> &b) {
   Matrix<T> ans(a.rows,a.cols);
   for(int i = 0; i < int(a.rows); ++i) {
      for(int j = 0; j < int(a.cols); ++j) {
         ans[i][j] = a[i][j] + b[i][j];
      }
   }
   return ans;
}

template <class T>
Matrix<T> Matrix<T>::get_identity(const int _N) {
   Matrix<T> ans(_N,_N);
   for(int i = 0; i < _N; ++i)
      ans[i][i] = 1;
   return ans;
}

template <class T>
Matrix<T> Matrix<T>::matrix_pow(const Matrix<T> &cur, int exp) {
   if(exp==0) return get_identity(cur.rows);
   if(exp & 1) {
      return matrix_pow(cur,exp-1)*cur;
   } else {
      Matrix<T> _m;
      _m = matrix_pow(cur,exp >> 1);
      return _m*_m;
   }
}

template <class T>
void Matrix<T>::print() {
   for(int i = 0; i < int(rows); ++i) {
      for(int j = 0; j < int(cols); ++j)
         cout << mat[i][j] << " ";
      cout << endl;
   }
}

int main() {
   llong N, M;
   Matrix<llong> M1(2,2), M2(2,2), M3(2,1), ans1, ans2;
   int TC;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%lld",&N,&M);
      M1[0][0] = 1; M1[0][1] = 1; // | 1 1 |
      M1[1][0] = 1; M1[1][1] = 0; // | 1 0 |
      M2[0][0] = 1; M2[0][1] = 1; // | 1 1 |
      M2[1][0] = 1; M2[1][1] = 0; // | 1 0 |            
      M3[0][0] = 1; // f(n)
      M3[1][0] = 0; // f(n-1)
      M1 = M1.matrix_pow(M1,max(0LL,N+1LL));
      M2 = M2.matrix_pow(M2,max(0LL,M+2LL));
      ans1 = M1*M3;
      ans2 = M2*M3;
      printf("%lld\n",(MOD + ans2[1][0]-ans1[1][0])%MOD);      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
