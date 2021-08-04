/*********
LINEAR_LIST_VECTOR  template
yianyian5 
2021.08.01
**********/

#define DEFAULT_CAPACITY  3 
#ifndef LINEAR_LIST_VECTOR
#define LINEAR_LIST_VECTOR

template<class  T>
class vector{
    private:
        T* _elem;
        int _capacity;
        int _size;

    public:
        vector(int n =  DEFAULT_CAPACITY );  //默认长度为3的空向量
        vector(T* const& A,int a ,int b);  //部分向量复制，从下标a到b-1
        vector(T* const& A,int n);  //向量整体复制
        ~vector();
        T show(int k);
        int size_show();
        int capacity_show();
        void expend();   //将原有数组扩容（每次插入时检查，在即将溢出时使用）
        int find(T const& e,int a ,int b ) const ;  //从后往前在[a,b)里查找第一个对应元素
        int find(T const& e) const ;     //重载查找
        vector<T>& insert(int r, T const& e); //在秩为r的位置插入元素e,便于连续插值
        int remove(int a,int b);    //删除区间[a,b)里的元素,返回删除元素总个数
        int remove(int r);        //删除秩为r的元素
        int deduplicate();    //删除重复元素
        void traverse( void (*visit)(T&));  //遍历器，允许传入一个void型并且接受一个T&参数的函数对数组中每一个元素进行操作
        int disordered() const;     //判断向量是否有序

        T& operator[](int r) const;  //const隐式限定this指针为const T*指针，使得成员函数只读取而无法修改调用的对象
        vector<T>& operator=(vector<T> const&);   //返回vector<t>类型的引用便于链式赋值
};

template<class T>
vector<T>:: vector(int n ){
    _elem = new T[n];
    _capacity = n;
    _size = 0;
}

template<class T>
vector<T>::vector(T* const& A,int a ,int b){
    _elem = new T[2*(b-a)];
    _capacity=2*(b-a);
    _size=0;
    while (a<b)
        _elem[_size++] = A[a++];  //如果使用后缀形式，则会在表达式计算之后完成自增或自减。
}                                 //此时应确保赋值操作 “ = ” 针对T类型进行过重载

template<class T>
vector<T>::vector(T* const& A,int n){
    _elem = new T[2*n];
    _capacity=2*n;
    _size=0;
    while (_size<n)
        _elem[_size++] = A[_size];    //此时应确保赋值操作 “ = ” 针对T类型进行过重载
}

template<class T>
vector<T>::~vector(){
    delete []_elem;
}

template<class T>
T vector<T>::show(int k){
    return _elem[k] ; 
}

template<class T>
int vector<T>::size_show(){
    return _size;
}

template<class T>
int vector<T>::capacity_show(){
    return _capacity;
}

template<class T>
void vector<T>::expend(){      
    if(_size<_capacity) return;  //未满不进行扩容
    T* oldelem = _elem;
    _elem = new T[2*_capacity];   //容量加倍
    _capacity*=2;     //也可以使用位移运算符_capacity<<=1
    for ( int i = 0; i < _size; i++)
        _elem[i] = oldelem[i];       //此时应确保赋值操作 “ = ” 针对T类型进行过重载
    delete [] oldelem;   //释放原空间
}

template<class T> 
int vector<T>::find(T const& e,int a,int b) const{
    while(a<b--)
        if(_elem[b]==e) return b;
    return -1;
}

template<class T> 
int vector<T>::find(T const& e) const{
    int a = 0;
    int b = _size;
    while(a<b--)
        if(_elem[b]==e) return b;
    return -1;
}

template<class T>
vector<T>& vector<T>::insert(int r , T const& e){
    expend();
    for (int i = _size; i > r; i)
        _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++;
    return *this;
}

template<class T>
int vector<T>::remove(int a,int b){
    if(a>=b) return 0;
    if(b>=_size){
        _size = a;
        return _size - a;
        }
    while(b<_size) _elem[a++] = _elem[b++];
    _size = a;
    return b-a;
}

template<class T>
int vector<T>::remove(int r){
    remove(r,r+1);
    return 1;
}

template<class T>
int vector<T>::deduplicate(){
    int oldsize = _size;
    int i = 1;
    while(i<_size) (find(_elem[i],0,i) < 0)? i++ : remove[i];
    return oldsize - _size;      //返回被删除的元素总个数
}

template<class T>                   //函数指针机制的遍历
void vector<T>::traverse(void (*visit)(T&)){
    for (int i = 0; i < _size; i++)   visit(_elem[i]);
}

template<class T>
int vector<T>::disordered() const {
    int n = 0;
    for (int i = 1; i < _size; i++)
        if(_elem[i - 1]>_elem[i])  n++;        //假定比较大小操作可用或已重载
    return n;           //当且仅当 n = 0 时向量有序
}

template<class T> 
T& vector<T>::operator[](int r) const{
    return _elem[r];
}

template<class T>
vector<T>& vector<T>::operator=(vector<T> const& v){
    if(_elem) delete[] _elem;  //如果动态分配了_elem就进行释放
    _elem = new T[2*v._size];
    _capacity=2*v._size;
    _size=0;
    while (_size<v._size)
        _elem[_size++] = v._elem[_size];
    return *this;
}

#endif  