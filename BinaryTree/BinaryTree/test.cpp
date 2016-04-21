#define _CRT_SECURE_NO_WARNINGS

#include "BinaryTree.hpp"
void TestBinaryTree()
{
	int array1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int array2[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	int size = sizeof(array1) / sizeof(array1[0]);
	BinaryTree<int> tree(array1, '#', size);
	tree.PreOrder();//�ȸ�����
	tree.InOrder();//�������
	tree.PostOrder();//�������
	tree.LevelOrder();//�������
	cout << "size:"<<tree.size() << endl;//��������Ԫ�ظ���
	cout << "depth��"<<tree.Depth() << endl;//���������
	cout << "Ҷ�ӽڵ������"<<tree.LeafSize() << endl;//������Ҷ�ӽڵ����

	BinaryTree<int> tree1(tree);//����
	tree.PreOrder();
	BinaryTree<int> tree3;
	tree3 = tree;//��ֵ
	tree3.PreOrder();
}

int main()
{
	TestBinaryTree();
	getchar();
	return 0;
}