/*
 * @Author: yianyian5
 * @Date: 2021-08-05 16:10:03
 * @LastEditTime: 2021-08-05 16:10:03
 * @LastEditors: yianyian5
 * @Description: data structure of stack
 * @FilePath: \Data-Structure\stack\stack.h
 * Talk is cheap,show me the code.
 */


#ifndef STACK_OF_VECTOR
#define STACK_OF_VECTOR

template<class T>
class stack_v{
    private:
        int max_size;
        int top;
        T* _elem;
    public:
        stack_v(int n){
            max_size = n;
            top = -1;
            _elem = new T[n];
        }
        ~stack_v(){
            delete []_elem;
        }
        int size(){
            return top + 1;
        }
        bool empty(){
            return top + 1;
        }
        stack_v<T>* push(T const& e);  // 进栈
        T pop();     // 出栈
        T& _top();   //取顶部元素
};


template<class T>
stack_v<T>* stack_v<T>::push(T const& e){
    if(top <(max_size - 1)) _elem[++top] = e;
    return this;
}

template<class T>
T stack_v<T>::pop(){
    return _elem[top--];
}

template<class T>
T& stack_v<T>::_top(){
    return _elem[top];
}

#endif