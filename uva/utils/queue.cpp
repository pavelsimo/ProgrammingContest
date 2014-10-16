#include <iostream>
#include <exception>

using namespace std;

class NoSuchElementException : public exception {
   virtual const char* what() const throw() {
      return "NoSuchElementException: the queue is empty.";
   }
};

template <class T>
class queue {
   
   private:
      struct node {
         node *next;
         T item;
         node(T _item) {
            item = _item;
         }
      };
      size_t N;
      node *head;
      node *tail;
   
   public:
      
      void push(const T &x) {
         node *new_node = new node(x);
         if(empty()) {
            head = tail = new_node;
         } else {
            tail->next = new_node;
            tail = tail->next;
         }
         ++N;
      }
      
      T front() const {
         if(empty())
            throw NoSuchElementException();
         return head->item;
      }
      
      void pop() {
         if(empty())
            throw NoSuchElementException();
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
   queue<int> *q = new queue<int>();
   q->push(2);
   q->push(10);
   q->push(-25);
   q->push(100);
   while(!q->empty()) {
      cout << q->front() << endl;
      q->pop();
   }
   return 0;
}
