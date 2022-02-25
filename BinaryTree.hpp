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
	TreeNode<Keytype, Valuetype>* left;    //记录左结点
	TreeNode<Keytype, Valuetype>* right;	//记录右结点
	Keytype m_key;		//存储键
	Valuetype m_value;		//存储值
	friend class BinaryTree<Keytype, Valuetype>;
};


template<typename Keytype, typename Valuetype>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(Keytype key, Valuetype val, TreeNode<Keytype, Valuetype>* left, TreeNode<Keytype, Valuetype>* right);
	//向树中插入一个键值对
	void Put(Keytype key, Valuetype val);
	//给指定树x上，添加一个键值对，并返回添加后的新树
	TreeNode<Keytype, Valuetype>* Put(TreeNode<Keytype, Valuetype> *x, Keytype key, Valuetype val);
	//根据key，在树中找到对应的值
	Valuetype Get(Keytype key);
	//从指定的树中，找到key对应的值
	Valuetype Get(TreeNode<Keytype, Valuetype> *x, Keytype key);
	//根据key，删除树中对应的键值对
	void Delete(Keytype key);
	//删除指定树x上的键为key的键值对，并返回删除后的新树
	TreeNode<Keytype, Valuetype>* Delete(TreeNode<Keytype, Valuetype> *x, Keytype key);
	//获取树中元素个数
	int Size();
	//找出树中最小的键
	Keytype Min();
	//找出指定树中，最小键所在的结点
	TreeNode<Keytype, Valuetype>* Min(TreeNode<Keytype, Valuetype>* x);
	//找出树中最大的键
	Keytype Max();
	//找出指定树中，最大键所在的结点
	TreeNode<Keytype, Valuetype>* Max(TreeNode<Keytype, Valuetype>* x);
	//使用前序遍历，获取整个树中的所有键
	vector<Keytype> preErgodic();
	//使用前序遍历，把指定树x中的所有键放入到keys队列中
	void preErgodic(TreeNode<Keytype, Valuetype>* x, vector<Keytype> &keys);

	//使用中序遍历，获取整个树中的所有键
	Queue<Keytype> midErgodic();
	//使用中序遍历，把指定树x中的所有键放入到keys队列中
	void midErgodic(TreeNode<Keytype, Valuetype>* x, Queue<Keytype> &keys);

	//使用后序遍历，获取整个树中的所有键
	Queue<Keytype> afterErgodic();
	//使用后序遍历，把指定树x中的所有键放入到keys队列中
	void afterErgodic(TreeNode<Keytype, Valuetype>* x, Queue<Keytype> &keys);
	//使用层序遍历，获取整个树中所有键
	Queue<Keytype> layerErgodic();
	//计算整个树的最大深度
	int maxDepth();
	//计算指定树x的最大深度
	int maxDepth(TreeNode<Keytype, Valuetype>* x);
private:
	TreeNode<Keytype, Valuetype>* root;//记录根节点
	int N;//记录树中元素个数
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

//向树中插入一个键值对
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::Put(Keytype key, Valuetype val)
{
	this->root = Put(this->root, key, val);
}



//给指定树x上，添加一个键值对，并返回添加后的新树
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
		///新结点的key大于当前结点的key，继续找当前结点的右子结点
		x->right = Put(x->right, key, val);
	}
	else if (key < x->m_key)
	{
		//新结点的key小于当前结点的key，继续找当前结点的左子结点
		x->left = Put(x->left, key, val);
	}
	else
	{
		//新结点的key等于当前结点的key，把当前结点的value进行替换
		x->m_value = val;
	}
	return x;
}


//根据key，在树中找到对应的值
template<typename Keytype, typename Valuetype>
Valuetype BinaryTree<Keytype, Valuetype>::Get(Keytype key)
{
	return Get(root, key);
}
						  
						  
						  
//从指定的树中，找到key对应的值
template<typename Keytype, typename Valuetype>
Valuetype BinaryTree<Keytype, Valuetype>::Get(TreeNode<Keytype, Valuetype> *x, Keytype key)
{
	if (x == NULL)
	{
		cout << "没有这个结点" << endl;
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

//根据key，删除树中对应的键值对
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::Delete(Keytype key)
{
	root = Delete(root, key);
}
						
						
						
//删除指定树x上的键为key的键值对，并返回删除后的新树
template<typename Keytype, typename Valuetype>
TreeNode<Keytype, Valuetype>* BinaryTree<Keytype, Valuetype>::Delete(TreeNode<Keytype, Valuetype> *x, Keytype key)
{
	if (x == NULL)
	{
		cout << "没有这个结点" << endl;
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
		//新结点等于当前结点的key，当前x就是要删除的结点
		//1.如果当前结点的右子树不存在，则直接返回当前结点的左子结点
		if (x->right == NULL)
		{
			return x->left;
		}
		//2.如果当前结点的左子树不存在，则直接返回当前结点的右子结点
		if (x->left == NULL)
		{
			return x->right;
		}
		//3.当前结点的左右子树都存在 
		//3.1找到右子树中最小的结点
		TreeNode<Keytype,Valuetype>* minNode = x->right;
		while (minNode->left != NULL)
		{
			minNode = minNode->left;
		}
		//3.2删除右子树中最小的结点
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
		//3.3让被删除结点的左子树称为最小结点minNode的左子树，让被删除结点的右子树称为最小结点 minNode的右子树
		minNode->left = x->left;
		minNode->right = x->right;
		//3.4让被删除结点的父节点指向最小结点minNode
		TreeNode<Keytype, Valuetype>* deleteNode = x;
		free(deleteNode);
		x = minNode;
	}
	return x;
}

//获取树中元素个数
template<typename Keytype, typename Valuetype>
int BinaryTree<Keytype, Valuetype>::Size()
{
	return this->N;
}

//找出树中最小的键
template<typename Keytype, typename Valuetype>
Keytype BinaryTree<Keytype, Valuetype>::Min()
{
	return this->Min(root)->m_key;
}



//找出指定树中，最小键所在的结点
template<typename Keytype, typename Valuetype>
TreeNode<Keytype, Valuetype>* BinaryTree<Keytype, Valuetype>::Min(TreeNode<Keytype, Valuetype>* x)
{
	if (x->left != NULL)
		return this->Min(x->left);
	else
		return x;
}

//找出树中最da的键
template<typename Keytype, typename Valuetype>
Keytype BinaryTree<Keytype, Valuetype>::Max()
{
	return this->Max(root)->m_key;
}



//找出指定树中，最da键所在的结点
template<typename Keytype, typename Valuetype>
TreeNode<Keytype, Valuetype>* BinaryTree<Keytype, Valuetype>::Max(TreeNode<Keytype, Valuetype>* x)
{
	if (x->right != NULL)
		return this->Max(x->right);
	else
		return x;
}


//使用前序遍历，获取整个树中的所有键
template<typename Keytype, typename Valuetype>
vector<Keytype> BinaryTree<Keytype, Valuetype>::preErgodic()
{
	vector<Keytype> keys1;
	this->preErgodic(this->root, keys1);
	return keys1;
}

//使用前序遍历，把指定树x中的所有键放入到keys队列中
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::preErgodic(TreeNode<Keytype, Valuetype>* x, vector<Keytype> &keys)
{
	if (x == NULL) return;
	//1.把当前结点的key放入到队列中; 
	
	keys.push_back(x->m_key); 
	//2.找到当前结点的左子树，如果不为空，递归遍历左子树 
	if (x->left!=NULL)
	{ 
		preErgodic(x->left,keys);
	}
	//3.找到当前结点的右子树，如果不为空，递归遍历右子树 
	if (x->right!=NULL)
	{ 
		preErgodic(x->right,keys);
	}
}





//使用中序遍历，获取整个树中的所有键
template<typename Keytype, typename Valuetype>
Queue<Keytype> BinaryTree<Keytype, Valuetype>::midErgodic()
{
	Queue<Keytype> keys2;
	midErgodic(root, keys2);
	return keys2;
}

//使用中序遍历，把指定树x中的所有键放入到keys队列中
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::midErgodic(TreeNode<Keytype, Valuetype>* x, Queue<Keytype> &keys)
{
	if (x == NULL) return;

	//2.找到当前结点的左子树，如果不为空，递归遍历左子树 
	if (x->left != NULL)
	{
		midErgodic(x->left, keys);
	}

	//1.把当前结点的key放入到队列中; 
	keys.enqueue(x->m_key);

	//3.找到当前结点的右子树，如果不为空，递归遍历右子树 
	if (x->right != NULL)
	{
		midErgodic(x->right, keys);
	}
}




//使用后序遍历，获取整个树中的所有键
template<typename Keytype, typename Valuetype>
Queue<Keytype> BinaryTree<Keytype, Valuetype>::afterErgodic()
{
	Queue<Keytype> keys3;
	afterErgodic(root, keys3);
	return keys3;
}

//使用后序遍历，把指定树x中的所有键放入到keys队列中
template<typename Keytype, typename Valuetype>
void BinaryTree<Keytype, Valuetype>::afterErgodic(TreeNode<Keytype, Valuetype>* x, Queue<Keytype> &keys)
{
	if (x == NULL) return;

	//2.找到当前结点的左子树，如果不为空，递归遍历左子树 
	if (x->left != NULL)
	{
		afterErgodic(x->left, keys);
	}

	//3.找到当前结点的右子树，如果不为空，递归遍历右子树 
	if (x->right != NULL)
	{
		afterErgodic(x->right, keys);
	}
	//1.把当前结点的key放入到队列中; 
	keys.enqueue(x->m_key);

}


//使用层序遍历，获取整个树中所有键
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


//计算整个树的最大深度
template<typename Keytype, typename Valuetype>
int BinaryTree<Keytype, Valuetype>::maxDepth()
{
	return maxDepth(root);
}

//计算指定树x的最大深度
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
