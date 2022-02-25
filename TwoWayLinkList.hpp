//双向链表
#pragma once
#include <iostream>
using namespace std;


template<typename datatype> class doubleLink;//双向链表声明
//双向链表数据结构定义
template<typename datatype>
class doubleNode
{
public:
	//无参数构造函数，将指针初始化为NULL
	doubleNode()
	{
		this->m_prior = NULL;
		this->m_next = NULL;
	}
	//带参数构造函数，初始化数据域与指针域
	doubleNode(datatype data, doubleNode<datatype>* prior = NULL, doubleNode<datatype>* next = NULL)
	{
		this->m_data = data;
		this->m_prior = prior;
		this->m_next = next;
	}
	~doubleNode()
	{
		this->m_prior = NULL;
		this->m_next = NULL;
	}
public:
	doubleNode<datatype>* m_prior;//指向前结点的指针
	doubleNode<datatype>* m_next;//指向后结点的指针
	datatype m_data;//自身结点的数据
	friend class doubleLink<datatype>;//定义友元类
};

//双向链表定义
template<typename datatype> 
class doubleLink
{
public:
	doubleLink();		//双向链表构造函数，链表产生新的头结点
	doubleLink(doubleNode<datatype>* node);		//双向链表构造函数，链表产生新的头结点
	~doubleLink();		//双向链表的析构函数，链表删除头结点
	void CleardoubleLink();		//清空双向链表
	bool IsEmpty();			//判断链表是否为空
	int Getlength();		//获取双向链表的长度
	datatype GetData(int n);			//获取第n个结点的数据
	bool InsertNode(datatype data, int n);			//在第n个结点插入datatype类型的data
	bool InsertNode(datatype data);				//向双向链表中添加一个元素
	bool DeleteNode(int n);			//删除第n个结点的数据
	int FindData(datatype data);		//寻找给定数值的结点，若不存在，则返回-1
	
public:
	doubleNode<datatype>* head;			//头指针
	int length;			//链表的长度
};

template<typename datatype>
doubleLink<datatype>::doubleLink()		//双向链表构造函数，链表产生新的头结点
{
	head = new doubleNode<datatype>();
	this->length = 0;
}

template<typename datatype>
doubleLink<datatype>::doubleLink(doubleNode<datatype>* node)		//双向链表构造函数，链表产生新的头结点
{
	head = node;
	this->length = 0;
}

template<typename datatype>
doubleLink<datatype>::~doubleLink()		//双向链表的析构函数，链表删除头结点
{
	delete head;
}

template<typename datatype>
void doubleLink<datatype>::CleardoubleLink()		//清空双向链表
{
	doubleNode<datatype>* p_move = head->m_next, * p_middle;//设置游标指针
	while (p_move != NULL)//判断头指针后面的结点
	{
		p_middle = p_move;
		p_move = p_middle->m_next;//游标指针借助中间指针向后移
		delete p_middle;//删除中间指针，即删除后面的结点
	}
	head->m_next = NULL;//将头指针指向空
}

template<typename datatype>
bool doubleLink<datatype>::IsEmpty()			//判断链表是否为空,空返回true，非空返回false
{
	return this->length == 0;
}

template<typename datatype>
int doubleLink<datatype>::Getlength()		//获取双向链表的长度
{
	doubleNode<datatype>* p_move = head->m_next;//设置游标指针
	int length = 0;
	while (p_move != NULL)
	{
		p_move = p_move->m_next;//游标指针后移
		length++;//计算length
	}
	return length;
}

template<typename datatype>
datatype doubleLink<datatype>::GetData(int n)			//获取第n个结点的数据
{
	if (n<1 || n>this->length)
	{
		cout << "输入非法位置" << endl;
		return false;
	}
	doubleNode<datatype>* p_move = head;
	for (int i = 1; i < n; i++)
	{
		p_move = p_move->m_next;
	}
	return p_move->m_data;
}

template<typename datatype>
bool doubleLink<datatype>::InsertNode(datatype data, int n)			//在第n个结点插入datatype类型的data
{
	if (n<1)
	{
		cout << "输入非法位置" << endl;
		return false;
	}
	doubleNode<datatype>* p_move = head;
	for (int i = 1; i < n; i++)
	{
		p_move = p_move->m_next;
		if (p_move == NULL && i <= n)
		{
			cout << "插入位置无效" << endl;
			return false;
		}
	}
	doubleNode<datatype>* newNode = new doubleNode<datatype>(data);
	if (newNode == NULL)
	{
		cout << "内存分配失败，新结点无法创建" << endl;
		return false;
	}
	newNode->m_next = p_move->m_next;
	if (p_move->m_next != NULL)
	{
		p_move->m_next->m_prior = newNode;
	}
	newNode->m_prior = p_move;
	p_move->m_next = newNode;
	this->length++;
	return true;
}

template<typename datatype>
bool doubleLink<datatype>::InsertNode(datatype data)				//向双向链表中添加一个元素
{
	doubleNode<datatype>* p_move = head;
	while (p_move->m_next != NULL)
	{
		p_move = p_move->m_next;
	}
	if (p_move->m_next == NULL)
	{
		p_move->m_data = data;
		doubleNode<datatype>* newNode = new doubleNode<datatype>(NULL);
		p_move->m_next = newNode;
		newNode->m_prior = p_move;
		newNode->m_next = NULL;
		this->length++;
		return true;
	}
	else 
	{
		doubleNode<datatype>* newNode = new doubleNode<datatype>(data);
		p_move->m_next = newNode;
		newNode->m_prior = p_move;
		newNode->m_next = NULL;
		this->length++;
		return true;
	}
}

template<typename datatype>
bool doubleLink<datatype>::DeleteNode(int n)			//删除第n个结点的数据
{
	if (n<1 || n>this->length)
	{
		cout << "非法输入" << endl;
		return false;
	}
	doubleNode<datatype>* p_move = head, * p_delete;
	for (int i = 1; i < n; i++)
	{
		p_move = p_move->m_next;
	}
	//删除结点
	p_delete = p_move;
	p_move->m_prior->m_next = p_delete->m_next;
	p_move->m_next->m_prior = p_delete->m_prior;
	delete p_delete;
	this->length--;
	return true;
}

template<typename datatype>
int doubleLink<datatype>::FindData(datatype data)		//寻找给定数值的结点，若不存在，则返回-1
{
	doubleNode<datatype>* p_move = head;
	if (p_move->m_next == NULL)
	{
		cout << "当前链表为空链表" << endl;
		return -1;
	}
	int pos = 1;
	while (p_move->m_data != data)
	{
		p_move = p_move->m_next;
		pos++;
	}
	return pos;
}