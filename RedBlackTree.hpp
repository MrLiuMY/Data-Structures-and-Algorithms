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
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* left;//��¼���ӽ��
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* right;//��¼���ӽ��
	RBTreeKeytype m_key;//�洢��
	RBTreeValuetype m_value;//�洢ֵ
	bool m_color;//���丸���ָ���������ӵ���ɫ

	friend class RedBlackTree<typename RBTreeKeytype, typename RBTreeValuetype>;
};

template<typename RBTreeKeytype, typename RBTreeValuetype>
class RedBlackTree
{
public:
	//����RedBlackTree����
	RedBlackTree();
	//������������ɲ������
	void Put(RBTreeKeytype key, RBTreeValuetype val);
	//����key���������ҳ���Ӧ��ֵ
	RBTreeValuetype Get(RBTreeKeytype key);
	//��ȡ����Ԫ�صĸ���
	int Size();

private:
	//�жϵ�ǰ���ĸ�ָ�������Ƿ�Ϊ��ɫ
	bool IsRed(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* x);
	//��������
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RotateLeft(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h);
	//��������
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RotateRight(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h);
	//��ɫ��ת,�൱����ɲ��4-���
	void FlipColors(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h);
	//��ָ�����У���ɲ������,���������Ԫ�غ��µ���
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* Put(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h, RBTreeKeytype key, RBTreeValuetype val);
	//��ָ������x�У��ҳ�key��Ӧ��ֵ
	RBTreeValuetype Get(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* x, RBTreeKeytype key);
private:
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* root;
	int N;
	//static bool RED = true;
	//static bool BLACK = false;
};

//����RedBlackTree����
template<typename RBTreeKeytype, typename RBTreeValuetype>
RedBlackTree<RBTreeKeytype, RBTreeValuetype>::RedBlackTree()
{
	root = new RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>();
}



//������������ɲ������
template<typename RBTreeKeytype, typename RBTreeValuetype>
void RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Put(RBTreeKeytype key, RBTreeValuetype val)
{
	//��root�������ϲ���key-val 
	root = this->Put(root, key, val); 
	//�ø�������ɫ��ΪBLACK 
	root->m_color = BLACK;
}



//����key���������ҳ���Ӧ��ֵ
template<typename RBTreeKeytype, typename RBTreeValuetype>
RBTreeValuetype RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Get(RBTreeKeytype key)
{
	return Get(root, key);
}



//��ȡ����Ԫ�صĸ���
template<typename RBTreeKeytype, typename RBTreeValuetype>
int RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Size()
{
	return N;
}




//�жϵ�ǰ���ĸ�ָ�������Ƿ�Ϊ��ɫ
template<typename RBTreeKeytype, typename RBTreeValuetype>
bool RedBlackTree<RBTreeKeytype, RBTreeValuetype>::IsRed(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* x)
{
	if (x == NULL)
	{
		return false;
	}
	return x->m_color == RED;
}


//��������
template<typename RBTreeKeytype, typename RBTreeValuetype>
RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RedBlackTree<RBTreeKeytype, RBTreeValuetype>::RotateLeft(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h)
{
	//�ҳ���ǰ���h�����ӽ��
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* hRight = h->right;
	//�ҳ����ӽ������ӽ��
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* hRightLeft = hRight->left;
	//�õ�ǰ���h�����ӽ������ӽ���Ϊ��ǰ�������ӽ�� 
	h->right = hRightLeft;
	//�õ�ǰ���h��Ϊ���ӽ������ӽ�� 
	hRight->left = h; 
	//�õ�ǰ���h��color������ӽ���color 
	hRight->m_color = h->m_color; 
	//�õ�ǰ���h��color��ΪRED 
	h->m_color = RED; 
	//���ص�ǰ�������ӽ�� 
	return hRight;
}


//��������
template<typename RBTreeKeytype, typename RBTreeValuetype>
RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RedBlackTree<RBTreeKeytype, RBTreeValuetype>::RotateRight(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h)
{
	//�ҳ���ǰ���h�����ӽ�� 
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* hLeft = h->left;
	//�ҳ���ǰ���h�����ӽ������ӽ�� 
	RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* hLeftRight = hLeft->right;
	//�õ�ǰ���h�����ӽ������ӽ���Ϊ��ǰ�������ӽ�� 
	h->left = hLeftRight;
	//�õ�ǰ����Ϊ���ӽ������ӽ�� 
	hLeft->right = h; 
	//�õ�ǰ���h��colorֵ��Ϊ���ӽ���colorֵ 
	hLeft->m_color = h->m_color; 
	//�õ�ǰ���h��color��ΪRED 
	h->m_color = RED; 
	//���ص�ǰ�������ӽ�� 
	return hLeft;
}



//��ɫ��ת,�൱����ɲ��4-���
template<typename RBTreeKeytype, typename RBTreeValuetype>
void RedBlackTree<RBTreeKeytype, RBTreeValuetype>::FlipColors(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h)
{
	//��ǰ����color����ֵ��ΪRED�� 
	h->m_color = RED; 
	//��ǰ���������ӽ���color����ֵ����Ϊ��ɫ 
	h->left->m_color = BLACK; 
	h->right->m_color = BLACK;
}



//��ָ�����У���ɲ������,���������Ԫ�غ��µ���
template<typename RBTreeKeytype, typename RBTreeValuetype>
RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Put(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* h, RBTreeKeytype key, RBTreeValuetype val)
{
	if (h == NULL)
	{
		//��׼�Ĳ���������͸�����ú���������
		N++;
		RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* newnode;
		newnode = new RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>(key, val, true, NULL, NULL);
		return newnode;
	}
	//�Ƚ�Ҫ����ļ��͵�ǰ���ļ� 
	if (key < h->m_key)
	{
		//����Ѱ������������ 
		h->left = Put(h->left, key, val);
	}
	else if (key > h->m_key)
	{ 
		//����Ѱ������������ 
		h->right = Put(h->right, key, val); 
	} 
	else 
	{ 
		//�Ѿ�����ͬ�Ľ����ڣ��޸Ľڵ��ֵ��
		h->m_value = val; 
	}
	//�����ǰ�����������Ǻ�ɫ���������Ǻ�ɫ����Ҫ���� 
	if (IsRed(h->right) && !IsRed(h->left)) 
	{ 
		h=RotateLeft(h); 
	}
	//�����ǰ�������ӽ������ӽ������ӽ�㶼�Ǻ�ɫ���ӣ�����Ҫ���� 
	if (IsRed(h->left) && IsRed(h->left->left)) 
	{ 
		h=RotateRight(h); 
	}
	//�����ǰ���������Ӻ������Ӷ��Ǻ�ɫ����Ҫ��ɫ�任 
	if (IsRed(h->left) && IsRed(h->right)) 
	{ 
		FlipColors(h); 
	}
	//���ص�ǰ��� 
	return h;
}




//��ָ������x�У��ҳ�key��Ӧ��ֵ
template<typename RBTreeKeytype, typename RBTreeValuetype>
RBTreeValuetype RedBlackTree<RBTreeKeytype, RBTreeValuetype>::Get(RedBlackTreeNode<RBTreeKeytype, RBTreeValuetype>* x, RBTreeKeytype key)
{
	//�����ǰ���Ϊ�գ���û���ҵ�,����null
	if (x == NULL)
	{
		return NULL;
	}
	//�Ƚϵ�ǰ���ļ���key
	if (key < x->m_key)
	{
		//���Ҫ��ѯ��keyС�ڵ�ǰ����key��������ҵ�ǰ�������ӽ�㣻 
		return Get(x->left, key);
	}
	else if (key > x->m_key)
	{
		//���Ҫ��ѯ��key���ڵ�ǰ����key��������ҵ�ǰ�������ӽ�㣻
		return Get(x->right, key);
	}
	else
	{
		//���Ҫ��ѯ��key���ڵ�ǰ����key�������з��ص�ǰ����value��
		return x->m_value;
	}
}


