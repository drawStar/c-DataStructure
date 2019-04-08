#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#define DEFAULT_CAPACITY 3 //Ĭ�ϵĳ�ʼ��������С������ʵ��Ӧ���п�ک��Ϊ����

template <typename T>
class Vector
{
protected:
	int _size; //vector��ǰ��ģ
	int _capacity;//������
	T* _elem;//����
	void copyFrom(T const* A, int left, int right);//������������A[left,right)
	void expand(); //�ռ䲻��ʱ����
	void shrink(); //װ������(ʵ��Ԫ������/�ռ��С)��Сʱѹ��
	

public:
	Vector(int c = DEFAULT_CAPACITY)
	{//���캯��
		_capacity = c;
		_elem = new T[_capacity];
		for (_size = 0; _size < c; _size++)
			_elem[_size] = 0;
	}
	~Vector(){ delete[] _elem; }
	void unsort(int lo, int hi); //��[lo, hi)����
	void unsort();//ȫ������
	T& operator[](int r)const;
	Vector<T>& operator= (Vector<T> const&);//����=
	int insert(int pos, T const& e); //����Ԫ��
	int insert(T const& e);////Ĭ����ΪĩԪ�ز���
	void traverse();//����
	int find(T const& e);
	int find(T const& e, int left, int right);//�������Ԫ��e
	int remove(int left, int right);//ɾ������[left.right)Ԫ��
	int remove(int pos);
	int deduplicate();//ɾ���ظ�Ԫ��
};


template <typename T>
void Vector<T>::copyFrom(T const* A, int left, int right)//������������A[left,right)
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
	//���������飬�����ռ䣬�������ݣ��ͷ�ԭ����
	if (_size < _capacity) return; //��δ��Աʱ����������
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY; //��������С����
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];//<<=��λ�����������������2��
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}
template <typename T>
void Vector<T>::shrink()
{
	//���������飬��С�����ռ䣬�������ݣ��ͷ�ԭ����
	if ((_capacity / 2)<DEFAULT_CAPACITY) return; //������������С��������
	if (_size * 4 >> _capacity)  return; //��25%Ϊ��
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}
template <typename T>
void Vector<T>::unsort(int lo, int hi) //��[lo, hi)����
{
	T* V = _elem + lo;
	for (int i = hi - lo; i>0; i--)
		swap(V[i - 1], V[rand() % i]);
}
template <typename T>
void Vector<T>::unsort() //��[lo, hi)����
{
	unsort(0, _size);
}
template <typename T>
T& Vector<T>::operator[](int r) const
{//���������[]
	return _elem[r];
}
template<typename T>
int Vector<T>::insert(int pos, T const& e) //����Ԫ��
{
	expand();//���б�Ҫ������
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
	return right-left;//����ɾ��Ԫ�ظ���
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
		{//���ظ�Ԫ��
			remove(pos); 
			count++;
			pos = find(_elem[i], i + 1, _size);
		}
		i++;
	}
	return count;//ɾ��Ԫ�ظ���
}



#endif
