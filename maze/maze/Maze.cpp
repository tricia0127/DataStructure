#define _CRT_SECURE_NO_WARNINGS
#include "Maze.h"

bool CheckPath(int *a, Pos next, int n)
{
	if (next._col < n && next._col >= 0
		&& next._row >= 0 && next._row < n
		&& (a[next._row*n + next._col] == 0))//�����ж��Ϸ��Ҹ�λ��Ԫ��Ϊ0��Ϊ��
		return true;
	return false;
}
void GetMaze(int *a, int n)
{
	FILE* fout = fopen("MazeMap.txt", "r");//�Թ���ͼ�ڷ��ڵ�ǰĿ¼�¡�MazeMap.txt����
	assert(fout);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;)
		{
			char ch = fgetc(fout);//���ļ�
			if ((ch == '0') || (ch == '1'))//��Ϊ0��1���������
			{
				a[i*n + j] = ch - '0';
				j++;
			}
			else
			{
				continue;
			}
		}
	}
	fclose(fout);//�ر��ļ�
}
void PrintMaze(int *a, int n)//��ӡ�Թ�
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i*n + j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}
bool MazePath(int *a, int n, Pos entry, stack<Pos>& path)//�ж��Թ��Ƿ���ͨ·
{
	Pos cur = entry;//�����ڵ�����ǰλ��
	Pos next;
	path.push(cur);
	while (!path.empty())//��ջ��Ϊ��
	{
		if (cur._col!=entry._col && cur._row!=entry._row
			&&( cur._col==n-1 || cur._col==0 || cur._row ==n-1 || cur._row ==0))
			//����λ�õ��������һ�У��������ߵ�����λ��
		{
			return true;
		}
		a[cur._row*n + cur._col] = 2;//����λ����Ϊ2���������߹���·

		next = cur;
		next._col++;//����һ��λ���ǵ�ǰλ�õ��ұ�
		if (CheckPath(a, next, n))//����һ��λ�õ�ֵ�Ϸ���Ϊ0(����ͨ)����������һ��λ�ã���ѹջ
			//��������ͨ��ô���ж���һ�������λ�õ�ֵ
		{
			cur = next;
			path.push(cur);
			continue;
		}

		next = cur;
		next._row++;
		if (CheckPath(a, next, n))//ͬ��
		{
			cur = next;
			path.push(cur);
			continue;
		}
		next = cur;
		next._row--;
		if (CheckPath(a, next, n))//ͬ��
		{
			cur = next;
			path.push(cur);

			continue;

		}
		next = cur;
		next._col--;
		if (CheckPath(a, next, n))//ͬ��
		{
			cur = next;
			path.push(cur);
			continue;
		}
		cur = path.top();//�����ܶ�������ͨ����ˣ�����ǰλ����Ϊջ��Ԫ�ص�����λ��
		path.pop();//��Ԫ�ص���

	}
	return false;//��ջΪ�գ���ô�Թ�û��ͨ·
}
