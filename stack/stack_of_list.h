/*
 * @Author: yianyian5
 * @Date: 2021-08-09 20:06:34
 * @LastEditTime: 2021-08-10 21:55:58
 * @LastEditors: yianyian5
 * @Description: 
 * @FilePath: \Data-Structure\stack\stack_of_list.h
 * Talk is cheap,show me the code.
 */
#include"list.h"

# ifndef STACK_OF_LIST
#define STACK_OF_LIST

template<class T>
class stack_l:public list<T>{
    public:
        stack_l() :list<T>() {}
        bool empty(){return (this->size() == 0) }
        stack_l<T>* push(T const& e){
            this->insertAsLast(e);
            return this;
        }
        T pop(){
            return this->remove(this->get_last());
        }
        T& _top(){
            return this->find_by_rank(this->size() - 1)->node_value();
        }

};
#endif


