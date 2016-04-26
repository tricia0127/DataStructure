#pragma once

#include<iostream>
#include<assert.h>
#include<queue>
#include<stack>
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
	//void PreOrder()//�ݹ�ʵ���������
	//{
	//	_PreOrder(_root);
	//	cout << endl;
	//}
	//void InOrder()//�ݹ�ʵ���������
	//{
	//	_InOrder(_root);
	//	cout << endl;
	//}
	//void PostOrder()//�ݹ�ʵ�ֺ������
	//{
	//	_PostOrder(_root);
	//	cout << endl;
	//}
	void PrevOrderNonR()//�ǵݹ�
	{
		stack<Node*> s; //����ջ���Ƚ����������ȳ������ʱ���������ڵ�
		Node* cur = _root;
		if (cur == NULL)
			return;
		s.push(cur);//�����ڵ㲻Ϊ�գ��򽫸��ڵ���ջ
		
		while (!s.empty())//ջΪ�ձ�ʾ�������ѷ�����
		{
			cur = s.top();//����ջ����Ԫ��
			cout << cur->_data << " ";
			s.pop();//ջ��Ԫ�س�ջ
			if (cur->_right)//�����ʹ���Ԫ�ص��ҽڵ�ѹջ������ʵ���ѹջ��
				s.push(cur->_right);
			if (cur->_left)//��ڵ�ѹջ
				s.push(cur->_left);
		}

		cout << endl;
	}
	void InOrderNonR()//�ǵݹ�
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())//���ڵ㲻Ϊ�ջ�ջ��Ϊ��
		{
			while(cur)//���ڵ㲻Ϊ��
			{
				s.push(cur);//���ڵ���ջ
				cur = cur->_left;//���ýڵ�����ڵ㣬����ڵ���ջ
			}
			cur = s.top();
			cout << cur->_data << " ";//��������ڵ㣨����ýڵ���ڵ�Ϊ�ջ��ѷ��ʣ�
			s.pop();
			cur = cur->_right;//�����ҽڵ�
		}

		cout << endl;
	}

	void PostOrderNonR()//�ǵݹ�
	{
		stack<Node*> s;
		Node* cur = _root;
		Node* prev = NULL;//��һ�����ʹ��Ľڵ�

		while (cur || !s.empty())//���ڵ㲻Ϊ�ջ�ջ��Ϊ��
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->_left;
			}//ջ��Ԫ��Ϊ����ڵ㣬��һ������
			Node* top= s.top();//ȡ��ջ��Ԫ��
			if (top->_right == NULL || prev == top->_right)//��ջ��Ԫ�ص��ҽڵ�Ϊ�գ��������ҽڵ��ѷ��ʹ�������ʸýڵ�
			{
				cout << top->_data << " ";
				s.pop();
				prev = top;//����prev
			}
			else
				cur = top->_right;//����Ԫ�ص��ҽڵ�û�з��ʹ����򽫸�Ԫ�ص��ҽڵ�ѹջ
		}
		cout << endl;
	}
	//˼·�����ö����Ƚ��ȳ����ص�,������һ��ڵ�ʱ����������һ��ڵ���ӣ���������һ��ڵ��
	//������ӣ�Ȼ��ɷ�����һ��ڵ�
	void LevelOrder()//�������
	{
		queue<Node*> q;
		Node* cur = _root;
		if (cur)
			q.push(cur);//�����ڵ㲻Ϊ�գ������ڵ����
		while (!q.empty())//���������Ľ��������Ƕ���Ϊ��
		{
			cur = q.front();
			cout <<cur->_data << " ";//���ʶ�ͷԪ��
			if (cur->_left)
			{
				q.push(cur->_left);//����Ԫ�ص���ڵ����
			}
			if (cur->_right)
			{
				q.push(cur->_right);//����Ԫ�ص��ҽڵ����
			}
			q.pop();//���ʹ��Ľڵ����
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
	Node* Find(const T& x)//����Ԫ��
	{
		return _Find(_root,x);
	}
	/*size_t GetKlevel(size_t k)
	{
		size_t size = 0;
		size_t level = 1;
		_GetKlevel(_root, k, level, size);
		return size;
	}*/
	size_t GetKlevel(size_t k)
	{
		return _GetKlevel(_root,k);
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
		if (root == NULL)
			return 0;
		return 1 + _Size(root->_left) + _Size(root->_right);
	}

	//���(�߶�)
	//˼·�������ڵ㲻Ϊ�գ�����������ȡ��������Ⱥ�����������е����ֵ��
	size_t _Depth(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		size_t Ldepth = _Depth(root->_left);//�������������
		size_t Rdepth = _Depth(root->_right);//�������������
		if (Ldepth > Rdepth)//ȡ�����ֵ
		{
			return Ldepth+1;//��ǰ��������������+1
		}
		else
			return Rdepth+1;//��ǰ��������������+1
	}
	size_t _LeafSize(Node* root)//Ҷ�ӽڵ����
	{
		if (root == NULL)//Ϊ�շ���
			return 0;
		if (root->_left == NULL && root->_right == NULL)//���ڵ�ΪҶ�ӽڵ㣨û�к��ӣ�
			return 1;
		return _LeafSize(root->_left) + _LeafSize(root->_right);//Ҷ�ӽڵ�ĸ�������������Ҷ�ӽڵ����+������Ҷ�ӽڵ�ĸ���
	}
	Node* _Find(Node* root, const T& x)//���ҽڵ�
	{
		if (root == NULL)//���ڵ�Ϊ��
			return NULL;//���ؿ�
		if (root->_data == x)//���ڵ�ֵ����Ҫ���ҵ�ֵ
			return root;//���ظýڵ�
		Node* ret = _Find(root->_left, x);//�������ڣ���ݹ����������в���
		if (ret)
		        return ret;//�����ҽ����Ϊ�գ��򷵻ز��ҵĽڵ��ַ
		else
			return _Find(root->_right, x);//��Ϊ�գ�������������û�иýڵ㣩�������������в���
	
	}
	//void _GetKlevel(Node* root, size_t k,size_t level,size_t& size)//��k��ڵ�������ֵ��
	//{
	//	if (root == NULL)
	//		return;
	//	if (level == k)//��k���ڵ�ǰ����
	//	{
	//		++size;
	//		return ;//����size+1;
	//	}
	//	_GetKlevel(root->_left, k, level + 1, size);//������һ��
	//	_GetKlevel(root->_right, k, level + 1, size);//������һ��

	//}
	size_t _GetKlevel(Node* cur,size_t k)
	{
		if (cur == NULL)
			return 0;
		if (k == 1)
			return 1;
		else
			return _GetKlevel(cur->_left, k - 1) + _GetKlevel(cur->_right, k - 1);
	}
protected:
	BinaryTreeNode<T>* _root;
};