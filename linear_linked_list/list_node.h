/*
 * @Author: yianyian5
 * @Date: 2021-08-02
 * @LastEditTime: 2021-08-05 09:08:53
 * @LastEditors: yianyian5
 * @FilePath: \Data-Structure\linear_linked_list\list_node.h
 * Talk is cheap,show me the code.
 */


#ifndef LINEAR_LINKED_LIST_NODE
#define LINEAR_LINKED_LIST_NODE

template<class T>
class list;                        //被声明为友元类之前要有简单地声明

template<class T>
class list_node {

private:
	T data; //T型数据
	list_node<T> * pred;     //前驱指针
	list_node<T> * succ;     //后驱指针
public:
	friend class list<T>;      //将list类声明为友元类，以便于直接访问节点保存的数据和指针
	list_node() {
		pred = NULL;
		succ = NULL;
	}      //用于构造头指针和尾指针
	list_node(T e, list_node<T>* p = NULL, list_node<T>* s = NULL);      //默认构造器
	list_node<T>* insertaspred(T const& e);  //将e紧靠当前节点之前插入于当前节点所属列表
	list_node<T>* insertassucc(T const& e);  //将e紧随当前节点之后插入于当前节点所属列表
	T& node_value() {
		return data;
	}
};

template<class T>
list_node<T>::list_node(T e, list_node<T>* p, list_node<T>* s) {
	data = e;
	pred = p;
	succ = s;
}

template<class T>
list_node<T>* list_node<T>::insertaspred(T const& e) {
	list_node<T>* x = new list_node<T>(e, pred, this);   //让新节点前继指向当前节点的前继，后驱指向当前节点
	pred->succ = x;
	pred = x;
	return x;           //返回新节点的位置
}

template<class T>
list_node<T>* list_node<T>::insertassucc(T const& e) {
	list_node<T>* x = new list_node<T>(e, this, succ);  //让新节点前继指向当前节点，后驱指向当前节点的后驱
	succ->pred = x;
	succ = x;
	return x;     //返回新节点的位置 
}

#endif