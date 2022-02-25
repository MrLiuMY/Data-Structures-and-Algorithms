#pragma once

#include <iostream>
using namespace std;

template<typename IndexMaxMinPriorityQueueType>
class IndexMaxMinPriorityQueue
{
public:
	IndexMaxMinPriorityQueue(int capacity, int m_type);
	int DelMaxMin();//删除堆中最大最小的元素，并返回这个最大的元素
	void Insert(int i,IndexMaxMinPriorityQueueType data);//向堆中插入一个元素
	int Size();
	bool IsEmpty();
	bool Contains(int k);//判断k对应的元素是否存在
	void ChangeItem(int i, IndexMaxMinPriorityQueueType data);//把与索引i关联的元素修改为data
	int MaxMinIndex();//最小元素关联的索引
	void DeleteIndexItem(int i);//删除索引i关联的元素
private:
	bool LessAndLarg(int i, int j);//判断堆中索引i处的元素是否小于或大于索引j处的元素
	void Exch(int i, int j);//交换堆中i索引和j索引的值.
	void Swim(int k);//使用上浮算法，使索引k处的元素能在堆中处于一个正确的位置
	void Sink(int k);//使用下沉算法，使索引k处的元素能在堆中处于一个正确的位置

private:
	IndexMaxMinPriorityQueueType* array;//用来储存元素的数组
	int* pq;//保存每个元素在array数组中的索引，pq数组需要堆排序
	int* qp;//保存qp的逆序，pq的值作为索引，pq的索引作为值
	int N;
	int max_size;
	int m_type;
};


template<typename IndexMaxMinPriorityQueueType>
IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::IndexMaxMinPriorityQueue(int capacity, int m_type)
{
	this->max_size = 10;
	if (capacity >= 10)
		this->max_size = capacity;
	array = new IndexMaxMinPriorityQueueType[max_size+1];
	pq = new int[max_size + 1];
	qp = new int[max_size + 1];
	for (int i = 0; i < max_size + 1; i++)
	{
		qp[i] = -1;//默认情况下，qp逆序中不保存任何索引
	}
	N = 0;
	this->m_type = 1;
	if (m_type == 1 || m_type == 2)
	{
		this->m_type = m_type;
	}
}

template<typename IndexMaxMinPriorityQueueType>
bool IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::LessAndLarg(int i, int j)
{
	if (this->m_type == 1)
		return pq[i] < pq[j];
	else if (this->m_type == 2)
		return pq[i] > pq[j];
	else
		return pq[i] < pq[j];
}



template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::Exch(int i, int j)
{
	//先交换pq数组中的值
	int tmp = pq[i];
	pq[i] = pq[j];
	pq[j] = tmp;

	//更新qp数组中的值
	qp[pq[i]] = i;
	qp[pq[j]] = j;
}


template<typename IndexMaxMinPriorityQueueType>
int IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::DelMaxMin()
{
	//找到items中最小元素的索引 
	int minIndex = pq[1]; 
	//交换pq中索引1处的值和N处的值 
	Exch(1, N); 
	//删除qp中索引pq[N]处的值 
	qp[pq[N]] = -1;
	//删除pq中索引N处的值 
	pq[N] = -1; 
	//删除items中的最小元素 
	//array[minIndex] = NULL; 
	//元素数量-1
	N--; 
	//对pq[1]做下沉，让堆有序 
	Sink(1); 
	return minIndex;
}


template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::Insert(int i,IndexMaxMinPriorityQueueType data)
{
	//如果索引i处已经存在了元素，则不让插入 
	if (this->Contains(i)) 
	{ 
		//throw new RuntimeException("该索引已经存在"); 
		return;
	}
	//个数+1 
	N++; 
	//把元素存放到items数组中 
	array[i] = data; 
	//使用pq存放i这个索引 
	pq[N] = i; 
	//在qp的i索引处存放N 
	qp[i] = N; 
	//上浮items[pq[N]],让pq堆有序 
	Swim(N);

}


template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::Swim(int k)
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


template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::Sink(int k)
{
	while (2 * k < N || 2 * k == N)
	{
		int maxminchild;
		if (2 * k + 1 < N)//存在右子结点
		{
			if (this->LessAndLarg(2 * k, 2 * k + 1))
				maxminchild = 2 * k + 1;
			else
				maxminchild = 2 * k;
		}
		else
		{
			maxminchild = 2 * k;
		}
		if (this->LessAndLarg(k, maxminchild)) break;
		this->Exch(k, maxminchild);
		k = maxminchild;
	}
}

template<typename IndexMaxMinPriorityQueueType>
int IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::Size()
{
	return N;
}


template<typename IndexMaxMinPriorityQueueType>
bool IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::IsEmpty()
{
	return N == 0;
}

template<typename IndexMaxMinPriorityQueueType>
bool IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::Contains(int k)//判断k对应的元素是否存在
{
	return qp[k] != -1;
}

template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::ChangeItem(int i, IndexMaxMinPriorityQueueType data)//把与索引i关联的元素修改为data
{
	//修改items数组中索引i处的值为t 
	array[i] = data; 
	//找到i在pq中的位置 
	int k = qp[i]; 
	//对pq[k]做下沉，让堆有序 
	Sink(k); 
	//对pq[k]做上浮，让堆有序 
	Swim(k);
}

template<typename IndexMaxMinPriorityQueueType>
int IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::MaxMinIndex()//最小元素关联的索引
{
	//pq的索引1处，存放的是最小元素在array中的索引
	return pq[1];
}

template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::DeleteIndexItem(int i)//删除索引i关联的元素
{
	//找出i在pq中的索引
	int k = qp[i];
	//把pq中索引k处的值和索引N处的值交换
	Exch(k, N);
	//删除qp中索引pq[N]处的值
	qp[pq[N]] = -1; 
	//删除pq中索引N处的值 
	pq[N] = -1; 
	//删除items中索引i处的值 
	//array[i] = NULL; 
	//元素数量-1
	N--; 
	//对pq[k]做下沉，让堆有序
	Sink(k); 
	//对pq[k]做上浮，让堆有序 
	Swim(k);
}

