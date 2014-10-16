/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240  499  C++  "Easy algorithm" */
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

class LettersFrequency {

    public:
        string getresult(string s) {
            string res = "";
            int N = 26;            
            int uppercase[N];
            int lowercase[N];

            for(int i = 0; i < N; ++i) {
                uppercase[i] = 0;
                lowercase[i] = 0;
            } 

            for(int i = 0; i < s.length(); ++i) {
                if ( isupper(s[i]) )
                    uppercase[s[i]-'A']++;
                else if ( islower(s[i]) )
                    lowercase[s[i]-'a']++;
            }

            int max_freq = -1;
            for(int i = 0; i < N; ++i) {
               max_freq = max(max_freq, uppercase[i]);
               max_freq = max(max_freq, lowercase[i]);
            }

            for(int i = 0; i < N; ++i) {
                if ( uppercase[i] == max_freq )
                    res+=(char)('A'+ i);
            }

            for(int i = 0; i < N; ++i) {
                if ( lowercase[i] == max_freq )
                   res+=(char)('a'+ i);
            }   
            
            if ( max_freq > 0 ) 
                res.append(" " + int2string(max_freq));
            else
                res = "";

            return res;
        }

        int max(int a, int b) {
            if ( a > b ) 
                return a;
            else 
                return b;
        }

        string int2string(const int& number)
        {
            ostringstream oss;
            oss << number;
            return oss.str();
        }

        void print(int array[], int N) {
            cout << "[";            
            for(int i = 0; i < N; ++i) {
                if ( i != 0 )
                    cout << ",";
                cout << array[i];                
            }
            cout << "]";
        }
};

int main() {
    LettersFrequency lf;
    string s = "";
    while ( getline(cin,s) ) {
        cout << lf.getresult(s) << endl;
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
