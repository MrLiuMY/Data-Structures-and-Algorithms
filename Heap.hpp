#pragma once
#include <iostream>
using namespace std;
/*
堆的特性：
1.它是完全二叉树，除了树的最后一层结点不需要是满的，其它的每一层从左到右都是满的，
如果最后一层结点不是满的，那么要求左满右不满。

2.它通常用数组来实现。
具体方法就是将二叉树的结点按照层级顺序放入数组中，根结点在位置1，它的子结点在位置
2和3，而子结点的子结点则分别在位置4,5,6和7，以此类推。如果一个结点的位置为k，则它
的父结点的位置为[k/2],而它的两个子结点的位置则分别为2k和2k+1。这样，在不使用指针
的情况下，我们也可以通过计算数组的索引在树中上下移动：从a[k]向上一层，就令k等于
k/2,向下一层就令k等于2k或2k+1。

 3.每个结点都大于等于它的两个子结点。这里要注意堆中仅仅规定了每个结点大于等于它的
 两个子结点，但这两个子结点的顺序并没有做规定，跟我们之前学习的二叉查找树是有区别
 的。
*/

template<typename ArrayType>
class Heap
{
public:
	Heap(int capacity);//创建容量为capac的heap对象
	bool Less(int i, int j);//判断堆中索引i处的元素是否小于索引j处的元素
	void Exch(int i, int j);//交换堆中i索引和j索引的值
	ArrayType DelMax();//删除堆中最大的元素，并返回这个最大的元素
	void Insert(ArrayType data);//向堆中插入一个元素
	void Swim(int k);//使用上浮算法，使索引k处的元素能在堆中处于一个正确的位置
	void Sink(int k);//使用下沉算法，使索引k处的元素能在堆中处于一个正确的位置
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
		if (2 * k + 1 < N)//存在右子结点
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
