//顺序表
#pragma once
#include <iostream>
using namespace std;

template<typename Type>
class SeqList
{
public:
	SeqList(size_t sz = INIT_SIZE);			//构造函数，初始化顺序表
	~SeqList();			//析构函数，销毁顺序表
	bool isFull()const;			//判断顺序表是否已满，const表示函数不可以修改class的成员
	bool isEmpty()const;			//判断顺序表是否为空
	void InsertSeqListAtEnd(const Type data);			//向顺序表的最后插入数据
	void InsertSeqListAtHead(const Type data);			//在头部插入新数据
	void InsertSeqList(int pos, const Type data);      //向顺序表中插入新数据
	void TraverseSeqList();				//遍历顺序表
	void DeleteSeqListEnd();			//删除顺序表尾部元素
	void DeleteSeqListHead();			//删除顺序表头部元素
	void DeleteSeqListPos(int pos);              //删除指定位置的值
	void DeleteSeqListElem(Type data);			//按值删除元素
	void DeleteAll();                    //删除所有元素
	int GetElemByElem(Type data);		//查看顺序表中是否含有查找的值,返回位置
	Type GetElemByIndex(int pos);			//根据下标查找顺序表中的元素
	int GetLength();                //获取顺序表的长度
	void SeqListReserv();			//翻转顺序表
	void SeqListSort();			//对顺序表排序

public:
	enum { INIT_SIZE = 8 };
	Type* base;						//顺序表的基地址
	int capacity;				//顺序表容量大小
	int size;					//当前元素数量
};

template<typename Type>
SeqList<Type>::SeqList(size_t sz)//分配空间
{
	capacity = sz > INIT_SIZE ? sz : INIT_SIZE;
	base = new Type[capacity];
	size = 0;
}

template<typename Type>
SeqList<Type>::~SeqList()      //销毁顺序表
{
	delete[] base;  //删除基地址指针
}

template<typename Type>
bool SeqList<Type>::isFull()const		//判断顺序表是否已满，const表示函数不可以修改class的成员
{
	return size >= capacity;
}

template<typename Type>
bool SeqList<Type>::isEmpty()const			//判断顺序表是否为空
{
	return size == 0;
}

template<typename Type>
void SeqList<Type>::InsertSeqListAtEnd(const Type data)			//向顺序表的最后插入数据
{
	if (isFull())
	{
		cout << "顺序表已满，不能插入！" << endl;
		return;
	}
	base[size++] = data;
}

template<typename Type>
void SeqList<Type>::InsertSeqListAtHead(const Type data)		//在头部插入新数据
{
	if (isFull())
	{
		cout << "顺序表已满，不能插入！" << endl;
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
void SeqList<Type>::InsertSeqList(int pos, const Type data)     //向顺序表中插入新数据
{
	if (pos<0 || pos>size)
	{
		cout << "要插入的位置非法!" << endl;
		return;
	}
	if (isFull())
	{
		cout << "顺序表已满，不能插入！" << endl;
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
void SeqList<Type>::TraverseSeqList()				//遍历顺序表
{
	for (int i = 0; i < size; i++)
	{
		cout << base[i] << " ";
	}
	cout << endl;
}

template<typename Type>
void SeqList<Type>::DeleteSeqListEnd()			//删除顺序表尾部元素
{
	size = size - 1;
}

template<typename Type>
void SeqList<Type>::DeleteSeqListHead()			//删除顺序表头部元素
{
	for (int i = 0; i < size; i++)
	{
		base[i] = base[i + 1];
	}
	size--;
}

template<typename Type>
void SeqList<Type>::DeleteSeqListPos(int pos)              //删除指定位置的值
{
	for (int i = pos; i < size; i++)
	{
		base[i] = base[i + 1];
	}
	size--;
}

template<typename Type>
void SeqList<Type>::DeleteSeqListElem(Type data)			//按值删除元素
{
	int pos = GetElemByElem(data);
	if (pos == -1)
	{
		cout << "删除元素不存在" << endl;
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
void SeqList<Type>::DeleteAll()                    //删除所有元素
{
	while (size)
	{
		base[size--] = NULL;
	}
}

template<typename Type>
int SeqList<Type>::GetElemByElem(Type data)		//查看顺序表中是否含有查找的值
{
	for (int i = 0; i < size; i++)
	{
		if (base[i] == data)
			return i;
	}
	return -1;
}

template<typename Type>
Type SeqList<Type>::GetElemByIndex(int pos)			//根据下标查找顺序表中的元素
{
	return base[pos];
}

template<typename Type>
int SeqList<Type>::GetLength()                //获取顺序表的长度
{
	cout << size << endl;
	return size;
}

template<typename Type>
void SeqList<Type>::SeqListReserv()			//翻转顺序表
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
void SeqList<Type>::SeqListSort()			//对顺序表排序
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
