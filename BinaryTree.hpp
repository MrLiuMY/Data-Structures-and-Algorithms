#pragma once
#include <iostream>
#include "Queue.hpp"
#include <vector>
using namespace std;

template<typename Keytype, typename Valuetype> class BinaryTree;

template<typename Keytype,typename Valuetype>
class TreeNode
{
public:
	TreeNode()
	{
		this->left = NULL;
		this->right = NULL;

	}
	TreeNode(Keytype key, Valuetype val, TreeNode<Keytype, Valuetype>* left, TreeNode<Keytype, Valuetype>* right)
	{
		this->left = left;
		this->right = right;
		this->m_key = key;
		this->m_value = val;
	}
public:
	TreeNode<Keytype, Valuetype>* left;    //��¼����
	TreeNode<Keytype, Valuetype>* right;	//��¼�ҽ��
	Keytype m_key;		//�洢��
	Valuetype m_value;		//�洢ֵ
	friend class BinaryTree<Keytype, Valuetype>;
};


template<typename Keytype, typename Valuetype>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(Keytype key, Valuetype val, TreeNode<Keytype, Valuetype>* left, TreeNode<Keytype, Valuetype>* right);
	//�����в���һ����ֵ��
	void Put(Keytype key, Valuetype val);
	//��ָ����x�ϣ����һ����ֵ�ԣ���������Ӻ������
	TreeNode<Keytype, Valuetype>* Put(TreeNode<Keytype, Valuetype> *x, Keytype key, Valuetype val);
	//����key���������ҵ���Ӧ��ֵ
	Valuetype Get(Keytype key);
	//��ָ�������У��ҵ�key��Ӧ��ֵ
	Valuetype Get(TreeNode<Keytype, Valuetype> *x, Keytype key);
	//����key��ɾ�����ж�Ӧ�ļ�ֵ��
	void Delete(Keytype key);
	//ɾ��ָ����x�ϵļ�Ϊkey�ļ�ֵ�ԣ�������ɾ���������
	TreeNode<Keytype, Valuetype>* Delete(TreeNode<Keytype, Valuetype> *x, Keytype key);
	//��ȡ����Ԫ�ظ���
	int Size();
	//�ҳ�������С�ļ�
	Keytype Min();
	//�ҳ�ָ�����У���С�����ڵĽ��
	TreeNode<Keytype, Valuetype>* Min(TreeNode<Keytype, Valuetype>* x);
	//�ҳ��������ļ�
	Keytype Max();
	//�ҳ�ָ�����У��������ڵĽ��
	TreeNode<Keytype, Valuetype>* Max(TreeNode<Keytype, Valuetype>* x);
	//ʹ��ǰ���������ȡ�������е����м�
	vector<Keytype> preErgodic();
	//ʹ��ǰ���������ָ����x�е����м����뵽keys������
	void preErgodic(TreeNode<Keytype, Valuetype>* x, vector<Keytype> &keys);

	//ʹ�������������ȡ�������е����м�
	Queue<Keytype> midErgodic();
	//ʹ�������������ָ����x�е����м����뵽keys������
	void midErgodic(TreeNode<Keytype, Valuetype>* x, Queue<Keytype> &keys);

	//ʹ�ú����������ȡ�������е����м�
	Queue<Keytype> afterErgodic();
	//ʹ�ú����������ָ����x�е����м����뵽keys������
	void afterErgodic(TreeNode<Keytype, Valuetype>* x, Queue<Keytype> &keys);
	//ʹ�ò����������ȡ�����������м�
	Queue<Keytype> layerErgodic();
	//������������������
	int maxDepth();
	//����ָ����x��������
	int maxDepth(TreeNode<Keytype, Valuetype>* x);
private:
	TreeNode<Keytype, Valuetype>* root;//��¼���ڵ�
	int N;//��¼����Ԫ�ظ���
};



template<typename Keytype, typename Valuetype>
BinaryTree<Keytype, Valuetype>::BinaryTree()
{
	root = new TreeNode<Keytype, Valuetype>();
}

template<typename Keytype, typename Valuetype>
BinaryTree<Keytype, Valuetype>::BinaryTree(Keytype key, Valuetype val, TreeNode<Keytype, Valuetype>* left, TreeNode<Keytype, Valuetype>* right)
{
	root = new TreeNode<Keytype, Valuetype>(key,val,left,right);
}

//�����в���һ����ֵ��
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::Put(Keytype key, Valuetype val)
{
	this->root = Put(this->root, key, val);
}



//��ָ����x�ϣ����һ����ֵ�ԣ���������Ӻ������
template<typename Keytype, typename Valuetype>
TreeNode<Keytype, Valuetype>* BinaryTree<Keytype, Valuetype>::Put(TreeNode<Keytype, Valuetype> *x, Keytype key, Valuetype val)
{

	if (x == NULL)
	{
		N++;
		TreeNode<Keytype, Valuetype> *newnode= new TreeNode<Keytype, Valuetype>(key, val, NULL, NULL);
		return newnode;
	}
	if (key > x->m_key)
	{
		///�½���key���ڵ�ǰ����key�������ҵ�ǰ�������ӽ��
		x->right = Put(x->right, key, val);
	}
	else if (key < x->m_key)
	{
		//�½���keyС�ڵ�ǰ����key�������ҵ�ǰ�������ӽ��
		x->left = Put(x->left, key, val);
	}
	else
	{
		//�½���key���ڵ�ǰ����key���ѵ�ǰ����value�����滻
		x->m_value = val;
	}
	return x;
}


//����key���������ҵ���Ӧ��ֵ
template<typename Keytype, typename Valuetype>
Valuetype BinaryTree<Keytype, Valuetype>::Get(Keytype key)
{
	return Get(root, key);
}
						  
						  
						  
//��ָ�������У��ҵ�key��Ӧ��ֵ
template<typename Keytype, typename Valuetype>
Valuetype BinaryTree<Keytype, Valuetype>::Get(TreeNode<Keytype, Valuetype> *x, Keytype key)
{
	if (x == NULL)
	{
		cout << "û��������" << endl;
	}
	if (key > x->m_key)
	{
		return Get(x->right, key);
	}
	else if (key < x->m_key)
	{
		return Get(x->left, key);
	}
	else
	{
		return x->m_value;
	}
}

//����key��ɾ�����ж�Ӧ�ļ�ֵ��
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::Delete(Keytype key)
{
	root = Delete(root, key);
}
						
						
						
//ɾ��ָ����x�ϵļ�Ϊkey�ļ�ֵ�ԣ�������ɾ���������
template<typename Keytype, typename Valuetype>
TreeNode<Keytype, Valuetype>* BinaryTree<Keytype, Valuetype>::Delete(TreeNode<Keytype, Valuetype> *x, Keytype key)
{
	if (x == NULL)
	{
		cout << "û��������" << endl;
		return NULL;
	}
	if (key > x->m_key)
	{
		x->right = Delete(x->right, key);
	}
	else if (key < x->m_key)
	{
		x->left = Delete(x->left, key);
	}
	else
	{
		N--;
		//�½����ڵ�ǰ����key����ǰx����Ҫɾ���Ľ��
		//1.�����ǰ���������������ڣ���ֱ�ӷ��ص�ǰ�������ӽ��
		if (x->right == NULL)
		{
			return x->left;
		}
		//2.�����ǰ���������������ڣ���ֱ�ӷ��ص�ǰ�������ӽ��
		if (x->left == NULL)
		{
			return x->right;
		}
		//3.��ǰ������������������ 
		//3.1�ҵ�����������С�Ľ��
		TreeNode<Keytype,Valuetype>* minNode = x->right;
		while (minNode->left != NULL)
		{
			minNode = minNode->left;
		}
		//3.2ɾ������������С�Ľ��
		TreeNode<Keytype, Valuetype>* n = x->right;
		while (n->left != NULL)
		{
			if (n->left->left == NULL)
			{
				n->left = NULL;
			}
			else
			{
				n = n->left;
			}
		}
		//3.3�ñ�ɾ��������������Ϊ��С���minNode�����������ñ�ɾ��������������Ϊ��С��� minNode��������
		minNode->left = x->left;
		minNode->right = x->right;
		//3.4�ñ�ɾ�����ĸ��ڵ�ָ����С���minNode
		TreeNode<Keytype, Valuetype>* deleteNode = x;
		free(deleteNode);
		x = minNode;
	}
	return x;
}

//��ȡ����Ԫ�ظ���
template<typename Keytype, typename Valuetype>
int BinaryTree<Keytype, Valuetype>::Size()
{
	return this->N;
}

//�ҳ�������С�ļ�
template<typename Keytype, typename Valuetype>
Keytype BinaryTree<Keytype, Valuetype>::Min()
{
	return this->Min(root)->m_key;
}



//�ҳ�ָ�����У���С�����ڵĽ��
template<typename Keytype, typename Valuetype>
TreeNode<Keytype, Valuetype>* BinaryTree<Keytype, Valuetype>::Min(TreeNode<Keytype, Valuetype>* x)
{
	if (x->left != NULL)
		return this->Min(x->left);
	else
		return x;
}

//�ҳ�������da�ļ�
template<typename Keytype, typename Valuetype>
Keytype BinaryTree<Keytype, Valuetype>::Max()
{
	return this->Max(root)->m_key;
}



//�ҳ�ָ�����У���da�����ڵĽ��
template<typename Keytype, typename Valuetype>
TreeNode<Keytype, Valuetype>* BinaryTree<Keytype, Valuetype>::Max(TreeNode<Keytype, Valuetype>* x)
{
	if (x->right != NULL)
		return this->Max(x->right);
	else
		return x;
}


//ʹ��ǰ���������ȡ�������е����м�
template<typename Keytype, typename Valuetype>
vector<Keytype> BinaryTree<Keytype, Valuetype>::preErgodic()
{
	vector<Keytype> keys1;
	this->preErgodic(this->root, keys1);
	return keys1;
}

//ʹ��ǰ���������ָ����x�е����м����뵽keys������
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::preErgodic(TreeNode<Keytype, Valuetype>* x, vector<Keytype> &keys)
{
	if (x == NULL) return;
	//1.�ѵ�ǰ����key���뵽������; 
	
	keys.push_back(x->m_key); 
	//2.�ҵ���ǰ�����������������Ϊ�գ��ݹ���������� 
	if (x->left!=NULL)
	{ 
		preErgodic(x->left,keys);
	}
	//3.�ҵ���ǰ�����������������Ϊ�գ��ݹ���������� 
	if (x->right!=NULL)
	{ 
		preErgodic(x->right,keys);
	}
}





//ʹ�������������ȡ�������е����м�
template<typename Keytype, typename Valuetype>
Queue<Keytype> BinaryTree<Keytype, Valuetype>::midErgodic()
{
	Queue<Keytype> keys2;
	midErgodic(root, keys2);
	return keys2;
}

//ʹ�������������ָ����x�е����м����뵽keys������
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::midErgodic(TreeNode<Keytype, Valuetype>* x, Queue<Keytype> &keys)
{
	if (x == NULL) return;

	//2.�ҵ���ǰ�����������������Ϊ�գ��ݹ���������� 
	if (x->left != NULL)
	{
		midErgodic(x->left, keys);
	}

	//1.�ѵ�ǰ����key���뵽������; 
	keys.enqueue(x->m_key);

	//3.�ҵ���ǰ�����������������Ϊ�գ��ݹ���������� 
	if (x->right != NULL)
	{
		midErgodic(x->right, keys);
	}
}




//ʹ�ú����������ȡ�������е����м�
template<typename Keytype, typename Valuetype>
Queue<Keytype> BinaryTree<Keytype, Valuetype>::afterErgodic()
{
	Queue<Keytype> keys3;
	afterErgodic(root, keys3);
	return keys3;
}

//ʹ�ú����������ָ����x�е����м����뵽keys������
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::afterErgodic(TreeNode<Keytype, Valuetype>* x, Queue<Keytype> &keys)
{
	if (x == NULL) return;

	//2.�ҵ���ǰ�����������������Ϊ�գ��ݹ���������� 
	if (x->left != NULL)
	{
		afterErgodic(x->left, keys);
	}

	//3.�ҵ���ǰ�����������������Ϊ�գ��ݹ���������� 
	if (x->right != NULL)
	{
		afterErgodic(x->right, keys);
	}
	//1.�ѵ�ǰ����key���뵽������; 
	keys.enqueue(x->m_key);

}


//ʹ�ò����������ȡ�����������м�
template<typename Keytype, typename Valuetype>
Queue<Keytype> BinaryTree<Keytype, Valuetype>::layerErgodic()
{
	Queue<Keytype> keys;
	Queue<TreeNode<Keytype, Valuetype>*> nodes;
	nodes.enqueue(root);
	while (!nodes.isEmpty())
	{
		TreeNode<Keytype, Valuetype> *x = nodes.dequeue();
		keys.enqueue(x->m_key);
		if (x->left != NULL)
		{
			nodes.enqueue(x->left);
		}
		if (x->right != NULL)
		{
			nodes.enqueue(x->right);
		}
	}
	return keys;
}


//������������������
template<typename Keytype, typename Valuetype>
int BinaryTree<Keytype, Valuetype>::maxDepth()
{
	return maxDepth(root);
}

//����ָ����x��������
template<typename Keytype, typename Valuetype>
int BinaryTree<Keytype, Valuetype>::maxDepth(TreeNode<Keytype, Valuetype>* x)
{
	if (x == NULL) return 0;
	int maxdep = 0, maxl = 0, maxr = 0;
	if (x->left != NULL) maxl = maxDepth(x->left);
	if (x->right != NULL) maxr = maxDepth(x->right);
	maxdep = maxl > maxr ? maxl + 1 : maxr + 1;
	return maxdep;
}
