#pragma once

#include <iostream>
using namespace std;

template<typename IndexMaxMinPriorityQueueType>
class IndexMaxMinPriorityQueue
{
public:
	IndexMaxMinPriorityQueue(int capacity, int m_type);
	int DelMaxMin();//ɾ�����������С��Ԫ�أ��������������Ԫ��
	void Insert(int i,IndexMaxMinPriorityQueueType data);//����в���һ��Ԫ��
	int Size();
	bool IsEmpty();
	bool Contains(int k);//�ж�k��Ӧ��Ԫ���Ƿ����
	void ChangeItem(int i, IndexMaxMinPriorityQueueType data);//��������i������Ԫ���޸�Ϊdata
	int MaxMinIndex();//��СԪ�ع���������
	void DeleteIndexItem(int i);//ɾ������i������Ԫ��
private:
	bool LessAndLarg(int i, int j);//�ж϶�������i����Ԫ���Ƿ�С�ڻ��������j����Ԫ��
	void Exch(int i, int j);//��������i������j������ֵ.
	void Swim(int k);//ʹ���ϸ��㷨��ʹ����k����Ԫ�����ڶ��д���һ����ȷ��λ��
	void Sink(int k);//ʹ���³��㷨��ʹ����k����Ԫ�����ڶ��д���һ����ȷ��λ��

private:
	IndexMaxMinPriorityQueueType* array;//��������Ԫ�ص�����
	int* pq;//����ÿ��Ԫ����array�����е�������pq������Ҫ������
	int* qp;//����qp������pq��ֵ��Ϊ������pq��������Ϊֵ
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
		qp[i] = -1;//Ĭ������£�qp�����в������κ�����
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
	//�Ƚ���pq�����е�ֵ
	int tmp = pq[i];
	pq[i] = pq[j];
	pq[j] = tmp;

	//����qp�����е�ֵ
	qp[pq[i]] = i;
	qp[pq[j]] = j;
}


template<typename IndexMaxMinPriorityQueueType>
int IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::DelMaxMin()
{
	//�ҵ�items����СԪ�ص����� 
	int minIndex = pq[1]; 
	//����pq������1����ֵ��N����ֵ 
	Exch(1, N); 
	//ɾ��qp������pq[N]����ֵ 
	qp[pq[N]] = -1;
	//ɾ��pq������N����ֵ 
	pq[N] = -1; 
	//ɾ��items�е���СԪ�� 
	//array[minIndex] = NULL; 
	//Ԫ������-1
	N--; 
	//��pq[1]���³����ö����� 
	Sink(1); 
	return minIndex;
}


template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::Insert(int i,IndexMaxMinPriorityQueueType data)
{
	//�������i���Ѿ�������Ԫ�أ����ò��� 
	if (this->Contains(i)) 
	{ 
		//throw new RuntimeException("�������Ѿ�����"); 
		return;
	}
	//����+1 
	N++; 
	//��Ԫ�ش�ŵ�items������ 
	array[i] = data; 
	//ʹ��pq���i������� 
	pq[N] = i; 
	//��qp��i���������N 
	qp[i] = N; 
	//�ϸ�items[pq[N]],��pq������ 
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
		if (2 * k + 1 < N)//�������ӽ��
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
bool IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::Contains(int k)//�ж�k��Ӧ��Ԫ���Ƿ����
{
	return qp[k] != -1;
}

template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::ChangeItem(int i, IndexMaxMinPriorityQueueType data)//��������i������Ԫ���޸�Ϊdata
{
	//�޸�items����������i����ֵΪt 
	array[i] = data; 
	//�ҵ�i��pq�е�λ�� 
	int k = qp[i]; 
	//��pq[k]���³����ö����� 
	Sink(k); 
	//��pq[k]���ϸ����ö����� 
	Swim(k);
}

template<typename IndexMaxMinPriorityQueueType>
int IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::MaxMinIndex()//��СԪ�ع���������
{
	//pq������1������ŵ�����СԪ����array�е�����
	return pq[1];
}

template<typename IndexMaxMinPriorityQueueType>
void IndexMaxMinPriorityQueue<IndexMaxMinPriorityQueueType>::DeleteIndexItem(int i)//ɾ������i������Ԫ��
{
	//�ҳ�i��pq�е�����
	int k = qp[i];
	//��pq������k����ֵ������N����ֵ����
	Exch(k, N);
	//ɾ��qp������pq[N]����ֵ
	qp[pq[N]] = -1; 
	//ɾ��pq������N����ֵ 
	pq[N] = -1; 
	//ɾ��items������i����ֵ 
	//array[i] = NULL; 
	//Ԫ������-1
	N--; 
	//��pq[k]���³����ö�����
	Sink(k); 
	//��pq[k]���ϸ����ö����� 
	Swim(k);
}

