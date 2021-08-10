#include"list.h"

# ifndef STACK_OF_LIST
#define STACK_OF_LIST

template<class T>
class stack_l:public list<T>{
    public:
        stack_l():list<T>(){
            
        }
        stack_l<T>* push(T const& e){
            this->insertAsLast(e);
            return this;
        }
        T pop(){
            return this->remove(this->get_last());
        }
        T& _top(){
            return this->find_by_rank(this->size() - 1)->data;
        }

};
#endif


