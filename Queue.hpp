#pragma once
#include <iostream>
using namespace std;

template<typename T> class Queue;//����

template<typename T>
class QueueNode
{
public:
	QueueNode()
	{
		this->next = NULL;
	}
	QueueNode(T item, QueueNode<T>* next)
	{
		this->data = item;
		this->next = next;
	}

	T data;
	QueueNode* next;
	friend class Queue<T>;
};

template<typename T> 
class Queue
{
public:
	Queue();
	bool isEmpty();			//�ж��Ƿ�Ϊ��
	int size();				//��ȡ����Ԫ�ظ���
	T dequeue();			//�Ӷ������ó�һ��Ԫ��
	void enqueue(T t);		//�������в���һ��Ԫ��

public:
	QueueNode<T>* head;
	int num;
	QueueNode<T>* last;
};

template<typename T>
Queue<T>::Queue()
{
	head = new QueueNode<T>();
	last = NULL;
	num = 0;
}

template<typename T>
bool Queue<T>::isEmpty()			//�ж��Ƿ�Ϊ��
{
	return num == 0;
}

template<typename T>
int Queue<T>::size()				//��ȡ����Ԫ�ظ���
{
	return num;
}

template<typename T>
T Queue<T>::dequeue()			//�Ӷ������ó�һ��Ԫ��
{
	if (isEmpty())
	{
		cout << "�ն��У�û��Ҫ�����" << endl;
	}
	QueueNode<T>* oldfirst = head->next;
	QueueNode<T>* deletenode = oldfirst;
	head->next = oldfirst->next;
	num--;
	if (isEmpty())
	{
		last = NULL;
	}
	return oldfirst->data;
	free(deletenode);
}

template<typename T>
void Queue<T>::enqueue(T t)		//�������в���һ��Ԫ��
{
	if (last == NULL)
	{
		last = new QueueNode<T>(t, NULL);
		head->next = last;
	}
	else
	{
		//QueueNode<T>* newlast = new QueueNode<T>(t, NULL);
		//last->next = newlast;
		//last = newlast;
		QueueNode<T>* oldlast = last;
		last = new QueueNode<T>(t, NULL);
		oldlast->next = last;
	}
	num++;
}