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

int M[1002][1002],V[1002][1002],t,k;

int d(int r,int c){
      if(r>=k)return 0;
      if(M[r][c]>=0)return M[r][c];
      return M[r][c]=V[r][c]+max(d(r+1,c),d(r+1,c+1));
}
int main(){ 
   cin>>t; 
   while(t--){ 
      cin>>k; 
      for(int i=0;i<k;++i)
      for(int j=0;j<=i;++j)
         cin>>V[i][j], M[i][j] = -1;
      cout<<d(0,0)<<std::endl; 
   } 
   return 0;
}
