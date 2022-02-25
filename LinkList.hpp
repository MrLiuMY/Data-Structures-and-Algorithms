//单向链表
#pragma once

#include <iostream>
#include <string>
using namespace std;


class Node
{
public:
	int data;
	Node* next;
};


class LinkList
{
public:

	LinkList();
	~LinkList();

	int CreateLinkList(int n);          //创建一个链表
	int ClearLinkList();			//空置一个链表
	bool IsEmply();			//判断是否为空，空就返回true，非空就返回false
	int GetLength();			//获取链表长度
	int GetVal(int i);				//获取链表第i个元素的值
	void InsertLinkList(int t);			//向链表中插入一个值
	int InsertLinkList(int data, int i);			//向链表中第i个元素之前插入一个值
	int DeleteLinklist(int i);				//删除并返回线性表中第i个数据元素
	int indexOf(int val);			//返回线性表中首次出现的指定的数据元素的位序号，若不存在，则返回-1
	int TravalLinkList();			//遍历链表
	void reverse();       //反转链表
	int getMid();			//利用快慢指针找出中间值
	bool isCircle();        //l利用快慢指针判断是否有环
	Node* getEntrance();     //利用快慢指针判断环的入口


	Node* head;			//记录首结点
	int size;			//记录长度
};


LinkList::LinkList()
{
	head = new Node;
	head->data = 0;
	head->next = NULL;
	size = 0;
}



LinkList::~LinkList()
{
	delete head;
}



int LinkList::CreateLinkList(int n)          //创建一个链表
{
	if (n < 0) 
	{
		printf("error\n");
		return -1;
	}

	Node *ptemp = NULL;
	Node *pnew = NULL;

	this->size = n;
	ptemp = this->head;
	for (int i = 0; i < n; i++)
	{
		pnew = new Node;
		pnew->next = NULL;
		cout << "请输入第" << i << "个结点的值" << endl;
		cin >> pnew->data;
		ptemp->next = pnew;
		ptemp = pnew;
	}
	cout << "创建完成" << endl;
	return 0;
}



int LinkList::ClearLinkList()			//空置一个链表
{
	Node *ptemp;
	if (this->head == NULL)
	{
		cout << "链表本身就为空" << endl;
		return -1;
	}
	while (this->head)
	{
		ptemp = head->next;
		free(head);
		head = ptemp;
	}
	cout << "销毁链表完成" << endl;
	return 0;
}


bool LinkList::IsEmply()			//判断是否为空，空就返回true，非空就返回false
{
	return this->size == 0;
}



int LinkList::GetLength()			//获取链表长度
{
	return this->size;
}



int LinkList::GetVal(int i)				//获取链表第i个元素的值
{
	if (i >= this->size || i < 0)
	{
		cout << "？？？输入区间有问题啊？？？" << endl;
		return -1;
	}
	Node *ptemp=this->head->next;
	for (int index = 0; index < i; index++)
	{
		ptemp = ptemp->next;
	}
	return ptemp->data;
}


void LinkList::InsertLinkList(int t)			//向链表中插入一个值
{
	Node *n = head;
	while (n->next != NULL)
	{
		n = n->next;
	}
	Node *newNode = new Node;
	newNode->data = t;
	newNode->next = NULL;
	n->next = newNode;
	this->size++;
}



int LinkList::InsertLinkList(int data, int i)			//向链表中第i个元素之前插入一个值
{
	if (i >= this->size || i < 0)
	{
		cout << "？？？输入区间有问题啊？？？" << endl;
		return -1;
	}
	Node *pre = head;
	for (int index = 0; index <= i - 1; index++) 
	{ 
		pre = pre->next; 
	}
	Node *cur = pre->next;//位置i的结点
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = cur;
	pre->next = newNode;
	this->size++;
}



int LinkList::DeleteLinklist(int i)				//删除并返回线性表中第i个数据元素
{
	if (i >= this->size || i < 0)
	{
		cout << "？？？输入区间有问题啊？？？" << endl;
		return -1;
	}
	Node *pre = head;
	for (int index = 0; index <= i - 1; index++) 
	{ 
		pre = pre->next; 
	}
	//当前i位置的结点
	Node *curr = pre->next;
	pre->next = curr->next;
	this->size--;
	return curr->data;
	free(curr);
}



int LinkList::indexOf(int val)			//返回线性表中首次出现的指定的数据元素的位序号，若不存在，则返回-1
{
	Node *n = head;
	for (int i = 0; n->next != NULL; i++) 
	{ 
		n = n->next; 
		if (n->data==val) 
		{ 
			return i; 
		} 
	}
	return -1;
}



int LinkList::TravalLinkList()			//遍历链表
{
	Node *ptemp = this->head->next;
	if (this->head == NULL) {
		cout << "链表为空" << endl;
		return -1;
	}
	while (ptemp)
	{
		cout << ptemp->data << "->";
		ptemp = ptemp->next;
	}
	cout << "NULL" << endl;
	return 0;
}

void LinkList::reverse()      //反转链表
{
	if (head->next == NULL || head->next->next == NULL)
	{
		cout << "不能反转" << endl;   /*链表为空或只有一个元素则直接返回*/
	}
	else
	{
		Node* t = NULL;
		Node* p = head->next;
		Node* q = head->next->next;
		while (q != NULL)
		{
			t = q->next;
			q->next = p;
			p = q;
			q = t;
		}

		/*此时q指向原始链表最后一个元素，也是逆转后的链表的表头元素*/
		head->next->next = NULL;  /*设置链表尾*/
		head->next = p;           /*调整链表头*/
	}
}


int LinkList::getMid()		//利用快慢指针找出中间值
{
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}

bool LinkList::isCircle()        //l利用快慢指针判断是否有环
{
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}


Node* LinkList::getEntrance()    //利用快慢指针判断环的入口
{
	Node* slow = head;
	Node* fast = head;
	Node* temp = NULL;
	Node* ret = NULL;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			temp = head;
			continue;
		}
		if (temp != NULL)
		{
			temp = temp->next;
			if (temp == slow)
				return temp;
		}
	}
	return ret;
}