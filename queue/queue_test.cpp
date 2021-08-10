#include<iostream>
#include"queue.h"

using namespace std;
int main() {
	queue<int> queue1;
	cout << bool(queue1.empty()) << endl;
	queue1.enqueue(1)->enqueue(2)->enqueue(3)->enqueue(4)->enqueue(5);
	cout << queue1.size() << endl;
	cout << queue1.front() << endl;
	cout << queue1.dequeue() << endl;
	cout << queue1.front() << endl;
	cout << queue1.size() << endl;
	return 0;
}