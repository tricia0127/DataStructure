#pragma once

#include<iostream>
#include<assert.h>
#include<queue>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T& d)
	:_data(d)
	,_left(NULL)
	,_right(NULL)
	{
	}
	T _data;//����
	BinaryTreeNode<T>* _left;//����
	BinaryTreeNode<T>* _right;//�Һ���
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree(const T *a, const T& invalid, size_t size)//����������  invalid��ʾû��ֵ�����ӻ��Һ���Ϊ�գ�
		:_root(NULL)
	{
		size_t index = 0;
		_root = _CreatBinaryTree(a, invalid, size, index);//ʵ�ֵݹ����
	}
	BinaryTree()//Ĭ�Ϲ��캯��
		:_root(NULL)
	{}
	BinaryTree(const BinaryTree<T>& t)
		:_root(NULL)
	{
		_root=_CopTree(t._root);
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)
	{
		if (this != &t)
		{
			Node* root = _CopTree(t._root);
			Destry(_root);
			_root = root;
		}
		return *this;
	}
	~BinaryTree()
	{
		Destry(_root);
	}
public:
	Node* _CopTree(Node* root)
	{
		Node* head=NULL;

		if (root)
		{
			head = new Node(root->_data);
			head->_left = _CopTree(root->_left);
			head->_right = _CopTree(root->_right);
		}
		return head;
	}
	void PreOrder()//�������
	{
		_PreOrder(_root);
		cout << endl;
	}
	void InOrder()//�������
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()//�������
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()//�������
	{
		queue<Node*> q1;//��Զ���浱ǰ��ӡ��һ�����нڵ�
		queue<Node*> q2;//��Զ���浱ǰһ��ڵ���ӽڵ�
		q1.push(_root); //���ڵ�ѹ�����

		while (q1.size())//����ǰһ��ڵ�û�д�ӡ��
		{
			cout << (q1.front())->_data << " ";//q1��ͷ�Ľڵ��ǽ�Ҫ��ӡ�Ľڵ�

			if (q1.front()->_left != NULL)//���ýڵ�����Ӳ�Ϊ��
				q2.push(q1.front()->_left);//���ý���������q2
			if (q1.front()->_right != NULL)//���ýڵ���Һ��Ӳ�Ϊ��
				q2.push(q1.front()->_right);//���ý���������q2

			q1.pop();//����ӡ����Ľڵ���Ӻ󣬶�ͷ��Ԫ��Ϊ�ò���һ��δ��ӡ�Ľڵ�
			if (q1.size() == 0)//���ò�ڵ�ȫ����ӡ��
			{
				swap(q1, q2);//����q1,q2,����һ��Ľڵ㱣����Ҫ��ӡ�Ķ�����
				continue;//������ӡ
			}
		}
		cout << endl;
	}
	size_t size()//������Ԫ�ظ���
	{
		return _Size(_root);
	}
	size_t Depth()//���������
	{
		return _Depth(_root);
	}
	size_t LeafSize()//Ҷ�ӽڵ����
	{
		return _LeafSize(_root);
	}
protected:
	void Destry(Node* root)
	{
		Node* del;
		Node* cur = root;
		if (cur)
		{
			del = cur;
			Destry(cur->_left);
			Destry(cur->_right);
			delete del;
		}
	
	}

	BinaryTreeNode<T>* _CreatBinaryTree(const T* a, const T& invalid, size_t size,size_t &index)
	{
		assert(a);
		Node* node = NULL;
		if (index < size && a[index] != invalid)//�����±겻Խ�磬����ֵ
		{
			node= new Node(a[index]);//����a����ǰ������Ķ��������ȴ������ڵ�
			node->_left = _CreatBinaryTree(a, invalid, size, ++index);//����������
			node->_right = _CreatBinaryTree(a, invalid, size, ++index);//����������
			return node;
		}
		return node;
	}
	void _PreOrder(Node* root)
	{
		if (root == NULL)
			return;
		else
		{
			cout << root->_data << " ";
			_PreOrder(root->_left);
		    _PreOrder(root->_right);
		}
	}
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		else
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}
	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;
		else
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout << root->_data << " ";
		}
	}
	
	size_t _Size(Node* root)
	{
		int size = 0;
		if (root)//�ڵ㲻Ϊ��ʱ��size++
		{
			size++;
			size+=_Size(root->_left);
			size+=_Size(root->_right);
		}
		return size;
	}

	//���
	//˼·��Ĭ��ÿһ�����Ϊ1���ݹ鵽���һ������Ϸ��أ�ÿ����һ�����+1��
	size_t _Depth(Node* root)
	{
		size_t depth=1;//������ȣ�Ĭ�����ڵ㲻Ϊ�������Ϊ1
		if (root)//��Ϊ��
		{
			size_t trdepth = _Depth(root->_left);//�ݹ���������������
			if (trdepth + 1 > depth)//����������ȴ��ڵ�ǰ���
				depth = trdepth + 1;//�����������
			trdepth = _Depth(root->_right);//�ݹ�������������
			if (trdepth + 1 > depth)
				depth = trdepth + 1;//�����������
		}
		else
			depth = 0;//��Ϊ�ڵ��ǿսڵ㣬���Ϊ0
		return depth;
	}
	size_t _LeafSize(Node* root)//Ҷ�ӽڵ����
	{
		size_t size = 0;
		if (root == NULL)//Ϊ�շ���
			return size;
		if (root->_left == NULL && root->_right == NULL)//���ڵ�ΪҶ�ӽڵ㣨û�к��ӣ�
			return ++size;//Ҷ�ӽڵ����+1
		else
		{
			size+=_LeafSize(root->_left);//�ݹ�Ѱ����������Ҷ�ӽڵ�
			size+=_LeafSize(root->_right);//�ݹ�Ѱ����������Ҷ�ӽڵ�
		}
	}
protected:
	BinaryTreeNode<T>* _root;
};