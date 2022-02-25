#pragma once
#include <iostream>
using namespace std;
/*
�ѵ����ԣ�
1.������ȫ�������������������һ���㲻��Ҫ�����ģ�������ÿһ������Ҷ������ģ�
������һ���㲻�����ģ���ôҪ�������Ҳ�����

2.��ͨ����������ʵ�֡�
���巽�����ǽ��������Ľ�㰴�ղ㼶˳����������У��������λ��1�������ӽ����λ��
2��3�����ӽ����ӽ����ֱ���λ��4,5,6��7���Դ����ơ����һ������λ��Ϊk������
�ĸ�����λ��Ϊ[k/2],�����������ӽ���λ����ֱ�Ϊ2k��2k+1���������ڲ�ʹ��ָ��
������£�����Ҳ����ͨ��������������������������ƶ�����a[k]����һ�㣬����k����
k/2,����һ�����k����2k��2k+1��

 3.ÿ����㶼���ڵ������������ӽ�㡣����Ҫע����н����涨��ÿ�������ڵ�������
 �����ӽ�㣬���������ӽ���˳��û�����涨��������֮ǰѧϰ�Ķ����������������
 �ġ�
*/

template<typename ArrayType>
class Heap
{
public:
	Heap(int capacity);//��������Ϊcapac��heap����
	bool Less(int i, int j);//�ж϶�������i����Ԫ���Ƿ�С������j����Ԫ��
	void Exch(int i, int j);//��������i������j������ֵ
	ArrayType DelMax();//ɾ����������Ԫ�أ��������������Ԫ��
	void Insert(ArrayType data);//����в���һ��Ԫ��
	void Swim(int k);//ʹ���ϸ��㷨��ʹ����k����Ԫ�����ڶ��д���һ����ȷ��λ��
	void Sink(int k);//ʹ���³��㷨��ʹ����k����Ԫ�����ڶ��д���һ����ȷ��λ��
	int Size();
private:
	ArrayType *array;
	int max_size;

	int N;
};


template<typename ArrayType>
Heap<ArrayType>::Heap(int capacity)
{
	this->max_size = 10;
	if (capacity >= 10)
		this->max_size = capacity;
	array = new ArrayType[max_size];
	N = 0;
}

template<typename ArrayType>
bool Heap<ArrayType>::Less(int i, int j)
{
	return array[i] < array[j];
}


template<typename ArrayType>
void Heap<ArrayType>::Exch(int i, int j)
{
	ArrayType temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}


template<typename ArrayType>
ArrayType Heap<ArrayType>::DelMax()
{
	ArrayType max_num = array[1];
	this->Exch(1, N);
	//delete(array[N]);
	N--;
	this->Sink(1);
	return max_num;
}


template<typename ArrayType>
void Heap<ArrayType>::Insert(ArrayType data)
{
	array[++N] = data;
	this->Swim(N);
}


template<typename ArrayType>
void Heap<ArrayType>::Swim(int k)
{
	while (k > 1)
	{
		if (this->Less(k / 2, k))
		{
			this->Exch(k / 2, k);
		}
		k = k / 2;
	}
}


template<typename ArrayType>
void Heap<ArrayType>::Sink(int k)
{
	while (2 * k < N || 2 * k == N)
	{
		int maxchild;
		if (2 * k + 1 < N)//�������ӽ��
		{
			if (this->Less(2 * k, 2 * k + 1))
				maxchild = 2 * k + 1;
			else
				maxchild = 2 * k;
		}
		else
		{
			maxchild = 2 * k;
		}
		if (!this->Less(k, maxchild)) break;
		this->Exch(k, maxchild);
		k = maxchild;
	}
}
template<typename ArrayType>
int Heap<ArrayType>::Size()
{
	return N;
}
