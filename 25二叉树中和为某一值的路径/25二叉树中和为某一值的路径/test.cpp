#include<iostream>
#include<vector>
using namespace std;

struct BinaryTreeNode
{
	BinaryTreeNode(const int& d)
	:_value(d)
	, _left(NULL)
	, _right(NULL)
	{
	}
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};
void FindPath(BinaryTreeNode* root, int expectSum, vector<int>& path, int& curSum)
{
	curSum += root->_value;
	path.push_back(root->_value);
	//�����Ҷ�ӽڵ㣬����·��֮�͵���expectSum,���ӡ����·��
	if (root->_left == NULL && root->_right == NULL && curSum == expectSum)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
	}
	//������Ҷ�ӽڵ㣬���������ӽڵ�
	if (root->_left != NULL)
		FindPath(root->_left,expectSum,path,curSum);
	if (root->_right != NULL)
		FindPath(root->_right, expectSum, path, curSum);
	//���ظ��ڵ�֮ǰ��·����ɾ���ýڵ㣬��ǰ��curSum��ȥ��ǰ�ڵ�ֵ
	curSum -= root->_value;
	path.pop_back();
}

void FindPath(BinaryTreeNode* root,int expectSum)
{
	if (root == NULL)
		return;
	vector<int> path;
	int curSum = 0;
	FindPath(root, expectSum, path, curSum);
}
void Test()
{
	BinaryTreeNode* root=new BinaryTreeNode(10);
	BinaryTreeNode* left1 =root->_left= new BinaryTreeNode(5);
	BinaryTreeNode* right2 = root->_right=new BinaryTreeNode(12);
	BinaryTreeNode* left1l =left1->_left= new BinaryTreeNode(4);
	BinaryTreeNode* right1r = left1->_right=new BinaryTreeNode(7);
	FindPath(root,22);
}
int main()
{
	Test();
	getchar();
	return 0;
}