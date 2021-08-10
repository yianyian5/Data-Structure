#pragma once

#include"list_node.h"

#ifndef LINEAR_LINKED_LIST
#define LINEAR_LINKED_LIST

template<class T>
class list {
private:
	int _size;
	list_node<T>* header;
	list_node<T>* trailer;
public:
	//构造函数与析构函数
	list();   //空列表的创建
	list(list<T> const& L);  //从现有列表L整体复制
	list(list<T> const& L, int r, int n);  //从现有列表L的秩为r的项开始复制后面的n项
	~list();          //释放包括头尾节点在内的所有节点
	//常用操作
	list_node<T>* get_trailer() { return trailer; }
	list_node<T>* get_header() { return header; }
	list_node<T>* get_last() { return trailer->pred; }
	list_node<T>* get_first() { return header->succ; }
	T& operator[](int r) const;   //重载[]运算符，返回T型数据
	int size() const;  //返回当前列表元素个数
	list_node<T>* find_by_value(T const& e) const;  //按值查找元素
	list_node<T>* find_by_rank(int k) const;      //按秩返回元素,返回整个节点指针
	T remove(int r);     //删除秩为r的元素
	T remove(list_node<T>* p);    //删除特定位置的元素
	list_node<T>* insert_as_before(list_node<T>* p, T const& e);  // 插到指定结点的前面
	list_node<T>* insert_as_after(list_node<T>* p, T const& e);
	list_node<T>* insert_by_rank(int k, T const& e);  //按秩插入
	list_node<T>* insertAsFirst ( T const& e );    //当作首节点插入
	list_node<T>* insertAsLast ( T const& e ); //当作尾节点插入
	void traverse(void(*visit) (T &));   //遍历器
};

template<class T>
list<T>::list() {
	header = new list_node<T>;
	trailer = new list_node<T>;    //创建头尾节点header和trailer
	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;             //规模为0
}

template<class T>
list<T>::list(list<T> const& L) {
	header = new list_node<T>;
	trailer = new list_node<T>;
	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;
	list_node<T>* p = L.header;
	for (int i = 0; i < L._size; i++)
	{
		p = p->succ;
		trailer->insertaspred(p->data);
		_size++;
	}
}

template<class T>
list<T>::list(list<T> const& L, int r, int n) {
	header = new list_node<T>;
	trailer = new list_node<T>;
	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;
	list_node<T>* p = L.header;
	for (int i = 0; i < r; i++)  p = p->succ;
	for (int i = 0; i < n; i++)
	{
		p = p->succ;
		trailer->insertaspred(p->data);
		_size++;
	}
}

template<class T>
list<T>::~list() {
	while (_size)  remove(header->succ);
	delete header;
	delete trailer;
}

template<class T>
int list<T>::size() const {
	return _size;
}

template<class T>
T& list<T>::operator[](int r) const {
	list_node<T> * p = header;
	for (int i = 0; i <= r; i++)  p = p->succ;
	return p->data;
}

template<class T>
list_node<T>* list<T>::find_by_value(T const& e) const {
	list_node<T>* p = trailer;
	int n = _size;
	while (0 < n--)  if (p->pred->data == e)  return p->pred; else p = p->pred;
	return NULL;           //查不到时返回null
}

template<class T>
list_node<T>* list<T>::find_by_rank(int k) const {
	list_node<T> * p = header;
	for (int i = 0; i <= k; i++)  p = p->succ;
	return p;
}

template<class T>
T list<T>::remove(int r) {
	;
	list_node<T> * p = header;
	for (int i = 0; i <= r; i++)  p = p->succ;
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template<class T>
T list<T>::remove(list_node<T>* p) {
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template<class T>
list_node<T>* list<T>::insert_as_before(list_node<T>* p, T const& e) {
	_size++;
	return p->insertaspred(e);
}

template<class T>
list_node<T>* list<T>::insert_as_after(list_node<T>* p, T const& e) {
	_size++;
	return p->insertassucc(e);
}

template<class T>
list_node<T>* list<T>::insert_by_rank(int k, T const& e) {
	list_node<T> * p = header;
	for (int i = 0; i <= k; i++)  p = p->succ;
	_size++;
	return p->insertaspred(e);
}

template <class T> 
list_node<T>* list<T>::insertAsFirst ( T const& e )
{  _size++; return header->insertassucc ( e );  } //e当作首节点插入

template <class T> 
list_node<T>* list<T>::insertAsLast ( T const& e )
{  _size++; return trailer->insertaspred ( e );  } //e当作末节点插入

template<class T>
void list<T>::traverse(void(*visit) (T &)) {
	list_node<T>* p = header;
	for (int i = 0; i < _size; i++)
	{
		p = p->succ;
		visit(p->data);
	}
}

#endif