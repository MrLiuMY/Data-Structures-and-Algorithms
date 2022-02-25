//˫������
#pragma once
#include <iostream>
using namespace std;


template<typename datatype> class doubleLink;//˫����������
//˫���������ݽṹ����
template<typename datatype>
class doubleNode
{
public:
	//�޲������캯������ָ���ʼ��ΪNULL
	doubleNode()
	{
		this->m_prior = NULL;
		this->m_next = NULL;
	}
	//���������캯������ʼ����������ָ����
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
	doubleNode<datatype>* m_prior;//ָ��ǰ����ָ��
	doubleNode<datatype>* m_next;//ָ������ָ��
	datatype m_data;//�����������
	friend class doubleLink<datatype>;//������Ԫ��
};

//˫��������
template<typename datatype> 
class doubleLink
{
public:
	doubleLink();		//˫�������캯������������µ�ͷ���
	doubleLink(doubleNode<datatype>* node);		//˫�������캯������������µ�ͷ���
	~doubleLink();		//˫���������������������ɾ��ͷ���
	void CleardoubleLink();		//���˫������
	bool IsEmpty();			//�ж������Ƿ�Ϊ��
	int Getlength();		//��ȡ˫������ĳ���
	datatype GetData(int n);			//��ȡ��n����������
	bool InsertNode(datatype data, int n);			//�ڵ�n��������datatype���͵�data
	bool InsertNode(datatype data);				//��˫�����������һ��Ԫ��
	bool DeleteNode(int n);			//ɾ����n����������
	int FindData(datatype data);		//Ѱ�Ҹ�����ֵ�Ľ�㣬�������ڣ��򷵻�-1
	
public:
	doubleNode<datatype>* head;			//ͷָ��
	int length;			//����ĳ���
};

template<typename datatype>
doubleLink<datatype>::doubleLink()		//˫�������캯������������µ�ͷ���
{
	head = new doubleNode<datatype>();
	this->length = 0;
}

template<typename datatype>
doubleLink<datatype>::doubleLink(doubleNode<datatype>* node)		//˫�������캯������������µ�ͷ���
{
	head = node;
	this->length = 0;
}

template<typename datatype>
doubleLink<datatype>::~doubleLink()		//˫���������������������ɾ��ͷ���
{
	delete head;
}

template<typename datatype>
void doubleLink<datatype>::CleardoubleLink()		//���˫������
{
	doubleNode<datatype>* p_move = head->m_next, * p_middle;//�����α�ָ��
	while (p_move != NULL)//�ж�ͷָ�����Ľ��
	{
		p_middle = p_move;
		p_move = p_middle->m_next;//�α�ָ������м�ָ�������
		delete p_middle;//ɾ���м�ָ�룬��ɾ������Ľ��
	}
	head->m_next = NULL;//��ͷָ��ָ���
}

template<typename datatype>
bool doubleLink<datatype>::IsEmpty()			//�ж������Ƿ�Ϊ��,�շ���true���ǿշ���false
{
	return this->length == 0;
}

template<typename datatype>
int doubleLink<datatype>::Getlength()		//��ȡ˫������ĳ���
{
	doubleNode<datatype>* p_move = head->m_next;//�����α�ָ��
	int length = 0;
	while (p_move != NULL)
	{
		p_move = p_move->m_next;//�α�ָ�����
		length++;//����length
	}
	return length;
}

template<typename datatype>
datatype doubleLink<datatype>::GetData(int n)			//��ȡ��n����������
{
	if (n<1 || n>this->length)
	{
		cout << "����Ƿ�λ��" << endl;
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
bool doubleLink<datatype>::InsertNode(datatype data, int n)			//�ڵ�n��������datatype���͵�data
{
	if (n<1)
	{
		cout << "����Ƿ�λ��" << endl;
		return false;
	}
	doubleNode<datatype>* p_move = head;
	for (int i = 1; i < n; i++)
	{
		p_move = p_move->m_next;
		if (p_move == NULL && i <= n)
		{
			cout << "����λ����Ч" << endl;
			return false;
		}
	}
	doubleNode<datatype>* newNode = new doubleNode<datatype>(data);
	if (newNode == NULL)
	{
		cout << "�ڴ����ʧ�ܣ��½���޷�����" << endl;
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
bool doubleLink<datatype>::InsertNode(datatype data)				//��˫�����������һ��Ԫ��
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
bool doubleLink<datatype>::DeleteNode(int n)			//ɾ����n����������
{
	if (n<1 || n>this->length)
	{
		cout << "�Ƿ�����" << endl;
		return false;
	}
	doubleNode<datatype>* p_move = head, * p_delete;
	for (int i = 1; i < n; i++)
	{
		p_move = p_move->m_next;
	}
	//ɾ�����
	p_delete = p_move;
	p_move->m_prior->m_next = p_delete->m_next;
	p_move->m_next->m_prior = p_delete->m_prior;
	delete p_delete;
	this->length--;
	return true;
}

template<typename datatype>
int doubleLink<datatype>::FindData(datatype data)		//Ѱ�Ҹ�����ֵ�Ľ�㣬�������ڣ��򷵻�-1
{
	doubleNode<datatype>* p_move = head;
	if (p_move->m_next == NULL)
	{
		cout << "��ǰ����Ϊ������" << endl;
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