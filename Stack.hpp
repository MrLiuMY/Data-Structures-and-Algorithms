#pragma once
#include<iostream>
using namespace std;

template<typename T> class Stack;

template<typename T>
class StackNode
{
public:
	T data;
	StackNode<T>* next;

	StackNode()
	{
		this->next = NULL;
	}
	StackNode(T item, StackNode<T>* curr)
	{
		this->data = item;
		this->next = curr;
	}
	friend class Stack<T>;
};

template<typename T>
class Stack
{
public:
	Stack();
	bool isStackEmpty();				//�ж�ջ���Ƿ�Ϊ�գ��Ƿ���true���񷵻�false
	int GetStackSize();				//��ȡջ��Ԫ�ظ���
	T popStack();				//����ջ��Ԫ��
	void pushStack(T data);			//��ջ��ѹ��Ԫ��data


public:
	StackNode<T>* head;
	int num;
};


template<typename T>
Stack<T>::Stack()
{
	head = new StackNode<T>();
	num = 0;
}


template<typename T>
bool Stack<T>::isStackEmpty()				//�ж�ջ���Ƿ�Ϊ�գ��Ƿ���true���񷵻�false
{
	return num == 0;
}

template<typename T>
int Stack<T>::GetStackSize()				//��ȡջ��Ԫ�ظ���
{
	return num;
}

template<typename T>
T Stack<T>::popStack()				//����ջ��Ԫ��
{
	StackNode<T>* oldNext = head->next;
	StackNode<T>* deletenode = NULL;
	if (oldNext == NULL)
	{
		return NULL;
	}
	deletenode = head->next;
	head->next = deletenode->next;
	num--;
	return oldNext->data;
	free(deletenode);
}

template<typename T>
void Stack<T>::pushStack(T data)			//��ջ��ѹ��Ԫ��data
{
	StackNode<T>* oldNext = head->next;
	StackNode<T>* node = new StackNode<T>(data, oldNext);
	head->next = node;
	num++;
}


