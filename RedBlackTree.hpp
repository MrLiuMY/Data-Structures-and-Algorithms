#pragma once
#include <iostream>
using namespace std;


#define RED true;
#define BLACK false;

template<typename RBTreeKeytype, typename RBTreeValuetype> class RedBlackTree;


template<typename RBTreeKeytype,typename RBTreeValuetype>
class RedBlackTreeNode
{
public:
	RedBlackTreeNode()
	{
		this->left = NULL;
		this->right = NULL;
	}
	RedBlackTreeNode(RBTreeKeytype key, RBTreeValuetype val, bool color, RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* left, RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* right)
	{
		this->left = left;
		this->right = right;
		this->m_key = key;
		this->m_value = val;
		this->m_color = color;
	}
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* left;//记录左子结点
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* right;//记录右子结点
	RBTreeKeytype m_key;//存储键
	RBTreeValuetype m_value;//存储值
	bool m_color;//由其父结点指向它的链接的颜色

	friend class RedBlackTree<typename RBTreeKeytype, typename RBTreeValuetype>;
};

template<typename RBTreeKeytype, typename RBTreeValuetype>
class RedBlackTree
{
public:
	//创建RedBlackTree对象
	RedBlackTree();
	//在整个树上完成插入操作
	void Put(RBTreeKeytype key, RBTreeValuetype val);
	//根据key，从树中找出对应的值
	RBTreeValuetype Get(RBTreeKeytype key);
	//获取树中元素的个数
	int Size();

private:
	//判断当前结点的父指向链接是否为红色
	bool IsRed(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* x);
	//左旋调整
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RotateLeft(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h);
	//右旋调整
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RotateRight(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h);
	//颜色反转,相当于完成拆分4-结点
	void FlipColors(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h);
	//在指定树中，完成插入操作,并返回添加元素后新的树
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* Put(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h, RBTreeKeytype key, RBTreeValuetype val);
	//从指定的树x中，找出key对应的值
	RBTreeValuetype Get(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* x, RBTreeKeytype key);
private:
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* root;
	int N;
	//static bool RED = true;
	//static bool BLACK = false;
};

//创建RedBlackTree对象
template<typename RBTreeKeytype, typename RBTreeValuetype>
RedBlackTree<RBTreeKeytype, RBTreeValuetype>::RedBlackTree()
{
	root = new RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>();
}



//在整个树上完成插入操作
template<typename RBTreeKeytype, typename RBTreeValuetype>
void RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Put(RBTreeKeytype key, RBTreeValuetype val)
{
	//在root整个树上插入key-val 
	root = this->Put(root, key, val); 
	//让根结点的颜色变为BLACK 
	root->m_color = BLACK;
}



//根据key，从树中找出对应的值
template<typename RBTreeKeytype, typename RBTreeValuetype>
RBTreeValuetype RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Get(RBTreeKeytype key)
{
	return Get(root, key);
}



//获取树中元素的个数
template<typename RBTreeKeytype, typename RBTreeValuetype>
int RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Size()
{
	return N;
}




//判断当前结点的父指向链接是否为红色
template<typename RBTreeKeytype, typename RBTreeValuetype>
bool RedBlackTree<RBTreeKeytype, RBTreeValuetype>::IsRed(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* x)
{
	if (x == NULL)
	{
		return false;
	}
	return x->m_color == RED;
}


//左旋调整
template<typename RBTreeKeytype, typename RBTreeValuetype>
RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RedBlackTree<RBTreeKeytype, RBTreeValuetype>::RotateLeft(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h)
{
	//找出当前结点h的右子结点
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* hRight = h->right;
	//找出右子结点的左子结点
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* hRightLeft = hRight->left;
	//让当前结点h的右子结点的左子结点成为当前结点的右子结点 
	h->right = hRightLeft;
	//让当前结点h称为右子结点的左子结点 
	hRight->left = h; 
	//让当前结点h的color变成右子结点的color 
	hRight->m_color = h->m_color; 
	//让当前结点h的color变为RED 
	h->m_color = RED; 
	//返回当前结点的右子结点 
	return hRight;
}


//右旋调整
template<typename RBTreeKeytype, typename RBTreeValuetype>
RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RedBlackTree<RBTreeKeytype, RBTreeValuetype>::RotateRight(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h)
{
	//找出当前结点h的左子结点 
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* hLeft = h->left;
	//找出当前结点h的左子结点的右子结点 
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* hLeftRight = hLeft->right;
	//让当前结点h的左子结点的右子结点称为当前结点的左子结点 
	h->left = hLeftRight;
	//让当前结点称为左子结点的右子结点 
	hLeft->right = h; 
	//让当前结点h的color值称为左子结点的color值 
	hLeft->m_color = h->m_color; 
	//让当前结点h的color变为RED 
	h->m_color = RED; 
	//返回当前结点的左子结点 
	return hLeft;
}



//颜色反转,相当于完成拆分4-结点
template<typename RBTreeKeytype, typename RBTreeValuetype>
void RedBlackTree<RBTreeKeytype, RBTreeValuetype>::FlipColors(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h)
{
	//当前结点的color属性值变为RED； 
	h->m_color = RED; 
	//当前结点的左右子结点的color属性值都变为黑色 
	h->left->m_color = BLACK; 
	h->right->m_color = BLACK;
}



//在指定树中，完成插入操作,并返回添加元素后新的树
template<typename RBTreeKeytype, typename RBTreeValuetype>
RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Put(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h, RBTreeKeytype key, RBTreeValuetype val)
{
	if (h == NULL)
	{
		//标准的插入操作，和父结点用红链接相连
		N++;
		RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* newnode;
		newnode = new RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>(key, val, true, NULL, NULL);
		return newnode;
	}
	//比较要插入的键和当前结点的键 
	if (key < h->m_key)
	{
		//继续寻找左子树插入 
		h->left = Put(h->left, key, val);
	}
	else if (key > h->m_key)
	{ 
		//继续寻找右子树插入 
		h->right = Put(h->right, key, val); 
	} 
	else 
	{ 
		//已经有相同的结点存在，修改节点的值；
		h->m_value = val; 
	}
	//如果当前结点的右链接是红色，左链接是黑色，需要左旋 
	if (IsRed(h->right) && !IsRed(h->left)) 
	{ 
		h=RotateLeft(h); 
	}
	//如果当前结点的左子结点和左子结点的左子结点都是红色链接，则需要右旋 
	if (IsRed(h->left) && IsRed(h->left->left)) 
	{ 
		h=RotateRight(h); 
	}
	//如果当前结点的左链接和右链接都是红色，需要颜色变换 
	if (IsRed(h->left) && IsRed(h->right)) 
	{ 
		FlipColors(h); 
	}
	//返回当前结点 
	return h;
}




//从指定的树x中，找出key对应的值
template<typename RBTreeKeytype, typename RBTreeValuetype>
RBTreeValuetype RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Get(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* x, RBTreeKeytype key)
{
	//如果当前结点为空，则没有找到,返回null
	if (x == NULL)
	{
		return NULL;
	}
	//比较当前结点的键和key
	if (key < x->m_key)
	{
		//如果要查询的key小于当前结点的key，则继续找当前结点的左子结点； 
		return Get(x->left, key);
	}
	else if (key > x->m_key)
	{
		//如果要查询的key大于当前结点的key，则继续找当前结点的右子结点；
		return Get(x->right, key);
	}
	else
	{
		//如果要查询的key等于当前结点的key，则树中返回当前结点的value。
		return x->m_value;
	}
}


