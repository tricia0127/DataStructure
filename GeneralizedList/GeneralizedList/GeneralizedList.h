#pragma once

#include<iostream>
#include<assert.h>

using namespace std;


enum Type
{
	HEAD,//头节点
	VALUE,//值
	SUB//子表节点
};

struct GeneralizedNode//广义表节点
{
	GeneralizedNode(const Type& type = HEAD,const char& value='0')
	:_next(NULL)
	,_SubLink(NULL)
	, _type(type)
	{
		_value = value;
	}
	Type _type;//节点类型
	GeneralizedNode* _next;//指向同层下一个节点的地址
	union
	{
		char _value;//值
		GeneralizedNode* _SubLink;//指向子表指针
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
	Generalized& operator=(Generalized g)
	{
		swap(_head, g._head);
		return *this;
	}
	~Generalized()
	{
		_DelGeneralized(_head);
	}
	void Print()
	{
		_Print(_head);
	}
	size_t Size()
	{
		size_t count = 0;
		count=_Size(_head,count);
		return count;
	}
	size_t Depth()
	{
		size_t mdepth = 1;
		_Depth(_head, 1,mdepth);
		return mdepth;
	}
protected:
	size_t _Depth(GeneralizedNode *head,size_t depth,size_t& mdepth)
	{
		if (head == NULL)
			return depth;
		GeneralizedNode* cur = head;
		cur = cur->_next;
		while (cur)
		{
			if (cur->_type == SUB)
			{
				depth++;
				depth = _Depth(cur->_SubLink,depth,mdepth);
				if (depth > mdepth)
				{
					mdepth = depth;
				}
				depth = 1;
			}
			cur = cur->_next;
		}
		return depth;
	}
	size_t _Size(GeneralizedNode *head,size_t count)
	{
		if (_head == NULL)
			return count;
		GeneralizedNode* cur = head;
		cur = cur->_next;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				count++;
			}
			else if (cur->_type == SUB)
			{
				count = _Size(cur->_SubLink, count);
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
				cur = cur->_next;
				_cur = _cur->_next;
			}
			else if (cur->_type == SUB)
			{
				
				_cur->_next = new GeneralizedNode(SUB);
				_cur = _cur->_next;
				_cur->_SubLink=CopyGeneralized(cur->_SubLink);
				cur = cur->_next;
			}
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
			if (cur->_type == SUB)
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
			if (IsValue(*str))
			{
				cur->_next = new GeneralizedNode(VALUE,*str);
				cur = cur->_next;
				str++;
			}
			else if (*str == '(')
			{
				cur->_next = new GeneralizedNode(SUB);
				cur = cur->_next;
				cur->_SubLink = _CreatList(str);
			}
			else if (*str == ')')
			{
				++str;
				return head;
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
