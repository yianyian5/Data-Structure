#include<iostream>
#include"vector.h"
using namespace std;

void increase(int& a){
    a*=2;
}

int main(){
    int a[6] ={ 1,2,3,4,5,6} ;
    vector<int> arr1(a,2,5);
    vector<int> arr2(a,6);
    int k = 0;
    while (k<6){
        cout << arr1.show(k)<<"  "<<arr2.show(k)<<endl;
        k++;
    }

    arr1=arr2;
    arr2.traverse(increase);
    k = 0;
    while (k<6){
        cout << arr1.show(k)<<"  "<<arr2.show(k)<<endl;
        k++;
    }
    cout<<arr1.disordered()<<"   "<<arr2.disordered()<<endl;
    cout<<arr1.find(2,1,5)<<endl;
    cout<<arr1.find(8)<<endl;

    vector<int> arr3(a,0,1);
    cout<<arr3.size_show()<<"  "<<arr3.capacity_show()<<endl;
    arr3.insert(1,6);
    cout<<arr3.size_show()<<"  "<<arr3.capacity_show()<<endl;
    arr3.insert(2,8);
    cout<<arr3.size_show()<<"  "<<arr3.capacity_show()<<endl;

    cout<<arr1.remove(2,5)<<endl;    
     k = 0;
    while (k<6){
        cout << arr1.show(k)<<"  "<<arr2.show(k)<<endl;
        k++;
    }
    cout<<arr1.capacity_show()<<"   "<<arr1.size_show()<<endl;
    return 0;
}