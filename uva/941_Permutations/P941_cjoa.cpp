/* @JUDGE_ID: 1131EP  941  C++  "Combinatorics" */
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <string>

using namespace std;

typedef long long llong;

llong fact[21];

int N;
int used[21];
char S[21];
char res[21];

string letters;
int freq[26];

int main(int argc, char* argv[]) {
   fact[0] = fact[1] = 1;
   for (int i = 2; i <= 20; ++i) {
      fact[i] = fact[i-1]*i;
   // printf("%d: %lld\n", i, fact[i]);
   }
   int TC;
   scanf("%d", &TC);
   while (TC-- > 0) {
      scanf("%s", S);
      N = strlen(S);

      memset(freq, 0, sizeof(freq));
      for (int i = 0; i < N; ++i)
         ++freq[ S[i]-'a' ];

      letters.clear();
      for (char c = 'a'; c <= 'z'; ++c)
         if (freq[c-'a'])
            letters += c;

      llong K;
      scanf("%lld", &K);

      for (int i = 0; i < N; ++i) {
         int j;
         for (j = 0; j < letters.size(); ++j) {
            if (freq[ letters[j]-'a' ] > 0) {
               llong d = fact[N-1-i];
               --freq[ letters[j]-'a' ];
               for (int k = 0; k < letters.size(); ++k)
                  d /= fact[ freq[ letters[k]-'a'] ];
               ++freq[ letters[j]-'a' ];
					// printf("* d: %lld\n", d);
               if (K - d < 0) break;
               K -= d;
            }
         }
      // printf("j: %d  K: %lld\n", j, K);
         res[i] = letters[j];
         freq[ letters[j]-'a' ]--;
      }

      res[N] = 0;
      puts(res);
   }
   return 0;
}
