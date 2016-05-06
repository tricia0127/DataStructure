#pragma once

#include<assert.h>
#include<iostream>
using namespace std;

typedef int DataType;
struct Node
{
	Node(const DataType& d)
	:_data(d)
	,_next(NULL)
	{}
	DataType _data;
	Node* _next;
};

class SList
{
public:
	SList()
		:_head(NULL)
		,_tail(NULL)
	{
	}
	~SList()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* del = cur;
			cur = cur->_next;
			delete del;
		}
	}
	SList(const SList& s)
		:_head(NULL)
		,_tail(NULL)
	{
		Node* cur = s._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	SList& operator=(SList s)
	{
		swap(_head,s._head);
		swap(_tail,s._tail);
		return *this;
	}
public:
	void PushBack(const DataType& d);
	void PushFront(const DataType& d);
	void PopBack();
	void PopFront();
	Node* Find(const DataType& d);
	void Insert(Node* pos, const DataType& d);
	void Reverse();
	void Sort();
	void Remove(const DataType& d);
	void RemoveAll(const DataType& d);
	void Erase(Node* pos);

	friend ostream& operator<<(ostream& output, const SList& s);

	//��������������
	//ɾ����β�ڵ�-----1
	void EraseNotTail(Node* pos);

	// �ڵ�ǰ�ڵ�ǰ����һ������x-----5
	void InsertFrontNode(Node* pos, DataType d);

	//�ϲ����������б�-----6
	void SList::Merge(SList l1);



	//����������м�ڵ�---7
	Node* FindMidNode();

	//Լɪ��
	Node* JoseCycle(int num);

	// ɾ��������ĵ�����k���ڵ�(k > 1 && k < ������ܳ���)----9
	// ʱ�临�Ӷ�O(N)
	void DelKNode(int k);

	// ������������⡿-----10
	// �ж������Ƿ���� ,���������������ڵ㣬����������NULL
	Node* CheckCycle();
	//������������󻷵ĳ���
	int GetCircleLength(Node* meet);
	//��ȡ����ڵ�
	Node* FindEntryNMeetNodeode(Node* MeetNode);


	// �������ཻ���⡿
	//
	// �ж����������Ƿ��ཻ����������������������

	int CheckCross(SList list1, SList list2);
	// ������Ľ��㣬����������n����nΪ������ĳ��Ȳ��Ȼ����һ���ߣ���һ����������Ϊ���㡣
	Node* LinkCrossNode(SList list1, SList list2);
private:
	Node* _head;
	Node* _tail;
};