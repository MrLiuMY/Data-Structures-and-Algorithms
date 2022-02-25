#pragma once
#include <iostream>
using namespace std;

class UF
{
public:
	UF(int N);//初始化并查集，以整数标识(0,N-1)个结点
	int Count();//获取当前并查集中的数据有多少个分组
	bool Connected(int p, int q);//判断并查集中元素p和元素q是否在同一分组中
	int Find(int p);//元素p所在分组的标识符
	void Union(int p, int q);//把p元素所在分组和q元素所在分组合并
private:
	int* eleAndGroup;//记录结点元素和该元素所在分组的标识
	int count;//记录并查集中数据的分组个数
};

UF::UF(int N)//初始化并查集，以整数标识(0,N-1)个结点
{
	this->count = N;
	eleAndGroup = new int[N];
	for (int i = 0; i < N; i++)
	{
		eleAndGroup[i] = i;
	}
}
int UF::Count()//获取当前并查集中的数据有多少个分组
{
	return count;
}
bool UF::Connected(int p, int q)//判断并查集中元素p和元素q是否在同一分组中
{
	return Find(p) == Find(q);
}
int UF::Find(int p)//元素p所在分组的标识符
{
	return eleAndGroup[p];
}
void UF::Union(int p, int q)//把p元素所在分组和q元素所在分组合并
{
	//如果p和q已经在同一个分组中，则无需合并； 
	if (Connected(p,q))
	{ 
		return; 
	}
	//如果p和q不在同一个分组，则只需要将p元素所在组的所有的元素的组标识符修改为q元素所在组的标识 符即可 
	int pGroup = Find(p); 
	int qGroup = Find(q); 
	int N = count;
	for (int i = 0; i < N; i++) 
	{ 
		if (eleAndGroup[i]==pGroup)
		{ 
			eleAndGroup[i]=qGroup; 
		} 
	}
	//分组数量-1 
	count--;
}
