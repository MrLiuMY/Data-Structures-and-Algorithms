#pragma once
#include <iostream>
using namespace std;

class UF
{
public:
	UF(int N);//��ʼ�����鼯����������ʶ(0,N-1)�����
	int Count();//��ȡ��ǰ���鼯�е������ж��ٸ�����
	bool Connected(int p, int q);//�жϲ��鼯��Ԫ��p��Ԫ��q�Ƿ���ͬһ������
	int Find(int p);//Ԫ��p���ڷ���ı�ʶ��
	void Union(int p, int q);//��pԪ�����ڷ����qԪ�����ڷ���ϲ�
private:
	int* eleAndGroup;//��¼���Ԫ�غ͸�Ԫ�����ڷ���ı�ʶ
	int count;//��¼���鼯�����ݵķ������
};

UF::UF(int N)//��ʼ�����鼯����������ʶ(0,N-1)�����
{
	this->count = N;
	eleAndGroup = new int[N];
	for (int i = 0; i < N; i++)
	{
		eleAndGroup[i] = i;
	}
}
int UF::Count()//��ȡ��ǰ���鼯�е������ж��ٸ�����
{
	return count;
}
bool UF::Connected(int p, int q)//�жϲ��鼯��Ԫ��p��Ԫ��q�Ƿ���ͬһ������
{
	return Find(p) == Find(q);
}
int UF::Find(int p)//Ԫ��p���ڷ���ı�ʶ��
{
	return eleAndGroup[p];
}
void UF::Union(int p, int q)//��pԪ�����ڷ����qԪ�����ڷ���ϲ�
{
	//���p��q�Ѿ���ͬһ�������У�������ϲ��� 
	if (Connected(p,q))
	{ 
		return; 
	}
	//���p��q����ͬһ�����飬��ֻ��Ҫ��pԪ������������е�Ԫ�ص����ʶ���޸�ΪqԪ��������ı�ʶ ������ 
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
	//��������-1 
	count--;
}
