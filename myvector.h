#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#define DEFAULT_CAPACITY 3 //默认的初始容量，最小容量（实际应用中可讴置为更大）

template <typename T>
class Vector
{
protected:
	int _size; //vector当前规模
	int _capacity;//总容量
	T* _elem;//数据
	void copyFrom(T const* A, int left, int right);//复制数组区间A[left,right)
	void expand(); //空间不足时扩容
	void shrink(); //装填因子(实际元素数量/空间大小)过小时压缩
	

public:
	Vector(int c = DEFAULT_CAPACITY)
	{//构造函数
		_capacity = c;
		_elem = new T[_capacity];
		for (_size = 0; _size < c; _size++)
			_elem[_size] = 0;
	}
	~Vector(){ delete[] _elem; }
	void unsort(int lo, int hi); //对[lo, hi)置乱
	void unsort();//全部置乱
	T& operator[](int r)const;
	Vector<T>& operator= (Vector<T> const&);//重载=
	int insert(int pos, T const& e); //插入元素
	int insert(T const& e);////默认作为末元素插入
	void traverse();//遍历
	int find(T const& e);
	int find(T const& e, int left, int right);//区间查找元素e
	int remove(int left, int right);//删除区间[left.right)元素
	int remove(int pos);
	int deduplicate();//删除重复元素
};


template <typename T>
void Vector<T>::copyFrom(T const* A, int left, int right)//复制数组区间A[left,right)
{
	_capacity = 2 * (right - left);
	_elem = new T[_capacity];
	_size = 0;
	while (left<right)
	{
		_elem[_size++] = A[left++];
	}
}
template <typename T>
void Vector<T>::expand()
{
	//创建新数组，二倍空间，复制数据，释放原数组
	if (_size < _capacity) return; //尚未满员时，不必扩容
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY; //不低于最小容量
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];//<<=左位移运算符，容量扩大2倍
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}
template <typename T>
void Vector<T>::shrink()
{
	//创建新数组，缩小二倍空间，复制数据，释放原数组
	if ((_capacity / 2)<DEFAULT_CAPACITY) return; //不致收缩到最小容量以下
	if (_size * 4 >> _capacity)  return; //以25%为界
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}
template <typename T>
void Vector<T>::unsort(int lo, int hi) //对[lo, hi)置乱
{
	T* V = _elem + lo;
	for (int i = hi - lo; i>0; i--)
		swap(V[i - 1], V[rand() % i]);
}
template <typename T>
void Vector<T>::unsort() //对[lo, hi)置乱
{
	unsort(0, _size);
}
template <typename T>
T& Vector<T>::operator[](int r) const
{//重载运算符[]
	return _elem[r];
}
template<typename T>
int Vector<T>::insert(int pos, T const& e) //插入元素
{
	expand();//若有必要，扩容
	for (int i = _size; i > pos; i--)
		_elem[i] = _elem[i - 1];
	_elem[pos] = e;
	_size++;
	return pos;
}

template<typename T>
void Vector<T>::traverse()
{
	for (int i = 0; i < _size; i++)
		cout << _elem[i]<<" ";
}
template<typename T>
int Vector<T>::find(T const& e)
{
	for (int i = 0; i < _size; i++)
	{
		if (e == _elem[i])
			return i;
	}
	return -1;
}
template<typename T>
int Vector<T>::find(T const& e, int left, int right)
{
	for (int i = left; i < right; i++)
	{
		if (_elem[i] == e)
			return i;
	}
	return -1;
}
template<typename T>
int Vector<T>::insert(T const& e)
{
	return insert(_size, e);
}
template<typename T>
int Vector<T>::remove(int left, int right)
{
	while (right < _size)
	{
		_elem[left++] = _elem[right++];
	}
	_size = _size - (right - left);
	return right-left;//返回删除元素个数
}
template<typename T>
int Vector<T>::remove(int pos)
{
	remove(pos, pos + 1);
	return 1;
}
template<typename T>
int Vector<T>::deduplicate()
{
	int count = 0,i=0,pos=0;
	while ( i < _size)
	{
		pos = find(_elem[i],i+1,_size);
		cout << "pos=" << pos << endl;
		while (pos != -1)
		{//有重复元素
			remove(pos); 
			count++;
			pos = find(_elem[i], i + 1, _size);
		}
		i++;
	}
	return count;//删除元素个数
}



#endif
