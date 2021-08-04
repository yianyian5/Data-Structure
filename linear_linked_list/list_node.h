/***********
LINEAR_LINKED_LIST_NODE template
yianyian5
2021.08.02
***********/

#ifndef LINEAR_LINKED_LIST_NODE
#define LINEAR_LINKED_LIST_NODE


template<class T>
class list_node {

public:
	T data; //T型数据
	list_node<T> * pred;     //前驱指针
	list_node<T> * succ;     //后驱指针

	list_node() {
		pred = NULL;
		succ = NULL;
	}      //用于构造头指针和尾指针
	list_node(T e, list_node<T>* p = NULL, list_node<T>* s = NULL);      //默认构造器
	list_node<T>* insertaspred(T const& e);  //将e紧靠当前节点之前插入于当前节点所属列表
	list_node<T>* insertassucc(T const& e);  //将e紧随当前节点之后插入于当前节点所属列表
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