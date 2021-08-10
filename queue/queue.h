#pragma once
#include"list.h"
#ifndef QUEUE
#define QUEUE

template<class T>
class queue:public list<T> {
	public:
		queue() :list<T>() {}
		bool empty() { return (this->size() == 0); }
		queue<T>* enqueue(T const& e) {
			this->insertAsLast(e);
			return this;
		}
		T dequeue() {
			return this->remove(this->get_first());
		}
		T& front() {
			return this->find_by_rank(0)->node_value();
		}
};


#endif // 
