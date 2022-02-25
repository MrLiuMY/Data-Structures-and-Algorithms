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
	bool isStackEmpty();				//判断栈顶是否为空，是返回true，否返回false
	int GetStackSize();				//获取栈中元素个数
	T popStack();				//弹出栈顶元素
	void pushStack(T data);			//向栈中压入元素data


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
bool Stack<T>::isStackEmpty()				//判断栈顶是否为空，是返回true，否返回false
{
	return num == 0;
}

template<typename T>
int Stack<T>::GetStackSize()				//获取栈中元素个数
{
	return num;
}

template<typename T>
T Stack<T>::popStack()				//弹出栈顶元素
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
void Stack<T>::pushStack(T data)			//向栈中压入元素data
{
	StackNode<T>* oldNext = head->next;
	StackNode<T>* node = new StackNode<T>(data, oldNext);
	head->next = node;
	num++;
}


