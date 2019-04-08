#ifndef __MYLIST_H__
#define __MYLIST_H__

// ��һ����Ԫ�ص�λ��Ϊ1

template<typename T>
struct ListNode
{
	T data;
	ListNode<T>* pred;//ǰ���ڵ�
	ListNode<T>* next;//��̽ڵ�
	//TODO:�Ƿ���Ҫһ�����캯��
};

template <typename T>
class List
{
private:
	int _size;
	ListNode<T>* header; //ͷ�ڱ�
	ListNode<T>* trailer; //β�ڱ�

protected:
	void init(); //�б���ʱ�ĳ�ʼ��
	int clear(); //������нڵ�

public:
	List(){ init(); }//���캯��
	int find(T const& e) const; //����Ԫ��e,����λ��
	void traverse();//����
	void insertAsLast(T const& e); //��e����ĩ�ڵ����
	void insertAsFirst(T const& e); //��e����ĩ�ڵ����
	void insertA(T const& e,int pos); //��pos������e
	void removeA(int pos); //��pos��ɾ��
};



template<typename T>
void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->pred = NULL;	header->next = trailer;
	trailer->pred = header; trailer->next = NULL;
	_size = 0;
}
template<typename T>
int List<T>::find(T const& e) const
{
	ListNode<T>* p;
	p = header->next;
	int pos = 1;
	while (p!=trailer)
	{
		if (p->data == e)
			return pos;
		p = p->next;
		pos++;
	}
	pos = -1;
	return pos;
}


template<typename T>
void List<T>::traverse()
{
	ListNode<T>* p;
	p = header->next;
	while (p != trailer)
	{
		cout << p->data<<" ";
		p = p->next;
	}
}

template<typename T>
void List<T>::insertAsLast(T const& e)
{
	ListNode<T>* x = new ListNode<T>;
	x->data = e;
	trailer->pred->next = x;
	x->pred = trailer->pred;
	x->next = trailer;
	trailer->pred = x;
	_size++;
}

template <typename T>
void List<T>::insertAsFirst(T const& e)
{
	ListNode<T>* x = new ListNode<T>;
	x->data = e;
	x->next = header->next;
	header->next->pred = x;
	header->next = x;
	x->pred = header;
	_size++;
}

template<typename T>
void List<T>::insertA(T const& e, int pos)
{//��һ����Ԫ�ص�λ��Ϊ1
	if (pos > _size || pos<=0) return;
	ListNode<T>* x = new ListNode<T>;
	x->data = e;

	ListNode<T>* p;
	p = header;
	for (int i = 1; i < pos && p!=trailer; i++)
		p = p->next;
	x->next = p->next;
	p->next->pred = x;
	p->next = x;
	x->pred = p;
	_size++;
}
template<typename T>
void List<T>::removeA(int pos)
{
	if (pos > _size || pos<=0) return;
	ListNode<T>* p;
	p = header;
	for (int i = 0; i < pos && p != trailer; i++)
		p = p->next;
	p->pred->next = p->next;
	p->next->pred = p->next;
	delete p;
	_size--;
}

#endif