#pragma once

#include<iostream>
#include<assert.h>

using namespace std;


enum Type
{
	HEAD,//ͷ�ڵ�
	VALUE,//ֵ
	SUB//�ӱ�ڵ�
};

struct GeneralizedNode//�����ڵ�
{
	GeneralizedNode(const Type& type = HEAD,const char& value='0')
	:_next(NULL)
	,_SubLink(NULL)
	, _type(type)
	{
		_value = value;
	}
	Type _type;//�ڵ�����
	GeneralizedNode* _next;//ָ��ͬ����һ���ڵ�ĵ�ַ
	union
	{
		char _value;//ֵ
		GeneralizedNode* _SubLink;//ָ���ӱ�ָ��
	};
};

class Generalized
{
public:
	Generalized()
	:_head(NULL)
	{}
	Generalized(const char *str)
		:_head(NULL)
	{
		_head = _CreatList(str);
	}
	Generalized(const Generalized& g)
		:_head(NULL)
	{
		_head=CopyGeneralized(g._head);
	}
	/*Generalized& operator=(Generalized g)
	{
		swap(_head, g._head);
		return *this;
	}*/
	Generalized& operator=(const Generalized& g)
	{
		if (this != &g)
		{
			GeneralizedNode *tmp = CopyGeneralized(g._head);
			_DelGeneralized(_head);
			_head =tmp;
		}
		return *this;
	}

	~Generalized()
	{
		_DelGeneralized(_head);
		_head = NULL;
	}
	void Print()
	{
		_Print(_head);
	}
	size_t Size()
	{
		return _Size(_head);
	}
	size_t Depth()
	{
		return _Depth(_head);
	}
protected:
	size_t _Depth(GeneralizedNode *head)
		//����Ǽ�������������ı�����
	{
		int depth = 1;//�տ�ʼĬ������ı����Ϊ1
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type == SUB)//�������ӱ�
			{
				int subdepth = _Depth(cur->_SubLink);//�ݹ�����ӱ�����
				if (subdepth+1 > depth)//���ӱ���ȼ�1��������Ŀǰ����ȣ�����ԭ�����������
				{
					depth = subdepth+1;//���ù�����������
				}
			}
			cur = cur->_next;
		}
		return depth;
	}
	size_t _Size(GeneralizedNode *head)//�������Ԫ�صĸ���
	{
		int count = 0;
		
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				count++;
			}
			else if (cur->_type == SUB)
			{
				count += _Size(cur->_SubLink);
			}
			cur = cur->_next;
		}
		return count;
	}
	GeneralizedNode* CopyGeneralized(GeneralizedNode* head)
	{
		GeneralizedNode* chead = new GeneralizedNode(HEAD);
		 GeneralizedNode* cur = head->_next;
		 GeneralizedNode* _cur = chead;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				_cur->_next = new GeneralizedNode(VALUE, cur->_value);
				_cur = _cur->_next;
			}
			else if (cur->_type == SUB)
			{
				
				_cur->_next = new GeneralizedNode(SUB);
				_cur = _cur->_next;
				_cur->_SubLink=CopyGeneralized(cur->_SubLink);
			}
			cur = cur->_next;
		}
		return chead;
	}

	void _DelGeneralized(GeneralizedNode* head)
	{
		if (head == NULL)
			return;
		GeneralizedNode* cur = head;
		GeneralizedNode* del = NULL;
		while (cur)
		{
			del = cur;
			if (cur->_type == SUB)//�����ӱ�ڵ�ʱ����������
			{
				_DelGeneralized(cur->_SubLink);
			}
			cur = cur->_next;
			delete del;
		}
	}
	bool IsValue(char ch)
	{
		if ((ch >= '0'&& ch <= '9') || (ch >= 'a'&& ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			return true;
		else
			return false;
	}
	void _Print(GeneralizedNode* &head)
	{
		assert(head);
		GeneralizedNode* cur = head;
		bool IsInTable = true;
		while (cur)
		{
			if (cur->_type == HEAD)
			{
				cout << "(";
				cur = cur->_next;
				if (cur == NULL)
					cout << ")";
			}
			else if (cur->_type == VALUE)
			{
				cout << cur->_value;
				if (cur->_next != NULL)
					cout << ",";
				else
				{
					cout << ")";
					return;
				}
				cur = cur->_next;
			}
			else if(cur->_type == SUB)
			{
				_Print(cur->_SubLink);
				if (cur->_next != NULL)
					cout << ",";
				else
					cout << ")";
				cur = cur->_next;
			}
		}
	}
	GeneralizedNode* _CreatList(const char* &str)
	{

		assert(str && *str == '(');
		++str;
		GeneralizedNode* head = new GeneralizedNode(HEAD);
		GeneralizedNode* cur = head;
		while (*str)
		{
			if (IsValue(*str))//���ڵ�ֵ�ǺϷ�ֵ
			{
				cur->_next = new GeneralizedNode(VALUE,*str);//�򴴽�һ��ֵ�ڵ�
				cur = cur->_next;
				str++;
			}
			else if (*str == '(')//����'('��ʾ����һ���ӱ�ڵ�
			{
				cur->_next = new GeneralizedNode(SUB);//����һ���ӱ�ڵ�
				cur = cur->_next;
				cur->_SubLink = _CreatList(str);//�ݹ����ӱ�Ĵ���
			}
			else if (*str == ')')//����')'˵��һ�����������ӱ����
			{
				++str;
				return head;//�����ӱ��ͷ�ڵ㣬�������ͷ�ڵ�
			}
			else
				++str;
		}
		assert(false);
		return head;
	}
private:
	GeneralizedNode* _head;
};
