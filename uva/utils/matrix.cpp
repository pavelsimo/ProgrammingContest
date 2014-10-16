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
   
   Matrix<T> m_mult(const Matrix<T> &a, const Matrix<T> &b);
   Matrix<T> m_sum(const Matrix<T> &a, const Matrix<T> &b);
   Matrix<T> m_identity(const int N);
   Matrix<T> m_pow(const Matrix<T> &cur, int exp);
   void print();
   
   // operators
   template <typename TT>
   Matrix<TT> operator*(const Matrix<TT> &a) { return m_mult(*this,a); }
   template <typename TT>
   Matrix<TT> operator+(const Matrix<TT> &a) { return m_sum(*this,a); }
   vector<T>& operator[](const T a){ return mat[a]; }
};

template <class T>
Matrix<T> Matrix<T>::m_mult(const Matrix<T> &a, const Matrix<T> &b) {
   assert(a.cols==b.rows);
   Matrix<T> ans(a.rows,b.cols);
   for(int k = 0; k < int(a.cols); ++k) {
      for(int i = 0; i < int(a.rows); ++i) {
         for(int j = 0; j < int(b.cols); ++j) {
            ans.mat[i][j] += (a.mat[i][k]*b.mat[k][j]);
         }
      }
   }
   return ans;
}

template <class T>
Matrix<T> Matrix<T>::m_sum(const Matrix<T> &a, const Matrix<T> &b) {
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
Matrix<T> Matrix<T>::m_identity(const int _N) {
   Matrix<T> ans(_N,_N);
   for(int i = 0; i < _N; ++i)
      ans[i][i] = 1;
   return ans;
}

template <class T>
Matrix<T> Matrix<T>::m_pow(const Matrix<T> &cur, int exp) {
   if(exp==0) return m_identity(cur.rows);
   if(exp & 1) {
      return m_pow(cur,exp-1)*cur;
   } else {
      Matrix<T> _m;
      _m = m_pow(cur,exp >> 1);
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
   Matrix<long long> M1(4,4),M2(4,1),M3(4,1);
   M1[0][0] = 3; M1[0][1] = -1; M1[0][2] = -1; M1[0][3] = -2;
   M1[1][0] = 1;
   M1[2][1] = 1;
   M1[3][3] = 1;
   cout << endl;
   M1.print();
   M2[0][0] = 3; M2[1][0] = 1; M2[2][0] = 0; M2[3][0] = 0;
   cout << endl;
   M2.print();
   M1 = M1.m_pow(M1,4);
   cout << endl;
   M1.print();
   M3 = M1 * M2;
   cout << endl;
   M3.print();
   return 0;
}
