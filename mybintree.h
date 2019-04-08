#ifndef __MYBINTREE_H__
#define __MYBINTREE_H__

template<typename T>
struct BinNode
{
	T data;
	BinNode<T>* leftc;//����
	BinNode<T>* rightc;//�Һ���
	BinNode(const T& d, BinNode<T>* left = NULL, BinNode<T>* right = NULL)
	{//���캯��
		data = d; leftc = left; rightc = right;
	}
};

template<typename T>
class BinTree
{
protected:
	int _size;//�ڵ���
	BinNode<T>* _root;//���ڵ�
	void create(BinNode<T>* &_root);//���������,���캯���ڵ���
	void preOrder(BinNode<T>* &_root);//�������������preTraverse����
	void inOrder(BinNode<T>* &_root);
	void postOrder(BinNode<T>* &_root);
	int _depth(BinNode<T>* &_root);//���������
	int _countNode(BinNode<T>* &_root);//��ڵ����

public:
	BinTree();
	//~BinTree(){ if (_size > 0) remove(_root); }
	void preTraverse();//�������
	void inorderTraverse();//�������
	void postorderTraverse();//�������
	//TODO:��α���
	int depth(){ return _depth(_root); }//���������,ֻ��root���Ϊ0
	int countNode(){return _countNode(_root); }//��ڵ����
};

template <typename T>
void BinTree<T>::create(BinNode<T>* &_root)
{//ָ�������*&
	char ch;//TODO:ʹ��T ch ��������ܻ��ȡ�س���
	cin >> ch;
	if (ch == '#')
		_root = NULL;
	else
	{
		_size++;
		_root = new BinNode<T>(ch);
		cout<<"\n����"<<ch<<"�����ӽ��: ";
		create(_root->leftc);
		cout << "\n����"<<ch<<"�����ӽ��: ";
		create(_root->rightc);
	}

}

template<typename T>
BinTree<T>::BinTree()
{
	cout << "����ڵ�,#��ʾ��" << endl;
	_size = 0; _root = NULL; 
	create(_root);
}

template <typename T>
void BinTree<T>::preOrder(BinNode<T>* &_root)
{
	if (_root)
	{
		cout <<char( _root->data)<<"  ";
		preOrder(_root->leftc);
		preOrder(_root->rightc);
	}

}
template <typename T>
void BinTree<T>::inOrder(BinNode<T>* &_root)
{
	if (_root)
	{
		inOrder(_root->leftc);
		cout << char(_root->data) << "  ";
		inOrder(_root->rightc);
	}
}
template <typename T>
void BinTree<T>::postOrder(BinNode<T>* &_root)
{
	if (_root)
	{
		postOrder(_root->leftc);
		postOrder(_root->rightc);
		cout << char(_root->data) << "  ";
	}
}
template <typename T>
void BinTree<T>::preTraverse()
{
	preOrder(_root);
}
template <typename T>
void BinTree<T>::inorderTraverse()
{
	inOrder(_root);
}
template <typename T>
void BinTree<T>::postorderTraverse()
{
	postOrder(_root);
}
template <typename T>
int BinTree<T>::_depth(BinNode<T>* &_root)
{
	int h1, h2;
	if (_root == NULL)
		return -1;
	h1=_depth(_root->leftc);
	h2=_depth(_root-> rightc);
	if (h1 > h2) return h1 + 1;
	else return h2 + 1;

}
template <typename T>
int BinTree<T>::_countNode(BinNode<T>* &_root)
{
	int num1, num2;
	if (_root == NULL)
		return 0;
	num1 = _countNode(_root->leftc);
	num2 = _countNode(_root->rightc);
	return  num1+num2+1;
}

#endif