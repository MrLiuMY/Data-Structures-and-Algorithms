#pragma once

#include <iostream>
using namespace std;

template<typename MaxMinPriorityQueueType>
class MaxMinPriorityQueue
{
public:
	MaxMinPriorityQueue(int capacity,int m_type);
	MaxMinPriorityQueueType DelMaxMin();//删除堆中最大的元素，并返回这个最大的元素
	void Insert(MaxMinPriorityQueueType data);//向堆中插入一个元素
	int Size();
	bool isEmpty();
private:
	bool LessAndLarg(int i, int j);//判断堆中索引i处的元素是否小于或大于索引j处的元素
	void Exch(int i, int j);//交换堆中i索引和j索引的值.
	void Swim(int k);//使用上浮算法，使索引k处的元素能在堆中处于一个正确的位置
	void Sink(int k);//使用下沉算法，使索引k处的元素能在堆中处于一个正确的位置

private:
	MaxMinPriorityQueueType* array;
	int N;
	int max_size;
	int m_type;
};


template<typename MaxMinPriorityQueueType>
MaxMinPriorityQueue<MaxMinPriorityQueueType>::MaxMinPriorityQueue(int capacity,int m_type)
{
	this->max_size = 10;
	if (capacity >= 10)
		this->max_size = capacity;
	array = new MaxMinPriorityQueueType[max_size];
	N = 0;
	this->m_type = 1;
	if (m_type == 1 || m_type == 2)
	{
		this->m_type = m_type;
	}
}

template<typename MaxMinPriorityQueueType>
bool MaxMinPriorityQueue<MaxMinPriorityQueueType>::LessAndLarg(int i, int j)
{
	if (this->m_type == 1)
		return array[i] < array[j];
	if (this->m_type == 2)
		return array[i] > array[j];
}



template<typename MaxMinPriorityQueueType>
void MaxMinPriorityQueue<MaxMinPriorityQueueType>::Exch(int i, int j)
{
	MaxMinPriorityQueueType temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}


template<typename MaxMinPriorityQueueType>
MaxMinPriorityQueueType MaxMinPriorityQueue<MaxMinPriorityQueueType>::DelMaxMin()
{
	MaxMinPriorityQueueType max_num = array[1];
	this->Exch(1, N);
	//delete(array[N]);
	N--;
	this->Sink(1);
	return max_num;
}


template<typename MaxMinPriorityQueueType>
void MaxMinPriorityQueue<MaxMinPriorityQueueType>::Insert(MaxMinPriorityQueueType data)
{
	array[++N] = data;
	this->Swim(N);
}


template<typename MaxMinPriorityQueueType>
void MaxMinPriorityQueue<MaxMinPriorityQueueType>::Swim(int k)
{
	while (k > 1)
	{
		if (this->LessAndLarg(k / 2, k))
		{
			this->Exch(k / 2, k);
		}
		k = k / 2;
	}
}


template<typename MaxMinPriorityQueueType>
void MaxMinPriorityQueue<MaxMinPriorityQueueType>::Sink(int k)
{
	while (2 * k < N || 2 * k == N)
	{
		int maxchild;
		if (2 * k + 1 < N)//存在右子结点
		{
			if (this->LessAndLarg(2 * k, 2 * k + 1))
				maxchild = 2 * k + 1;
			else
				maxchild = 2 * k;
		}
		else
		{
			maxchild = 2 * k;
		}
		if (!this->LessAndLarg(k, maxchild)) break;
		this->Exch(k, maxchild);
		k = maxchild;
	}
}

template<typename MaxMinPriorityQueueType>
int MaxMinPriorityQueue<MaxMinPriorityQueueType>::Size()
{
	return N;
}


template<typename MaxMinPriorityQueueType>
bool MaxMinPriorityQueue<MaxMinPriorityQueueType>::isEmpty()
{
	return N == 0;
}