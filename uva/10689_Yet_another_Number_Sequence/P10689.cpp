/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10689  C++  "Matrix Exponentation" */
#include <algorithm>
#include <cassert>
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define pb push_back

int A, B, N, M, MOD;


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
   assert(a.cols==b.rows);
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
   assert(a.rows==b.rows && a.cols==b.cols);
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

int TP[] = {1,10,100,1000,10000};

int main() {
   int TC;
   scanf("%d",&TC);
   Matrix<long long> M1(2,2), M2(2,1), ans;
   while(TC-- > 0) {
      scanf("%d%d%d%d", &A, &B, &N, &M);
      M1[0][0] = 1; M1[0][1] = 1;
      M1[1][0] = 1; M1[1][1] = 0;
      M2[0][0] = B;
      M2[1][0] = A;
      MOD = TP[M];
      M1 = M1.matrix_pow(M1,N);
      ans = M1*M2;
      if(N==0) printf("%d\n",A%MOD);
      else if(N==1) printf("%d\n",B%MOD);
      else printf("%lld\n",ans[1][0]%MOD);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
