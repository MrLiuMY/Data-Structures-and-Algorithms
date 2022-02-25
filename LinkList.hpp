//��������
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

	int CreateLinkList(int n);          //����һ������
	int ClearLinkList();			//����һ������
	bool IsEmply();			//�ж��Ƿ�Ϊ�գ��վͷ���true���ǿվͷ���false
	int GetLength();			//��ȡ������
	int GetVal(int i);				//��ȡ�����i��Ԫ�ص�ֵ
	void InsertLinkList(int t);			//�������в���һ��ֵ
	int InsertLinkList(int data, int i);			//�������е�i��Ԫ��֮ǰ����һ��ֵ
	int DeleteLinklist(int i);				//ɾ�����������Ա��е�i������Ԫ��
	int indexOf(int val);			//�������Ա����״γ��ֵ�ָ��������Ԫ�ص�λ��ţ��������ڣ��򷵻�-1
	int TravalLinkList();			//��������
	void reverse();       //��ת����
	int getMid();			//���ÿ���ָ���ҳ��м�ֵ
	bool isCircle();        //l���ÿ���ָ���ж��Ƿ��л�
	Node* getEntrance();     //���ÿ���ָ���жϻ������


	Node* head;			//��¼�׽��
	int size;			//��¼����
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



int LinkList::CreateLinkList(int n)          //����һ������
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
		cout << "�������" << i << "������ֵ" << endl;
		cin >> pnew->data;
		ptemp->next = pnew;
		ptemp = pnew;
	}
	cout << "�������" << endl;
	return 0;
}



int LinkList::ClearLinkList()			//����һ������
{
	Node *ptemp;
	if (this->head == NULL)
	{
		cout << "�������Ϊ��" << endl;
		return -1;
	}
	while (this->head)
	{
		ptemp = head->next;
		free(head);
		head = ptemp;
	}
	cout << "�����������" << endl;
	return 0;
}


bool LinkList::IsEmply()			//�ж��Ƿ�Ϊ�գ��վͷ���true���ǿվͷ���false
{
	return this->size == 0;
}



int LinkList::GetLength()			//��ȡ������
{
	return this->size;
}



int LinkList::GetVal(int i)				//��ȡ�����i��Ԫ�ص�ֵ
{
	if (i >= this->size || i < 0)
	{
		cout << "�������������������Ⱑ������" << endl;
		return -1;
	}
	Node *ptemp=this->head->next;
	for (int index = 0; index < i; index++)
	{
		ptemp = ptemp->next;
	}
	return ptemp->data;
}


void LinkList::InsertLinkList(int t)			//�������в���һ��ֵ
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



int LinkList::InsertLinkList(int data, int i)			//�������е�i��Ԫ��֮ǰ����һ��ֵ
{
	if (i >= this->size || i < 0)
	{
		cout << "�������������������Ⱑ������" << endl;
		return -1;
	}
	Node *pre = head;
	for (int index = 0; index <= i - 1; index++) 
	{ 
		pre = pre->next; 
	}
	Node *cur = pre->next;//λ��i�Ľ��
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = cur;
	pre->next = newNode;
	this->size++;
}



int LinkList::DeleteLinklist(int i)				//ɾ�����������Ա��е�i������Ԫ��
{
	if (i >= this->size || i < 0)
	{
		cout << "�������������������Ⱑ������" << endl;
		return -1;
	}
	Node *pre = head;
	for (int index = 0; index <= i - 1; index++) 
	{ 
		pre = pre->next; 
	}
	//��ǰiλ�õĽ��
	Node *curr = pre->next;
	pre->next = curr->next;
	this->size--;
	return curr->data;
	free(curr);
}



int LinkList::indexOf(int val)			//�������Ա����״γ��ֵ�ָ��������Ԫ�ص�λ��ţ��������ڣ��򷵻�-1
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



int LinkList::TravalLinkList()			//��������
{
	Node *ptemp = this->head->next;
	if (this->head == NULL) {
		cout << "����Ϊ��" << endl;
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

void LinkList::reverse()      //��ת����
{
	if (head->next == NULL || head->next->next == NULL)
	{
		cout << "���ܷ�ת" << endl;   /*����Ϊ�ջ�ֻ��һ��Ԫ����ֱ�ӷ���*/
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

		/*��ʱqָ��ԭʼ�������һ��Ԫ�أ�Ҳ����ת�������ı�ͷԪ��*/
		head->next->next = NULL;  /*��������β*/
		head->next = p;           /*��������ͷ*/
	}
}


int LinkList::getMid()		//���ÿ���ָ���ҳ��м�ֵ
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

bool LinkList::isCircle()        //l���ÿ���ָ���ж��Ƿ��л�
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


Node* LinkList::getEntrance()    //���ÿ���ָ���жϻ������
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