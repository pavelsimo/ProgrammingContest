/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') p.push(s[i]);
            else if (s[i] == ')' && (p.empty() || p.top() != '(')) return false;
            else if (s[i] == ']' && (p.empty() || p.top() != '[')) return false;
            else if (s[i] == '}' && (p.empty() || p.top() != '{')) return false;
            else p.pop();
        }
        return p.empty();
    }
};
