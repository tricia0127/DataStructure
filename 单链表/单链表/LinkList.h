#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct LinkNode
{
	DataType data;
	struct LinkNode *next;
}LinkNode, *pLinkNode, *pList;

void InitLinkList(pList* pHead);//������ĳ�ʼ��
void Destroy(pList *pHead);//���٣���̬���ٵ��ڴ��ͷţ�
void PushBack(pList* pHead, DataType x);//β��
void PopBack(pList* pHead);//βɾ
void PushFront(pList* pHead, DataType x);//ͷ��
void PopFront(pList* pHead);//ͷɾ
void PrintList(pList list);//��ӡ�������Ԫ��

int GetListLength(pList head);//��ȡ������ĳ���
pLinkNode Find(pList head, DataType x);//����Ԫ��
void Insert(pList *pHead, pLinkNode pos, DataType x);//����Ԫ��
void Remove(pList *pHead, DataType x);//ɾ��ָ��Ԫ��
void RemoveAll(pList *pHead, DataType x);//ɾ��������������ָ��Ԫ��
void Erase(pList *pHead, pLinkNode pos);//��λ��ɾ��


//��������������
//ɾ����β�ڵ�-----1
void EraseNotTail(pLinkNode pos);
//��ת����������--2
void ReverseList(pList* pplist);
//��������ð�ݣ�--3
void BubbleSort(pList * pplist);

// �ڵ�ǰ�ڵ�ǰ����һ������x-----5
void InsertFrontNode(pLinkNode pos, DataType x);

//�ϲ����������б�-----6
pLinkNode Merge(pList l1, pList l2);


//����������м�ڵ�---7
pLinkNode FindMidNode(pList head);

//Լɪ��
pLinkNode JoseCycle(pList *pHead, int num);

// ɾ��������ĵ�����k���ڵ�(k > 1 && k < ������ܳ���)----9
// ʱ�临�Ӷ�O(N)
void DelKNode(pList *pHead, int k);

// ������������⡿-----10
// �ж������Ƿ���� ,���������������ڵ㣬����������NULL
pLinkNode CheckCycle(pList pList);
//������������󻷵ĳ���
int GetCircleLength(pLinkNode meet);
//��ȡ����ڵ�
pLinkNode FindEntryNMeetNodeode(pList head, pLinkNode MeetNode);


// �������ཻ���⡿
//
// �ж����������Ƿ��ཻ����������������������

int CheckCross(pList list1, pList list2);
// ������Ľ��㣬����������n����nΪ������ĳ��Ȳ��Ȼ����һ���ߣ���һ����������Ϊ���㡣
pLinkNode LinkCrossNode(pList list1, pList list2);

#endif//__LINKLIST_H__
