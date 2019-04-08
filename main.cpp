#include<iostream>
#include"myvector.h"
#include"mylist.h"
#include"mybintree.h"
using namespace std;

int main()
{
	/*
	//===vector测试===
	Vector<int> A(20);
	for (int i = 0; i < 20; i++)
		A[i] = rand()%10;

	A.traverse();
	cout << endl;
	//cout<<A.find(4);
	//A.remove(2);
	//A.unsort();
	//cout<<A.find(4,2,9);
	cout << A.deduplicate() << endl;;
	A.traverse();
	*/
	/*
	//===LIST测试===

	List<int> A;//注意默认构造函数的调用方法
	A.insertAsLast(3);
	A.insertAsLast(13);
	A.insertAsFirst(32);
	A.insertA(20,3);
	A.traverse();
	cout << A.find(32) << endl;
	A.removeA(1);
	cout << endl; 
	A.traverse();
	*/

	BinTree<int> A;
	cout << "\n先序遍历"<<endl;
	A.preTraverse();
	cout << "\n中序遍历" << endl;
	A.inorderTraverse();
	cout << "\n后序遍历" << endl;
	A.postorderTraverse();
	cout << "节点个数=" << A.countNode() << endl;
	cout << "树的深度=" << A.depth() << endl;

	//TODO: 迭代实现遍历 stack



	return 0;
}