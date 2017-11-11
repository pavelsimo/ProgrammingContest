/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cassert>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 2002;

class Stack {
    
public:
    Stack() : head(-1) {}

    int size() {
        return head + 1;
    }
   
    bool empty() {
        return size() == 0;
    }
    
    char pop() {    
        char ch = '\0';
        if(!empty()) {
            ch = arr[head];
        }
        --head;
        if(head < -1)
            head = -1;
        return ch;
    }

    void push(char value) {
        assert(head <= MAXN);
        arr[++head] = value;    
    }

private:
    char arr[MAXN];
    int head;    
};

bool is_balanced(string s) {
    Stack b1;
    bool balanced = true;
    for(int i = 0; i < s.size(); ++i) {
        char bracket = s[i];
        if(bracket == '(' || bracket == '[' || bracket == '{') 
            b1.push(bracket);
        if(bracket == ')' && b1.pop() != '(') balanced = false;
        if(bracket == ']' && b1.pop() != '[') balanced = false;
        if(bracket == '}' && b1.pop() != '{') balanced = false;
    }    
    return b1.empty() && balanced;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        string s;
        cin >> s;
        bool answer = is_balanced(s);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }       
    return 0;
}
