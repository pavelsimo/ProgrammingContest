/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {            
            stack_newest_on_top.push(x);
        }
    
        void move_to_oldest() {
            while(!stack_newest_on_top.empty()) {
                int x = stack_newest_on_top.top();
                stack_newest_on_top.pop();
                stack_oldest_on_top.push(x);
            }                        
        }    
    
        void pop() {            
            if(stack_oldest_on_top.empty()) {
                move_to_oldest();
            }            
            stack_oldest_on_top.pop();
        }

        int front() {
            if(stack_oldest_on_top.empty()) {
                move_to_oldest();
            }
            int res = stack_oldest_on_top.top();     
            return res;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    return 0;
}
