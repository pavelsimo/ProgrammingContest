#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <set>

using namespace std;

template<class INT>
struct AVL {
   #define DEFAULT 1<<31
   int sz, h, un;
   INT val;
   AVL *r,*l,*p;
   AVL(INT _val = DEFAULT,AVL *_p=NULL){ un=sz=h=1 , r=l=NULL,p=_p , val=_val; }
   ~AVL(){if(l)delete l; if(r)delete r;}
   void rotate(bool left = true) {
      if(left) {
         swap(val,r->val);swap(r->r , r->l);
         swap(r->l,l);swap(l,r);
         l->updateH();
      } else {
         swap(val,l->val);swap(l->l,l->r);
         swap(l->r,r);swap(r,l);
         r->updateH();
      }
      this->updateH();
   }
   inline int getBF(){ return (l?l->h:0)-(r?r->h:0); }
   inline int updateH(){
      if(l)l->p = this; if(r)r->p = this;
      sz = (l?l->sz:0) + (r?r->sz:0) + 1;
      return h = max(l?(l->h):0 , r?(r->h):0)+1;
   }
   void balance() {
      updateH();
      if( this->getBF() == -2 )
      {
         if( r->getBF() == 1 ) r->rotate(false);
         this->rotate(true);
      }
      else if(this->getBF() == 2)
      {
         if( l->getBF() == -1 ) l->rotate(true);
         this->rotate(false);
      }
   }
   void insert(INT value,bool rep = true) {
      if(!un)*this = AVL(value);
      else if(val < value)
         if(r == NULL)r = new AVL(value,this);
         else r->insert(value, rep);
      else if(rep || value < val)
         if(l == NULL)l = new AVL(value,this);
         else l->insert(value, rep);
      balance();
   }
   int size(){
      return sz;
   }
   
   int count(INT nval)
   {
      if(nval > val) return r ? r->count(nval) : 0;
      else if(nval < val) return l ? l->count(nval) : 0;
      else return 1+(l?l->count(nval):0)+(r?r->count(nval):0);
   }
   
   int lower_bound(INT nval)
   {
      if(nval <= val)return l ? l->lower_bound(nval) : 0;
      else return sz - (r?r->sz:0) + (r?r->lower_bound(nval):0);
   }
   
   //kth term
   INT operator[](int k) {
      
      int szl = (l?l->sz:0);
      if( k == szl )return val;
      else if(k < szl)return (*l)[k];
      else return (*r)[k - szl - 1];
   }
   
   void erase(INT nval){int cnt = 1;this->erase(nval,cnt);}
   
   bool erase(INT nval, int &cnt) {
      if( nval < val && l ){
         if( l->erase(nval , cnt) )l = NULL;
         balance(); return false;
      }
      else if(nval > val && r){
         if( r->erase(nval , cnt) )r = NULL;
         balance(); return false;
      }
      else if(nval==val)
      {
         if(!r && !l){delete this;return true;}
         else
         {
            AVL **ar = new AVL*[h];
            AVL *n1 = this,*n2;
            int idx = 0;
            bool f = l;
            n2 = f ? l : r;
            while(f ? n2->r : n2->l)
               ar[idx++] = n1,   n1 = n2 , n2 = f ? n2->r : n2->l;
            val = n2->val;
            if(f ? n2->l : n2->r)
               ar[idx++] = n1,   n1 = n2 , n2 = (f?n2->l:n2->r),
               n1->val=n2->val;
            if(f)
               if(n1->r && n1!=this)n1->r = 0;
               else n1->l = 0;
            else
               if(n1->l && n1!=this)n1->l = 0;
               else n1->r = 0;
            delete n2;
            cnt--;
            n1 -> balance();
            while(idx > 0)ar[--idx]->balance();
            delete [] ar;
            if(cnt > 0)this->erase(nval,cnt);
         }
      }
      return false;
   }
   struct Iterator{
      AVL *it;
      Iterator(AVL *_it){it = _it;}
      bool operator++(){
         AVL *ne = it;
         if(ne->r)
         {
            ne = ne->r;
            while(ne->l)ne = ne->l;
         }
         else
         {
            while(ne->p && ne->p->r == ne)ne = ne->p;
            if(ne->p)ne = ne->p;
            else return false;
         }
         it = ne;
         return true;
      }
      bool operator--(){
         AVL *ne = it;
         if(ne->l)
         {
            ne = ne->l;
            while(ne->r)ne = ne->r;
         }
         else
         {
            while(ne->p && ne->p->l == ne)ne = ne->p;
            if(ne->p)ne = ne->p;
            else return false;
         }
         it = ne;
         return true;
      }
      INT operator*()
      {
         return it->val;
      }
   };
   Iterator begin(){
      AVL *ret = this;
      while(ret->l)ret = ret->l;
      return Iterator(ret);
   }
   Iterator end(){
      AVL *ret = this;
      while(ret->r)ret = ret->r;
      return Iterator(ret);
   }
};


int main() { 
   AVL<int> A;
   int N, c, ind, x;
   scanf("%d",&N);
   while(N-- > 0) {
      scanf("%d",&c);   
      if(c == 1) {
         scanf("%d",&x);
         A.insert(-x);
      } else {
         ind = (A.sz - 1) / 3;
         if(ind - 1 >= 0) 
            printf("%d\n",-A[ind]);
         else 
            printf("No reviews yet\n");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
