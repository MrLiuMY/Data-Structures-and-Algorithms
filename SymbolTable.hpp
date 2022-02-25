#pragma once
#include <iostream>
using namespace std;

template<typename Keytype, typename Valuetype> class SymbolTable;

template<typename Keytype,typename Valuetype>
class SymbolTableNode
{
public:
	SymbolTableNode(Keytype key,Valuetype value,SymbolTableNode<Keytype,Valuetype> *nextnode)
	{
		this->m_key = key;
		this->m_value = value;
		this->next = nextnode;
	}
	SymbolTableNode()
	{
		this->next = NULL;
	}

	Keytype m_key;
	Valuetype m_value;
	SymbolTableNode<Keytype,Valuetype>* next;
	friend class SymbolTable<Keytype, Valuetype>;
};

template<typename Keytype, typename Valuetype>
class SymbolTable
{
public:
	SymbolTable();
	Valuetype Get(Keytype key);			//根据键值，找对应的值
	void Put(Keytype key, Valuetype val);			//向符号表中插入一对键值
	void Delete(Keytype key);			//删除键值为key的键值对
	int Size();				//获取符号表的大小
private:
	SymbolTableNode<Keytype,Valuetype>* head;
	int N;
};



template<typename Keytype, typename Valuetype>
SymbolTable<Keytype, Valuetype>::SymbolTable()
{
	head = new SymbolTableNode<Keytype, Valuetype>();
	N = 0;
}


template<typename Keytype, typename Valuetype>
Valuetype SymbolTable<Keytype, Valuetype>::Get(Keytype key)//根据键值，找对应的值
{
	SymbolTableNode<Keytype, Valuetype>* n = head;
	while (n->next != NULL)
	{
		n = n->next;
		if (n->m_key == key)
			return n->m_value;
	}
	cout << "没有这个元素" << endl;
}


template<typename Keytype, typename Valuetype>
void SymbolTable<Keytype, Valuetype>::Put(Keytype key, Valuetype val)//向符号表中插入一对键值
{
	SymbolTableNode<Keytype, Valuetype>* n = head;
	while (n->next != NULL)
	{
		n = n->next;
		if (n->m_key == key)
		{
			n->m_value = val;
			return;
		}
	}
	SymbolTableNode<Keytype, Valuetype>* oldFrist = head->next;
	SymbolTableNode<Keytype, Valuetype>* newFirst = new SymbolTableNode<Keytype, Valuetype>(key, val, oldFrist);
	head->next = newFirst;
	N++;
}


template<typename Keytype, typename Valuetype>
void SymbolTable<Keytype, Valuetype>::Delete(Keytype key)//删除键值为key的键值对
{
	SymbolTableNode<Keytype, Valuetype>* n = head;
	SymbolTableNode<Keytype, Valuetype>* deletenode = NULL;
	while (n->next != NULL)
	{
		if (n->next->m_key == key)
		{
			deletenode = n->next;
			n->next = deletenode->next;
			N--;
			free(deletenode);
			return;
		}
		n = n->next;
	}
}


template<typename Keytype, typename Valuetype>
int SymbolTable<Keytype, Valuetype>::Size()	//获取符号表的大小
{
	return N;
}