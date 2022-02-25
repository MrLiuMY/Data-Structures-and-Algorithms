//˳���
#pragma once
#include <iostream>
using namespace std;

template<typename Type>
class SeqList
{
public:
	SeqList(size_t sz = INIT_SIZE);			//���캯������ʼ��˳���
	~SeqList();			//��������������˳���
	bool isFull()const;			//�ж�˳����Ƿ�������const��ʾ�����������޸�class�ĳ�Ա
	bool isEmpty()const;			//�ж�˳����Ƿ�Ϊ��
	void InsertSeqListAtEnd(const Type data);			//��˳��������������
	void InsertSeqListAtHead(const Type data);			//��ͷ������������
	void InsertSeqList(int pos, const Type data);      //��˳����в���������
	void TraverseSeqList();				//����˳���
	void DeleteSeqListEnd();			//ɾ��˳���β��Ԫ��
	void DeleteSeqListHead();			//ɾ��˳���ͷ��Ԫ��
	void DeleteSeqListPos(int pos);              //ɾ��ָ��λ�õ�ֵ
	void DeleteSeqListElem(Type data);			//��ֵɾ��Ԫ��
	void DeleteAll();                    //ɾ������Ԫ��
	int GetElemByElem(Type data);		//�鿴˳������Ƿ��в��ҵ�ֵ,����λ��
	Type GetElemByIndex(int pos);			//�����±����˳����е�Ԫ��
	int GetLength();                //��ȡ˳���ĳ���
	void SeqListReserv();			//��ת˳���
	void SeqListSort();			//��˳�������

public:
	enum { INIT_SIZE = 8 };
	Type* base;						//˳���Ļ���ַ
	int capacity;				//˳���������С
	int size;					//��ǰԪ������
};

template<typename Type>
SeqList<Type>::SeqList(size_t sz)//����ռ�
{
	capacity = sz > INIT_SIZE ? sz : INIT_SIZE;
	base = new Type[capacity];
	size = 0;
}

template<typename Type>
SeqList<Type>::~SeqList()      //����˳���
{
	delete[] base;  //ɾ������ַָ��
}

template<typename Type>
bool SeqList<Type>::isFull()const		//�ж�˳����Ƿ�������const��ʾ�����������޸�class�ĳ�Ա
{
	return size >= capacity;
}

template<typename Type>
bool SeqList<Type>::isEmpty()const			//�ж�˳����Ƿ�Ϊ��
{
	return size == 0;
}

template<typename Type>
void SeqList<Type>::InsertSeqListAtEnd(const Type data)			//��˳��������������
{
	if (isFull())
	{
		cout << "˳������������ܲ��룡" << endl;
		return;
	}
	base[size++] = data;
}

template<typename Type>
void SeqList<Type>::InsertSeqListAtHead(const Type data)		//��ͷ������������
{
	if (isFull())
	{
		cout << "˳������������ܲ��룡" << endl;
		return;
	}
	for (int i = size; i > 0; --i)
	{
		base[i] = base[i - 1];
	}
	base[0] = data;
	size++;
}

template<typename Type>
void SeqList<Type>::InsertSeqList(int pos, const Type data)     //��˳����в���������
{
	if (pos<0 || pos>size)
	{
		cout << "Ҫ�����λ�÷Ƿ�!" << endl;
		return;
	}
	if (isFull())
	{
		cout << "˳������������ܲ��룡" << endl;
		return;
	}
	for (int i = size; i > pos; i--)
	{
		base[i] = base[i - 1];
	}
	base[pos] = data;
	size++;
}

template<typename Type>
void SeqList<Type>::TraverseSeqList()				//����˳���
{
	for (int i = 0; i < size; i++)
	{
		cout << base[i] << " ";
	}
	cout << endl;
}

template<typename Type>
void SeqList<Type>::DeleteSeqListEnd()			//ɾ��˳���β��Ԫ��
{
	size = size - 1;
}

template<typename Type>
void SeqList<Type>::DeleteSeqListHead()			//ɾ��˳���ͷ��Ԫ��
{
	for (int i = 0; i < size; i++)
	{
		base[i] = base[i + 1];
	}
	size--;
}

template<typename Type>
void SeqList<Type>::DeleteSeqListPos(int pos)              //ɾ��ָ��λ�õ�ֵ
{
	for (int i = pos; i < size; i++)
	{
		base[i] = base[i + 1];
	}
	size--;
}

template<typename Type>
void SeqList<Type>::DeleteSeqListElem(Type data)			//��ֵɾ��Ԫ��
{
	int pos = GetElemByElem(data);
	if (pos == -1)
	{
		cout << "ɾ��Ԫ�ز�����" << endl;
		return;
	}
	else
	{
		for (int i = pos; i < size; i++)
		{
			base[i] = base[i + 1];
		}
		size--;
	}
}

template<typename Type>
void SeqList<Type>::DeleteAll()                    //ɾ������Ԫ��
{
	while (size)
	{
		base[size--] = NULL;
	}
}

template<typename Type>
int SeqList<Type>::GetElemByElem(Type data)		//�鿴˳������Ƿ��в��ҵ�ֵ
{
	for (int i = 0; i < size; i++)
	{
		if (base[i] == data)
			return i;
	}
	return -1;
}

template<typename Type>
Type SeqList<Type>::GetElemByIndex(int pos)			//�����±����˳����е�Ԫ��
{
	return base[pos];
}

template<typename Type>
int SeqList<Type>::GetLength()                //��ȡ˳���ĳ���
{
	cout << size << endl;
	return size;
}

template<typename Type>
void SeqList<Type>::SeqListReserv()			//��ת˳���
{
	int m = size - 1;
	int end = size;
	for (int i = 0; i < (m / 2); ++i)
	{
		int temp = base[i];
		base[i] = base[end - 1];
		base[end - 1] = temp;
		end--;
	}
}

template<typename Type>
void SeqList<Type>::SeqListSort()			//��˳�������
{
	int tmp;
	for (int i = 0; i <= size; i++)
	{
		for (int j = i + 1; j <= size - 1; j++)
		{
			if (base[i] > base[j])
			{
				tmp = base[j];
				base[j] = base[i];
				base[i] = tmp;
			}
		}
	}
}
