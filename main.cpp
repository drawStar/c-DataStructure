#include<iostream>
#include"myvector.h"
#include"mylist.h"
#include"mybintree.h"
using namespace std;

int main()
{
	/*
	//===vector����===
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
	//===LIST����===

	List<int> A;//ע��Ĭ�Ϲ��캯���ĵ��÷���
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
	cout << "\n�������"<<endl;
	A.preTraverse();
	cout << "\n�������" << endl;
	A.inorderTraverse();
	cout << "\n�������" << endl;
	A.postorderTraverse();
	cout << "�ڵ����=" << A.countNode() << endl;
	cout << "�������=" << A.depth() << endl;

	//TODO: ����ʵ�ֱ��� stack



	return 0;
}