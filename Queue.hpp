#pragma once
#include <iostream>
using namespace std;

template<typename T> class Queue;//声明

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
	bool isEmpty();			//判断是否为空
	int size();				//获取队列元素个数
	T dequeue();			//从队列中拿出一个元素
	void enqueue(T t);		//往队列中插入一个元素

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
bool Queue<T>::isEmpty()			//判断是否为空
{
	return num == 0;
}

template<typename T>
int Queue<T>::size()				//获取队列元素个数
{
	return num;
}

template<typename T>
T Queue<T>::dequeue()			//从队列中拿出一个元素
{
	if (isEmpty())
	{
		cout << "空队列，没有要输出的" << endl;
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
void Queue<T>::enqueue(T t)		//往队列中插入一个元素
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