#include <iostream>
#include <exception>

using namespace std;

class empty_stack_exception : public exception {
   virtual const char* what() const throw() {
      return "stack: empty stack error";
   }
} ex_empty_stack;


template <class T>
class stack {
   
   private:
      struct node {
         node *next;
         T item;
         node(T _item) {
            item = _item;
         }
      };
      
      node *head;
      size_t N;
   
   public:   

      
      stack() {
         head = NULL;
      }
     
      void push(T x) {
         node *new_head = new node(x);
         ++N;
         if(head == NULL) {
            head = new_head;
         } else {
            node *prev_head = head;
            head = new_head;
            head->next = prev_head;
         }
      }
      
      T top() {
         if(head == NULL) 
            throw ex_empty_stack;         
         return head->item;
      }
      
      void pop() {
         if(head == NULL) 
            throw ex_empty_stack;
         --N;
         node *t = head;
         head = head->next;
         delete t;
      }
           
      bool empty() const {
         return head == NULL;
      }
      
      size_t size() const {
         return N;
      }
};


int main() {
   stack<string> *s = new stack<string>();
   s->push("pavel");
   s->push("brenda");
   s->push("carlos");
   while(!s->empty()) {
      cout << s->top() << endl;
      s->pop();
   }
   return 0;
}
