#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

struct Pos
{
	int _row; //��
	int _col;//��
};

bool CheckPath(int *a, Pos next, int n);//���·���Ƿ�Ϸ����߽硢ͨ·��
void GetMaze(int *a, int n);//��õ�ͼ
void PrintMaze(int *a, int n);//��ӡ��ͼ
bool MazePath(int *a, int n, Pos entry, stack<Pos>& path);
