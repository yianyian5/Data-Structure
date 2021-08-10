/*
 * @Author: yianyian5
 * @Date: 2021-08-09 19:44:45
 * @LastEditTime: 2021-08-09 22:16:13
 * @LastEditors: yianyian5
 * @Description: 
 * @FilePath: \Data-Structure\stack\stack_test.cpp
 * Talk is cheap,show me the code.
 */
#include<iostream>
#include"stack_of_vector.h"
#include"stack_of_list.h"
using namespace std;

int main(){
    stack_v<int> stack1(10);
    stack1.push(1)->push(2)->push(3)->push(4)->push(5);
    cout<<stack1.size()<<stack1.empty()<<endl;
    cout<<stack1.pop()<<stack1.pop()<<endl;
    cout<<stack1.size()<<stack1.empty()<<endl;


    stack_l<int> stack2;
    stack2.push(1)->push(2)->push(3)->push(4)->push(5);
    cout<<stack2.size()<<endl;
    cout<<stack2.pop()<<stack2.pop()<<endl;
    cout<<stack2.size()<<endl;
    return 0;
}