#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
void InitLinkList(pList* pHead)//������ĳ�ʼ��
{
	assert(pHead);
	*pHead = NULL;
}


void Destroy(pList *pHead)//���٣���̬���ٵ��ڴ��ͷţ�
{
	assert(pHead);
	pLinkNode del = NULL;
	pLinkNode cur = *pHead;
	while (*pHead)
	{
		del = *pHead;
		*pHead = (*pHead)->next;
		free(del);
		del = NULL;
	}
}


pLinkNode BuyNode(DataType x)//�����½ڵ�
{
	pLinkNode NewNode = (pLinkNode)malloc(sizeof(LinkNode));
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}


void PushBack(pList* pHead, DataType x)
{
    assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode NewNode=BuyNode(x);

	if (cur == NULL)
	{
		*pHead = NewNode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = NewNode;
	}
}


void PrintList(pList list)
{
	pLinkNode cur = list;
	printf("list is: ");
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}


void PopBack(pList* pHead)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode del = NULL;
	if (cur == NULL)
	{
		return;
	}
	else if (cur->next == NULL)
	{
		free(cur);
		*pHead = NULL;
	}
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		del = cur->next;
		cur->next = NULL;
		free(del);
		del = NULL;
	}
}


void PushFront(pList* pHead, DataType x)
{
	assert(pHead);
	pLinkNode NewNode = BuyNode(x);
	pLinkNode cur = *pHead;

	if (cur == NULL)
	{
		*pHead = NewNode;
	}
	else
	{
		NewNode->next = *pHead;
		*pHead = NewNode;
	}
}


void PopFront(pList* pHead)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode del = cur;
	if (cur == NULL)
	{
		return;
	}
	else
	{
		*pHead = cur->next;
		free(del);
		del = NULL;
	}
}


int GetListLength(pList head)
{
	
	int count = 0;
	pLinkNode cur = head;
	
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}


pLinkNode Find(pList head, DataType x)
{
	pLinkNode cur = head;
	
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}


void Insert(pList *pHead, pLinkNode pos, DataType x)
{
	assert(pHead);
	assert(pos);
	pLinkNode cur = *pHead;
	pLinkNode NewNode = BuyNode(x);

	if (cur ==pos)
	{
		NewNode->next = cur;
		*pHead = NewNode;
	}
	else
	{
		while (cur->next!=pos)
		{
			cur = cur->next;
		}
		NewNode->next =cur->next;
		cur->next = NewNode;
	}
}


void Remove(pList *pHead, DataType x)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode prev = NULL;
	pLinkNode del = NULL;
	while (cur)
	{
		if (cur->data == x)
		{	
			del = cur;
			if (cur == *pHead)
			{
				*pHead = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(del);
			del = NULL;
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}


void Erase(pList *pHead, pLinkNode pos)
{
	assert(pHead);
	assert(pos);
	pLinkNode cur = *pHead;
	pLinkNode del = cur;
	pLinkNode prev = NULL;
	while (cur)
	{
		del = cur;
		if (cur == pos)
		{
			if (cur == *pHead)
			{
				*pHead = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(del);
			del = NULL;
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}


void RemoveAll(pList *pHead, DataType x)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode prev = NULL;
	pLinkNode del = NULL;
	while (cur)
	{
		if (cur->data == x)
		{
			del = cur;
			if (cur == *pHead)
			{
				*pHead = cur->next;
				cur = *pHead;
			}
			else
			{
				prev->next = cur->next;
				cur = prev->next;
			}
			free(del);
			del = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}



//��������������
//ɾ����β�ڵ�-----1
void EraseNotTail(pLinkNode pos)
{
	assert(pos);
	pLinkNode del = NULL;

	pos->data = pos->next->data;
	del = pos->next;
	pos->next = pos->next->next;
	free(del);
    del = NULL;
}
//��ת����������--2
void ReverseList(pList* pHead)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode prev = NULL;
	pLinkNode NewHead = NULL;

	while (cur)
	{
		prev = cur;
		cur = cur->next;
		prev->next = NewHead;
		NewHead = prev;
	    
	}
	*pHead = NewHead;
}
//��������ð�ݣ�--3
void BubbleSort(pList * pHead)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode end = NULL;
	DataType tmp = 0;

	while (cur != end)
	{
		while (cur && cur->next != end)
		{
			if (cur->data > cur->next->data)
			{
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		end = cur;
		cur = *pHead;
	}
}

// �ڵ�ǰ�ڵ�ǰ����һ������x-----5
void InsertFrontNode(pLinkNode pos, DataType x)
{
	assert(pos);
	pLinkNode NewNode = BuyNode(x);
	DataType tmp = 0;
	NewNode->next = pos->next;
	pos->next = NewNode;

	tmp = NewNode->data;
	NewNode->data = pos->data;
	pos->data = tmp;
}
//�ϲ�������������-----6
pLinkNode Merge(pList l1, pList l2)
{

	pList NewHead = NULL;
	pLinkNode cur = NULL;

	//if (l1 == l2)
	//{
	//	return l1;
	//}
	//if (l1 == NULL && l2 != NULL)
	//{
	//	return l2;
	//}
	//if (l1 != NULL && l2 == NULL)
	//{
	//	return l1;
	//}
	if (l1 == NULL || l2 == NULL)
	{
		if (l1)
			return l1;
		else
	        return l2;
		
	}
	if (l1->data < l2->data)
	{
		NewHead = l1;
		l1 = l1->next;
	}
	else
	{
		NewHead = l2;
		l2 = l2->next;
	}
	cur = NewHead;
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	if (l1)
	{
		cur->next = l1;
	}
	else
	{
		cur->next = l2;
	}
	return NewHead;
}
pLinkNode _Merge(pList l1, pList l2)
{

	pList NewHead = NULL;
	pLinkNode cur = NULL;

	if (l1 == NULL || l2 == NULL)
	{
		if (l1)
			return l1;
		else
			return l2;

	}
	if (l1->data < l2->data)
	{
		NewHead = l1;
		NewHead->next = _Merge(l1->next, l2);
	}
	else
	{
		NewHead = l2;
		NewHead->next = _Merge(l1, l2->next);
	}
	return NewHead;
}

//����������м�ڵ�---7
pLinkNode FindMidNode(pList head)
{
	pLinkNode fast = head;
	pLinkNode slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//Լɪ��
pLinkNode JoseCycle(pList *pHead, int num)
{
	assert(pHead);

	pLinkNode cur = *pHead;
	pLinkNode del = NULL;
	int count = 0;

	while (1)
	{
		count = num;
		if (cur == cur->next->next) //��ǰ�ڵ�ĺ�һ���ڵ��next�ǵ�ǰ�ڵ�ʱ������ѭ��
		{
			break;
		}	
			while (--count)    //�ҵ���num��Ԫ��
			{
				cur = cur->next;
			}
			del = cur->next;
			cur->data = cur->next->data;
			cur->next = cur->next->next;
			free(del); //ɾ����num��Ԫ��
			del == NULL;
	}
	*pHead = cur;
	return cur;
}
// ɾ��������ĵ�����k���ڵ�(k > 1 && k < ������ܳ���)----9
// ʱ�临�Ӷ�O(N)
void DelKNode(pList *pHead, int k)
{
	assert(k > 1);

	pLinkNode l1 = *pHead;
	pLinkNode l2 = *pHead;
	pLinkNode del = NULL;

	while (--k && l2->next) 
	{
		l2 = l2->next;
	}
	if (l2->next == NULL) //k>=�����ܳ���
	{
		return;
	}
	while (l2->next)
	{
		l2 = l2->next;
		l1 = l1->next;
	}
		del = l1->next;
		l1->data = l1->next->data;
		l1->next = l1->next->next;
		free(del);
		del = NULL;
}

// �ж������Ƿ���� ,���������������ڵ㣬����������NULL
pLinkNode CheckCycle(pList head)
{
	pLinkNode fast = head;
	pLinkNode slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return slow;
		}
	}
	return NULL;
}

//������������󻷵ĳ���
int GetCircleLength(pLinkNode meet)
{
	pLinkNode cur = meet;
	int count = 0;

	do
	{
		cur = cur->next; 
		count++;
	} while (cur != meet);

	return count;
}

//��ȡ����ڵ�
pLinkNode GetCycleEntryNode(pList head, pLinkNode MeetNode)
{
	pLinkNode Entry= head;
	pLinkNode meet = MeetNode;

	while (meet != Entry)
	{
		Entry = Entry->next;
		meet = meet->next;
	}
	return Entry;
}
pLinkNode _GetCycleEntryNode(pList head, pLinkNode MeetNode)//�������ת��Ϊ�����ཻ�����ȡ���
{
	pLinkNode Entry = head;
	pLinkNode meet = MeetNode->next;
	int len_head = 0;
	int len_meet = 0;
	int len = 0;

	while (Entry != MeetNode) //��������
	{
		len_head++;
		Entry = Entry->next;
	}
	while (meet != MeetNode)//��������
	{
		len_meet++;
		meet = meet->next;
	}

	 Entry = head;
	 meet = MeetNode->next;

	if (len_head > len_meet)  
	{
		len = len_head - len_meet;
		while (len--)
		{
			Entry = Entry->next;
		}//�ϳ���������len=|len_l1 - len_l2|��
	}
	else
	{
		len = len_meet - len_head;
		while (len--)
		{
			meet = meet->next;
		}//�ϳ���������len=|len_l1 - len_l2|��
	}

	while (meet != Entry)
	{
		Entry = Entry->next;
		meet = meet->next;
	} //��ָ��ͬʱ�ߣ������ڵ���ǻ���ڵ�
	return Entry;
}



// �ж����������Ƿ��ཻ����������������������
int CheckCross(pList list1, pList list2)
{
	pLinkNode l1 = list1;
	pLinkNode l2 = list2;

	if (l1 == NULL || l2 == NULL)
	{
		return 0;
	}
	while (l1->next) 
	{
		l1 = l1->next;
	} //����l1����������ĩβ
	while (l2->next)
	{
		l2 = l2->next;
	}//����l2����������ĩβ
	if (l1 == l2) //�ж�����������һ���ڵ��Ƿ���ͬ����ͬ���ཻ����1
	{
		return 1;
	}
	else
		return 0;//��ͬ�򷵻�0
}
// ������Ľ��㣬����������n����nΪ������ĳ��Ȳ��Ȼ����һ���ߣ���һ����������Ϊ���㡣
pLinkNode LinkCrossNode(pList list1, pList list2)
{
	int len_l1=0;
	int len_l2 = 0;
	int len = 0;
	pLinkNode l1 = list1;
	pLinkNode l2 = list2;
	pLinkNode longlink = NULL;
	pLinkNode shortlink = NULL;
	while (l1)
	{
		len_l1++;
		l1 = l1->next;
	}//��¼��һ��������
	while (l2)
	{
		len_l2++;
		l2 = l2->next;
	}//��¼�ڶ���������

	if (len_l1 > len_l2)
	{
		len = len_l1 - len_l2;
	  while (len--)
	  {
			list1 = list1->next;
	  }//�ϳ���������len = |len_l1 - len_l2|��
	}
	else
	{
		len = len_l2 - len_l1;
		while (len--)
		{
			list2 = list2->next;
		}//�ϳ���������len = |len_l1 - len_l2|��
	}
	
	while (list1!= list2)//��ָ��ͬʱ�ߣ������������������Ľ���
	{
		list1 = list1->next;
		list2 = list2->next;
	}
	return list1;
}
//��β��ͷ��ӡ����
