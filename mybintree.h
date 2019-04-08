#ifndef __MYBINTREE_H__
#define __MYBINTREE_H__

template<typename T>
struct BinNode
{
	T data;
	BinNode<T>* leftc;//左孩子
	BinNode<T>* rightc;//右孩子
	BinNode(const T& d, BinNode<T>* left = NULL, BinNode<T>* right = NULL)
	{//构造函数
		data = d; leftc = left; rightc = right;
	}
};

template<typename T>
class BinTree
{
protected:
	int _size;//节点数
	BinNode<T>* _root;//根节点
	void create(BinNode<T>* &_root);//构造二叉树,构造函数内调用
	void preOrder(BinNode<T>* &_root);//先序遍历，用于preTraverse函数
	void inOrder(BinNode<T>* &_root);
	void postOrder(BinNode<T>* &_root);
	int _depth(BinNode<T>* &_root);//求树的深度
	int _countNode(BinNode<T>* &_root);//求节点个数

public:
	BinTree();
	//~BinTree(){ if (_size > 0) remove(_root); }
	void preTraverse();//先序遍历
	void inorderTraverse();//中序遍历
	void postorderTraverse();//后序遍历
	//TODO:层次遍历
	int depth(){ return _depth(_root); }//求树的深度,只有root深度为0
	int countNode(){return _countNode(_root); }//求节点个数
};

template <typename T>
void BinTree<T>::create(BinNode<T>* &_root)
{//指针的引用*&
	char ch;//TODO:使用T ch 会出错，可能会读取回车？
	cin >> ch;
	if (ch == '#')
		_root = NULL;
	else
	{
		_size++;
		_root = new BinNode<T>(ch);
		cout<<"\n输入"<<ch<<"的左子结点: ";
		create(_root->leftc);
		cout << "\n输入"<<ch<<"的右子结点: ";
		create(_root->rightc);
	}

}

template<typename T>
BinTree<T>::BinTree()
{
	cout << "输入节点,#表示空" << endl;
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