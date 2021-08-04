#include<iostream>
#include"list.h"
using namespace std;

int main(){
    list<int> list1;
	list1.insert_by_rank(0, 45);
	list1.insert_by_rank(1, 88);
	list1.insert_by_rank(2, 90);
	list1.insert_by_rank(3, 66);
	for (int i = 0; i < 4; i++)   cout << list1[i] << "  ";
	cout << endl;

	list<int> list2(list1);
	for (int i = 0; i < 4; i++)   cout << list2[i] << "  ";
	cout << endl;

	list<int> list3(list1, 1, 2);
	cout << list3.size() << endl;

    list1.find_by_value(88)->data = 44;
	for (int i = 0; i < 4; i++)   cout << list1[i] << "  ";
	cout << endl;
	list2.find_by_rank(2)->data = 7 ;
	for (int i = 0; i < 4; i++)   cout << list2[i] << "  ";
	cout << endl;
	list3.remove(1);
	cout << list3.size() << endl;
	return 0;
}