/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PUCMM025 C++ "Ad Hoc, String Manipulation" */
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

const int MAXN = 52;
string s, message;
vector<int> image[MAXN];
int mask[] = {3,12,48};

int encode(char ch) {
   if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 1;
   else if(ch >= 'a' && ch <= 'z') return ch - 'z' + 27;
   else if(ch >= '0' && ch <= '9') return ch - '0' + 53;
   return 0;
}

void tobin(int n) {
   for(int i = 7; i >= 0; --i) {
      if(n & (1<<i)) cout << '1';
      else cout << '0';
   }
   cout << endl;
}

/*
* The image will be in the format of a sequence of digits where each three digits represent a number from 0 to 255, inclusive 
* (leading zeros will be added as necessary), which is a pixel value in the black and white image. 
* You will also be given the message you would like to encode into the image. You will first encode the message into 
* numbers representing the characters in the message - spaces will be 0, 'A'-'Z' will be 1-26, 'a'-'z' will be 27-52, '0'-'9' will be 53-62, and 63 will be used for any space after the message. 
* All these numbers can be represented in binary with 6 digits. You will put each pair of bits (representing a number between 0 and 3) 
* into the lowest two bits of the values in the image. For each character, you will put in the lowest two bits, then the middle two, 
* then the highest two, and then continue to the next character. You will put them in the lowest two bits of the first pixel on the 
* first row, then the second pixel on the first row, and so on until you get to the end of the first row, then the first pixel on the second row, and so on. Once you are out of characters, continue substituting the lowest two bits of each pixel value as if the current character were represented by number 63.

*/
int main(int argc, char *argv[]) {
   int TC, n, row, col, color;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin,s);
      DEBUG(s);
      sscanf(s.c_str(),"%d",&n);
      for(int i = 0; i < n; ++i) {
         getline(cin,s);
         for(int j = 0; j < sz(s); j+=3) {
            sscanf(s.substr(j,3).c_str(),"%d",&color);
            image[i].push_back(color);
         }
      }
      getline(cin,message);
      int i;
      for(i = 0, row = 0, col = 0; i < sz(message); ++i) {
         int ch = encode(message[i]);
         int im = image[row][col];
         for(int j = 0; j < 3; ++j) {
            int bmask = (ch & mask[j]) << j;
            tobin(bmask);
            im = im | bmask;
         }
         DEBUG(im);
         col++;
         if(col >= sz(image[row]))
            col = 0, row++;
      }
      
      /*
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < sz(image[i]); j+=3) {
            DEBUG(image[i].substr(j,3));  
         }
      }
      */
   }
   
   return 0;
}
/* @END_OF_SOURCE_CODE */
