#include<assert.h>
#include<iostream>
#include<string.h>
using namespace std;
#include"Sort.h"
void InsertSort(int *a, int n)//��������
{
	assert(a || n > 0);

	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (a[end] > tmp && end >= 0)//��ǰһ��Ԫ�رȵ�ǰԪ��ֵ����ô�ͽ�ǰһ��Ԫ�������
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;//����ǰԪ��ֵ�Ž�����С��Ԫ�صĺ���
	}

}
void ShellSort(int *a, int n)//ϣ������ ͬʱ�Զ�����������
{
	assert(a || n > 0);
	int gap = n;
	while (gap > 1)//���һ����������Ԫ�ظ���Ϊ1
	{
		gap =gap/3 + 1;
		for (int i = 1; i < n; i++)
		{
			int tmp = a[i];
			int end = i - gap;
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}
//void SelecttSort(int *a, int n)//ѡ������
//{
//	assert(a || n > 0);
//	int maxindex = 0;
//	for (int j = n - 1; j > 0; j--)
//	{
//		maxindex = 0;
//		for (int i = 1; i <= j; i++)//ѡ��һ�������
//		{
//			if (a[i] > a[maxindex])
//				maxindex = i;
//
//		}
//		swap(a[j], a[maxindex]);//�뽻����a[j]λ����
//	}
//}
void SelecttSort(int *a, int n)//ѡ������
{
	assert(a || n > 0);
	int maxindex = 0;
	int minindex = 0;
	int right = n - 1;
	int left = 0;
	while (left < right)
	{
		minindex = left;
		maxindex = right;
		for (int i = left; i <= right; i++)
		{
			if (a[maxindex] < a[i])
				maxindex = i;
			if (a[minindex] > a[i])
				minindex = i;
		}
		swap(a[maxindex], a[right]);
		if (minindex == right)
			minindex = maxindex;
		swap(a[minindex], a[left]);
		left++;
		right--;
	}
}
//void AdjustDown()
void HeapSort(int *a, int n)
{




}

int GetKey(int *a, int left,int right)//����ȡ�з�ȷ��keyֵ
{

	int mid = left + (right - left) / 2;
	if (a[left] > a[mid])
	{
		if (a[left] > a[right])
		{
			if (a[mid] < a[right])
				return right;
			else
				return mid;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (a[right] > a[left])
		{
			if (a[mid] > a[right])
				return right;
			else
				return mid;
		}
		else
		{
			return left;
		}
	}
}
//��������ֿ� ����һ
//int PartSort(int *a,int left,int right)
//{
//	int mid = GetKey(a, left,right);
//	swap(a[mid], a[right]);
//	
//	int key= a[right];
//	int start = left;
//	int end = right - 1;
//	while (start < end)
//	{
//		while (start < end && a[start] <= key)//�Ҵ���a[key]ֵ
//			start++;
//
//		while (start < end && a[end] >= key)//��С��a[key]ֵ
//			end--;
//		if (start < end)
//		swap(a[end], a[start]);//������a[key]��С��a[key]������ʹ�����С��a[key],�ұߴ���a[key]
//	}
//	if (a[start] > a[right])//��֤start���С��a[key]���ұߴ���a[key]
//	{
//		swap(a[start], a[right]);
//	}
//	return start;
//}

//int PartSort(int *a, int left, int right)//�������� �������ڿӷ�
//{
//		int key = GetKey(a, left,right);
//		swap(a[key], a[right]);
//		int keyValue = a[right];//�����ұ�ֵa[right]����������������һ����
//		while (left < right)
//		{
//			//����������Ҵ���keyValue��ֵ��������У����γ�һ����
//			while (left < right && a[left] < keyValue)
//				left++;
//			if (left<right)
//				a[right--] = a[left];//�������
//			//���ұ�������С��keyValue��ֵ��������У����γ�һ����
//			while (left < right && a[right] > keyValue)
//				right--;
//			if (left<right)
//		       a[left++] = a[right];//�������
//		}
//		a[left] = keyValue;//��keyValue�������һ������
//		return left;
//}

int PartSort(int *a, int left, int right)//�������򷽷���
{
	int key = GetKey(a, left, right);
	swap(a[key], a[right]);
	
	int prev = left - 1;
	int cur = left;
	while (cur < right)
	{
		if (a[cur] < a[right] && ++prev != cur )
			swap(a[cur], a[prev]);
		++cur;
	}
	swap(a[++prev], a[right]);
	return prev;
}
void QuickSort(int *a, int left,int right)//��������
{
	assert(a);
	if (left < right)
	{
		int div = PartSort(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}
void BubbleSort(int *a, int n)//ð������
{
	assert(a || n>0);
	bool flag = true;
	for (int i = 0; i < n-1; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}

		}
		if (flag == false)
			break;
	}

}
void Merge(int *a, int *tmp, int begin1, int end1, int begin2, int end2)
{
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

}
void _MergeSort(int *a, int *tmp, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(a, tmp, left,mid);
	_MergeSort(a, tmp, mid + 1, right);
	Merge(a, tmp, left, mid, mid + 1, right);
	memcpy(a + left,tmp + left, (right - left + 1)*sizeof(int));
}
void MergeSort(int *a, int n)
{
	assert(a || n);
	int *tmp = new int[n];
	_MergeSort(a,tmp,0,n-1);
	delete[] tmp;
}

void CountSort(int *a, int n,int min,int max)
{
	assert(a || n > 0 || min < max);
	int cap = max - min + 1;
	int *tmp = new int[cap];
	memset(tmp, 0, sizeof(int)*cap);
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		assert(a[i] >= 0);
		index = a[i] - min;
		++tmp[index];
	}
	index = 0;
	for (int i = 0; i < cap; i++)
	{
		cout << "tmp[" << i+min << "]" << tmp[i] << endl;
		while (tmp[i]--)
		{
			a[index++] = i+min;
		}
	}
	delete[] tmp;
}
void RadixSort(int *a, int n)
{



}

