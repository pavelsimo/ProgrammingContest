#include <cstdio>
#include <cstring>

//#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
// http://acm.uva.es/board/viewtopic.php?f=22&t=42601&hilit=719&sid=5968410ebb6974e716001b3602b2f772

 // Suffix array in $O(n \log^2 n)$ time, 16 bytes/char overhead.
 // Input: text, N
 // Output:
 //   sa[] is a sorted list of offsets to all non-empty suffixes,
 //   lcp[i] = length of longest common prefix of text+sa[i] and text+sa[i+1]
 char text[MAX]; long long key[MAX]; int N, sa[MAX], rank[MAX], *lcp=(int*)key;
 struct Cmp { bool operator()(int i, int j) const { return key[i]<key[j]; } };

 void build() {
     for (int i = 0; i < N; i++) { sa[i] = i; key[i] = text[i]; }
     sort(sa, sa+N, Cmp());
     for (int K = 1; ; K *= 2) {
         // invariant: suffixes are now sorted by their first K characters
         for (int i = 0; i < N; i++)
             rank[sa[i]] = i>0 && key[sa[i-1]]==key[sa[i]] ? rank[sa[i-1]] : i;
         if (K >= N) break;

         // sort suffixes by key (rank of this suffix, rank of suffix K chars ahead)
         for (int i = 0; i < N; i++)
             key[i] = rank[i] * (N+1LL) + (i+K < N ? rank[i+K]+1 : 0);
         sort(sa, sa+N, Cmp());
         // now they're sorted by their first 2K characters
     }

     // Kasai's algorithm for LCP array:
     for (int i = 0, k = 0; i < N; i++) {
         if (k > 0) k--;
         if (rank[i] == N-1) { lcp[N-1] = -1; k = 0; continue; }
         int j = sa[rank[i]+1];
         while (text[i+k] == text[j+k]) k++;
         lcp[rank[i]] = k;
     }
 }
*/

    // Suffix array in $O(n \log^2 n)$ time, 16 bytes/char overhead.
    // Input: text, N
    // Output:
    //   sa[] is a sorted list of offsets to all non-empty suffixes,
    //   lcp[i] = length of longest common prefix of text+sa[i] and text+sa[i+1]
    char text[MAX]; long long key[MAX]; int N, sa[MAX], rank[MAX], *lcp=(int*)key;
    struct Cmp { bool operator()(int i, int j) const { return key[i]<key[j]; } };

    void build() {
        for (int i = 0; i < N; i++) { sa[i] = i; key[i] = text[i]; }
        sort(sa, sa+N, Cmp());
        for (int K = 1; ; K *= 2) {
            // invariant: suffixes are now sorted by their first K characters
            for (int i = 0; i < N; i++)
                rank[sa[i]] = i>0 && key[sa[i-1]]==key[sa[i]] ? rank[sa[i-1]] : i;
            if (K >= N) break;

            // sort suffixes by key (rank of this suffix, rank of suffix K chars ahead)
            for (int i = 0; i < N; i++)
                key[i] = rank[i] * (N+1LL) + (i+K < N ? rank[i+K]+1 : 0);
            sort(sa, sa+N, Cmp());
            // now they're sorted by their first 2K characters
        }

        // Kasai's algorithm for LCP array:
        for (int i = 0, k = 0; i < N; i++) {
            if (k > 0) k--;
            if (rank[i] == N-1) { lcp[N-1] = -1; k = 0; continue; }
            int j = sa[rank[i]+1];
            while (text[i+k] == text[j+k]) k++;
            lcp[rank[i]] = k;
        }
    }


/*
 * http://forums.topcoder.com/?module=Thread&threadID=627379&start=0
 * Author: irancolfusion
 * O(N lg^2 N) suffix sorting
 */

/*
#define MAXN 10000000

int N;
char str[MAXN];

int Bucket[MAXN], nBucket[MAXN];
 
int Pos[MAXN];  // Pos[j] is the starting index of suffix str[ Pos[j] .. N-1 ]

struct CmpPosLessThan {
// Compares two suffixes based on their first 2H symbols,
// assuming we know the result for H symbols.
   int H;
   CmpPosLessThan(int _H) : H(_H) {}
   bool operator()(int x, int y) const {
      if (H == 0)
         return str[x] < str[y];
      return
         Bucket[x] == Bucket[y] ? 
            (Bucket[x+H] < Bucket[y+H]) :
            (Bucket[x  ] < Bucket[y  ]);
   }
};

struct CmpPosNotEqual {
   int H;
   CmpPosNotEqual(int _H) : H(_H) {}
   bool operator()(int x, int y) const {
      if (H == 0)
         return str[x] != str[y];
      return
         Bucket[x] == Bucket[y] ? 
            (Bucket[x+H] != Bucket[y+H]) :
            (Bucket[x  ] != Bucket[y  ]);
   }
};

 
bool UpdateBuckets(int H) {
   int start = 0, id = 0;
   bool c = false;
   CmpPosNotEqual ne(H);
   nBucket[Pos[0]] = 0;
   for (int i = 1; i < N; i++) {
      // If Pos[i] is not equal to Pos[i-1], a new bucket has started.
      if (ne(Pos[i], Pos[i-1])) {
         start = i;
         id++;
      }
   // if (i != start) // if there is bucket with size larger than 1, we should continue ...
      else
         c = true;
      nBucket[Pos[i]] = id; // Bucket for suffix starting at Pos[i] is id ...
   }
   memcpy(Bucket, nBucket, N * sizeof(int));
   return c;
}
 
void SuffixSort() {
   for (int i = 0; i < N; i++)
      Pos[i] = i;

   // H == 0, Sort based on first Character.
   sort(Pos, Pos + N, CmpPosLessThan(0));

   // Update Buckets based on first 2*H symbols; H=0 -> create initial buckets
   bool c = UpdateBuckets(0);
   for (int H = 1; c; H *= 2) {
      // Sort based on first 2*H symbols, assuming that we have sorted based on first H character
      sort(Pos, Pos+N, CmpPosLessThan(H));
      c = UpdateBuckets(H);
   }
}
*/

/*
class SuffixArray {
   int *bucket, *tbucket;
   bool cmp_ne_bucket(int x, int y, int H) const {
      return bucket[ x ] != bucket[ y ] ?
               (bucket[ x   ] != bucket[ y   ]) :
               (bucket[ x+H ] != bucket[ y+H ]);
   }
   bool update_buckets(int H = 0) {
      int start = 0, id = 0;
      bool more = false;
      if (H == 0) {
         for (int i = 1; i < N; ++i) {
            // If pos[i] <> pos[i-1], a new bucket has started.
            if (str[ pos[i] ] != str[ pos[i-1] ]) {
               start = i;
               ++id;
            }
         // if (i != start)   // if there is bucket with size larger than 1, we should continue ...
            else
               more = true;
            tbucket[ pos[i] ] = id;      // bucket for suffix starting at Pos[i] is id ...
         }
      }
      else {
         for (int i = 1; i < N; ++i) {
            // If pos[i] <> pos[i-1], a new bucket has started.
            if (cmp_ne_bucket(pos[i], pos[i-1], H)) {
               start = i;
               ++id;
            }
         // if (i != start)   // if there is bucket with size larger than 1, we should continue ...
            else
               more = true;
            tbucket[ pos[i] ] = id;      // bucket for suffix starting at Pos[i] is id ...
         }
      }
      tbucket[ pos[0] ] = 0;
      memcpy(bucket, tbucket, N*sizeof(int));
      return more;
   }
   struct CmpLtFirstChar {
      char *str;
      CmpLtFirstChar(char *_str) : str(_str) {}
      bool operator() (const int x, const int y) const {
         return str[x] < str[y];
      }
   };
   struct CmpLtBucket {
      int *B, H;
      CmpLtBucket(int *_B, int _H) : B(_B), H(_H) {}
      bool operator() (const int x, const int y) const {
         return B[x] != B[y] ? (B[x] < B[y]) : (B[x+H] < B[y+H]);
      }
   };
public:
   int N;
   char *str;
   int *pos;
   int *rank;
   int *lcp_len;

   SuffixArray(int _N)
      : N(_N), str(new char[N]), pos(NULL), rank(NULL), lcp_len(NULL)
   {
      str[0] = 0;
   }
   SuffixArray(const char *s)
      : N(s ? strlen(s)+1 : 1), str(new char[N]),
      pos(NULL), rank(NULL), lcp_len(NULL) {
      memcpy(str, s, N*sizeof(char));
   }
   ~SuffixArray() {
      delete[] str;
      delete[] pos;
      delete[] rank;
      delete[] lcp_len;
   }

   // O(N lg^2 N) suffix sorting
   void suffix_sort() {
      N = strlen(str) + 1;
      delete[] pos;
      pos = new int[N];
      for (int i = 0; i < N; ++i)
         pos[i] = i;
      std::sort(pos, pos+N, CmpLtFirstChar(str));
      bucket  = new int[N];
      tbucket = new int[N];
      if (update_buckets()) {
         for (int H = 1; ; H <<= 1) {
            std::sort(pos, pos+N, CmpLtBucket(bucket, H));
            if (!update_buckets(H))
               break;
         }
      }
      rank = new int[N];
      for (int i = 0; i < N; ++i)
         rank[pos[i]] = i;
      delete[] bucket;
      delete[] tbucket;
   }

   // O(n) longest common prefix algorithm
   void build_lcp() {
   // Precondition: suffix_sort() has been called
   // suffix_sort();
#ifdef USE_VECTOR
      lcp_len = vector<int>(N);
#else
      delete[] lcp_len;
      lcp_len = new int[N];
#endif
      lcp_len[0] = 0;
      for (int i = 0, h = 0; i < N; ++i) {
         if (rank[i] > 0) {
            int j = pos[rank[i]-1];
            for (; i + h < N && j + h < N && str[i+h] == str[j+h]; ++h);
            lcp_len[rank[i]] = h;
            if (h > 0)
               --h;
         }
      }
   }
};
*/





/*
 * http://forums.topcoder.com/?module=RevisionHistory&messageID=1171511
 * I'd recommend reading the paper "Linear-Time Longest-Common-Prefix
 * Computation in Suffix Arrays and Its Applications" by Toru Kasai, Gunho Lee,
 * Hiroki Arimura, Setsuo Arikawa, and Kunsoo Park.
 * 
 * It shows how to find the length of the longest common prefixes between
 * consecutive suffixes in linear time, in around 10 lines of code.
 * 
 * I also wanted to share my implementation of Manber & Myers algorithm which
 * is also on edit. I got Accepted on SUBST1 with it.
*/

// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm
// Refer to "Suffix arrays: A new method for on-line string searches",
// by Udi Manber and Gene Myers
 
//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
// That's it!
 
//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// rank = The inverse of the suffix array. rank[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> rank[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if rank[i] < rank[j]

/*
#define N 100000

int str[N]; //input
int rank[N], pos[N]; //output
int cnt[N], next[N]; //internal
bool bh[N], b2h[N];
 
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}
 
void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);
  //{pos contains the list of suffixes sorted by their first character}
 
  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      next[i] = j;
      buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing strings starting with the same h characters}
 
    for (int i = 0; i < n; i = next[i]){
      cnt[i] = 0;
      for (int j = i; j < next[i]; ++j){
        rank[pos[j]] = i;
      }
    }
 
    cnt[rank[n - h]]++;
    b2h[rank[n - h]] = true;
    for (int i = 0; i < n; i = next[i]){
      for (int j = i; j < next[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = rank[s];
          rank[s] = head + cnt[head]++;
          b2h[rank[s]] = true;
        }
      }
      for (int j = i; j < next[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[rank[s]]){
          for (int k = rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[rank[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    rank[pos[i]] = i;
  }
}
// End of suffix array algorithm
 
 
// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
int height[N];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void getHeight(int n){
  for (int i=0; i<n; ++i) rank[pos[i]] = i;
  height[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (rank[i] > 0){
      int j = pos[rank[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      height[rank[i]] = h;
      if (h > 0) h--;
    }
  }
}
*/

// End of longest common prefixes algorithm
 

class SuffixArray {
   struct CmpLtFirstChar {
      const char *str;
      CmpLtFirstChar(char *_str) : str(_str) {}
   // CmpLtFirstChar(const string& _s) : str(_s.c_str()) {}
      bool operator() (const int x, const int y) const {
         return str[x] < str[y];
      }
   };
public:
   int N;

   // INPUT string
   char *str;

   // OUTPUT:
   // pos = The suffix array. Contains the N suffixes of str sorted in
   //       lexicographical order.  Each suffix is represented as a single
   //       integer (the position of str where it starts).
   // rank = The inverse of the suffix array.
   //        rank[i] = the index of the suffix str[i..n) in the pos array.
   //        (In other words,  rank[i] = k <=> pos[k] = i)
   //        With this array, you can compare two suffixes in O(1):
   //        Suffix str[i..N) is smaller than str[j..n) IFF rank[i] < rank[j]
   // lcp_len[i] = length of longest common prefix of suffix str[pos[i]..N)
   //              and suffix str[pos[i-1]..N);   lcp_len[0] = 0

#ifdef USE_VECTOR
   vector<int> pos;
   vector<int> rank;
   vector<int> lcp_len;
#else
   int *pos;
   int *rank;
   int *lcp_len;
#endif

   SuffixArray(int _N);
   SuffixArray(const char *s);
   ~SuffixArray();

   // O(n log n) - Manber and Myers suffix sort algorithm
   void suffix_sort();

   // O(n) longest common prefix algorithm
   void build_lcp();

   int find(const char *s) const;
};

SuffixArray::SuffixArray(int _N)
   : N(_N+1), str(new char[N]), pos(NULL), rank(NULL), lcp_len(NULL) {
   str[0] = 0;
}

SuffixArray::SuffixArray(const char *s)
   : N ((s ? strlen(s) : 0)+1), str(new char[N]),
     pos(NULL), rank(NULL), lcp_len(NULL) {
   memcpy(str, s, N * sizeof(char));
}

SuffixArray::~SuffixArray() {
   delete[] str;
#ifndef USE_VECTOR
   delete[] pos;
   delete[] rank;
   delete[] lcp_len;
#endif
}

void SuffixArray::suffix_sort() {
   N = strlen(str) + 1;
#ifdef USE_VECTOR
   pos = vector<int>(N);
   rank = vector<int>(N);
#else
   delete[] pos;
   delete[] rank;
   pos = new int[N];
   rank = new int[N];
#endif
   for (int i = 0; i < N; ++i)
      pos[i] = i;

   // sort suffixes according to their first characters
#ifdef USE_VECTOR
   std::sort(pos.begin(), pos.end(), CmpLtFirstChar(str));
#else
   std::sort(pos, pos + N, CmpLtFirstChar(str));
#endif

#ifdef USE_VECTOR
   vector<bool> bh(N), b2h(N);
   vector<int> cnt(N), nxt(N);
#else
   bool *bh  = new bool[N];
   bool *b2h = new bool[N];
   int *cnt = new int[N];
   int *nxt = new int[N];
   memset(b2h, 0, N*sizeof(bool));
#endif

   bh[0] = true;
   for (int i = 1; i < N; ++i)
      bh[i] = str[pos[i]] != str[pos[i-1]];

   for (int h = 1; h < N; h <<= 1) {
      // bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]
      int buckets = 0;
      for (int i = 0; i < N; ) {
         int j = i + 1;
         for (; j < N && !bh[j]; ++j);
         nxt[i] = j;
         buckets++;
         i = j;
      }
      if (buckets == N) break;

      // Suffixes are separated in buckets containing strings starting with the same h characters
      for (int i = 0; i < N; i = nxt[i]) {
         cnt[i] = 0;
         for (int j = i; j < nxt[i]; ++j)
            rank[pos[j]] = i;
      }

      cnt[rank[N - h]]++;
      b2h[rank[N - h]] = true;

      for (int i = 0; i < N; i = nxt[i]) {
         for (int j = i; j < nxt[i]; ++j) {
            int s = pos[j] - h;
            if (s >= 0) {
               int head = rank[s];
               rank[s] = head + cnt[head]++;
               b2h[rank[s]] = true;
            }
         }
         for (int j = i; j < nxt[i]; ++j) {
            int s = pos[j] - h;
            if (s >= 0 && b2h[rank[s]]) {
               for (int k = rank[s]+1; k < N && !bh[k] && b2h[k]; ++k)
                  b2h[k] = false;
            }
         }
      }

      for (int i = 0; i < N; ++i) {
         pos[rank[i]] = i;
         if (b2h[i])
            bh[i] = true;
      }
   }

   for (int i = 0; i < N; ++i)
      rank[pos[i]] = i;

#ifndef USE_VECTOR
   delete[] cnt;
   delete[] nxt;
   delete[] b2h;
   delete[] bh;
#endif
}

void SuffixArray::build_lcp() {
// Precondition: suffix_sort() has been called
// suffix_sort();
#ifdef USE_VECTOR
   lcp_len = vector<int>(N);
#else
   delete[] lcp_len;
   lcp_len = new int[N];
#endif
   lcp_len[0] = 0;
   for (int i = 0, h = 0; i < N; ++i) {
      if (rank[i] > 0) {
         int j = pos[rank[i]-1];
         for (; i + h < N && j + h < N && str[i+h] == str[j+h]; ++h);
         lcp_len[rank[i]] = h;
         if (h > 0)
            --h;
      }
   }
}

int SuffixArray::find(const char *s) const {
   int lo = 0, hi = N-1;
   while (lo < hi) {
      int mid = lo + (hi-lo)/2;
      if (strcmp(str + pos[mid], s) >= 0)
         hi = mid;
      else
         lo = mid+1;
   }
   if (strcmp(str + pos[lo], s) < 0)
      return N;
   return lo;
}

/* // TOO SLOW!!!
int SuffixArray::find(const char *s) const {
   int L = 0, R = N-1;
   for (int j = 0; s[j]; ++j) {
      int lo = L, hi = R;
      while (lo < hi) {
         int mid = lo + (hi-lo)/2;
         if (str[ pos[mid]+j ] >= s[j])
            hi = mid;
         else
            lo = mid+1;
      }
      if (str[ pos[lo]+j ] < s[j])
         return R+1;
      L = lo;

   // lo = L;
      hi = R;
      while (lo < hi) {
         int mid = lo + (hi-lo+1)/2;
         if (str[ pos[mid]+j ] > s[j])
            hi = mid-1;
         else
            lo = mid;
      }
      if (str[ pos[lo]+j ] > s[j])
         return L;
      R = lo;
   }
   return L;
}
*/

int main(int argc, char *argv[]) {
   SuffixArray sa("abracadabra");
   sa.suffix_sort();
   sa.build_lcp();
   for (int i = 0; i < sa.N; i++) {
      printf("%4d: %3d ", i, sa.lcp_len[i]);
      putchar('"');
      fputs(sa.str + sa.pos[i], stdout);
      putchar('"');
      putchar('\n');
   }
   putchar('\n');

   const char *ss[] = {"acabyz", "acaxyz", "0", "xxx", "rat", "rab", "aaa", "a"};

   for (int j = 0; j < sizeof(ss)/sizeof(const char*); ++j) {
      printf("Position of string \"%s\" would be %d\n",
             ss[j], sa.find(ss[j]));
   }

   return 0;
}
