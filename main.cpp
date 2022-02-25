#include "SequenceList.hpp"
#include "LinkList.hpp"
#include "TwoWayLinkList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "SymbolTable.hpp"
#include "BinaryTree.hpp"
#include "TestPaperFolding.hpp"
#include "Heap.hpp"
#include "MaxMinPriorityQueue.hpp"
#include "IndexMaxMinPriorityQueue.hpp"
#include "RedBlackTree.hpp"
#include "UF.hpp"
#include "GraphWithVector.hpp"
#include "GraphWithList.hpp"
#include <iostream>
#include <string>
using namespace std;

void TestSequenceList();			 //����˳���
void TestLinkList();				 //���Ե�������
void TestTwoWayLinkList();			 //����˫������
void TestJoseph();					 //���԰�����Լɪ��
void TestStack();					 //����ջ
void TestisMatch();					 //���԰���������ƥ��
void Testcaculate();				 //���԰������沨�����ʽ��ֵ
void TestQueue();					 //���Զ���
void TestSymbolTable();				 //���Է��ű�
void TestBinaryTree();				 //���Զ����������
void TestPaperFolding();		     //���԰�������ֽ����
void TestHead();					 //���Զ�
void TestMaxMinPriorityQueue();		 //���������С���ȶ���
void TestIndexMaxMinPriorityQueue(); //�����������ȶ���??����Ӧ��û���󣬵�û���
void TestRedBlackTree();			 //���Ժ����
void TestUF();						 //���Բ����????
void TestGraphWithVector();			 //�����ڽӾ���ʵ��ͼ
void TestGraphWithList();		     //�����ڽӱ�ʵ��ͼ




int main()
{
	TestGraphWithList();
	system("pause");
	return 0;
}




///////////////////////////////////////////////
//����˳���
///////////////////////////////////////////////
void TestSequenceList()
{
	//������
	//3 2 1 5 10 9 8
	//2 1 10
	//
	//.....................................
	//2
	//...................................
	//4
	//7
	//8 9 10 5 1 2 3
	//1 2 3 5 8 9 10
	SeqList<int> mylist(100);
	mylist.InsertSeqListAtEnd(10);
	mylist.InsertSeqListAtEnd(9);
	mylist.InsertSeqListAtEnd(8);
	mylist.InsertSeqListAtHead(1);
	mylist.InsertSeqListAtHead(2);
	mylist.InsertSeqListAtHead(3);
	mylist.InsertSeqList(3, 5);
	mylist.TraverseSeqList();

	mylist.DeleteSeqListEnd();
	mylist.DeleteSeqListHead();
	mylist.DeleteSeqListPos(2);
	mylist.DeleteSeqListElem(9);
	mylist.TraverseSeqList();

	mylist.DeleteAll();
	mylist.TraverseSeqList();

	mylist.InsertSeqListAtEnd(10);
	mylist.InsertSeqListAtEnd(9);
	mylist.InsertSeqListAtEnd(8);
	mylist.InsertSeqListAtHead(1);
	mylist.InsertSeqListAtHead(2);
	mylist.InsertSeqListAtHead(3);
	mylist.InsertSeqList(3, 5);

	cout << "....................................." << endl;
	cout << mylist.GetElemByIndex(1) << endl;
	cout << "..................................." << endl;
	cout << mylist.GetElemByElem(10) << endl;

	mylist.GetLength();
	mylist.SeqListReserv();
	mylist.TraverseSeqList();

	mylist.SeqListSort();
	mylist.TraverseSeqList();
}



///////////////////////////////////////////////
//���Ե�������
///////////////////////////////////////////////
void TestLinkList()
{
	//��������1 2 3 4 5 
	LinkList list;
	list.CreateLinkList(5);
	list.TravalLinkList();//���1 2 3 4 5
	cout << list.getMid() << endl;   ///���3
	list.reverse();
	list.TravalLinkList();//���5 4 3 2 1
	list.DeleteLinklist(0);//���2 3 4 5 
	list.TravalLinkList();
	cout << list.GetLength() << endl;//���4
	cout << list.GetVal(1) << endl;//���3
	cout << list.indexOf(2) << endl;;//���0
	list.InsertLinkList(6);//���2 3 4 5 6
	list.TravalLinkList();
	list.InsertLinkList(3, 2);//���2 3 3 4 5 6
	list.TravalLinkList();
	if (!list.IsEmply()) cout << "no" << endl;  //���no
	list.TravalLinkList();
}



///////////////////////////////////////////////
//����˫������
///////////////////////////////////////////////
void TestTwoWayLinkList()		 //����˫������
{
	doubleLink<int> Link;
	Link.InsertNode(11);
	Link.InsertNode(22);
	Link.InsertNode(33);
	Link.InsertNode(44);
	Link.InsertNode(55);
	for (int i = 1; i <= 5; i++)
	{
		cout << Link.GetData(i) << " ";
	}
	cout << endl;
	//���11 22 33 44 55
	Link.CleardoubleLink();
	Link.GetData(1);
	//����Ƿ�λ��
	Link.InsertNode(11);
	Link.InsertNode(22);
	Link.InsertNode(33);
	Link.InsertNode(44);
	Link.InsertNode(55);
	if (!Link.IsEmpty()) cout << "�ǿ�" << endl;//����ǿ�
	cout << Link.Getlength() << endl;//���5
	Link.InsertNode(25, 3);
	for (int i = 1; i <= 6; i++)
	{
		cout << Link.GetData(i) << " ";
	}
	cout << endl;
	//���11 22  33 25 44 55
	Link.DeleteNode(2);
	for (int i = 1; i <= 5; i++)
	{
		cout << Link.GetData(i) << " ";
	}
	cout << endl;
	cout << endl;
	//���11  33 25 44 55
	cout << Link.FindData(55) << endl;//���5
}


//////////////////////////////////////////////
//����Լɪ��
//////////////////////////////////////////////
/*��˵������һ�����£���������ռ���������غ�39 ����̫����Լɪ���������Ѷ㵽һ�����У�
39����̫�˾�����Ը��Ҳ��Ҫ������ץ�������Ǿ�����һ����ɱ��ʽ��41�����ų�һ��ԲȦ����һ��
�˴�1��ʼ��������������������˱�����3����ô����˾ͱ�����ɱ��Ȼ������������һ��������
��1��ʼ������ֱ�������˶���ɱ����Ϊֹ��Ȼ��Լɪ����������Ѳ�������ӡ����ǣ�Լɪ��Ҫ��
�������ȼ�װ��ӣ������������Լ������ڵ�16�����31��λ�ã��Ӷ��ӹ����ⳡ������Ϸ ��*/
void TestJoseph()				 //����Լɪ��
{
	//����һ��ѭ������
	Node* head = NULL;
	Node* pre = NULL;
	for (int i = 1; i <= 41; i++)
	{
		if (i == 1)
		{
			head = new Node;
			head->data = i;
			head->next = NULL;
			pre = head;
			continue;
		}
		Node* node = new Node;
		node->data = i;
		node->next = NULL;
		pre->next = node;
		pre = node;
		if (i == 41)
		{
			pre->next = head;
		}
	}
	//ʹ��count����¼��ǰ����ֵ
	int count = 0;
	//��������ÿѭ��һ�Σ�count++
	Node* n = head;
	Node* before = NULL;
	Node* dele = NULL;
	while (n != n->next)
	{
		//�ж�count��ֵ�������3�����������ɾ�������㲢��ӡ��ǰ����ֵ����count��Ϊ0
		count++;
		if (count == 3)
		{
			dele = n;
			before->next = n->next;
			cout << n->data << " -> ";
			count = 0;
			n = n->next;
			free(dele);
		}
		else
		{
			before = n;
			n = n->next;
		}
	}
	//��ӡ���һ����
	cout << n->data << "����˳ɹ����" << endl;
}



///////////////////////////////////////////////
//����ջ
///////////////////////////////////////////////
void TestStack()				 //����ջ
{
	Stack<string> mystack;
	mystack.pushStack("a");
	mystack.pushStack("b");
	mystack.pushStack("c");
	mystack.pushStack("d");
	cout << mystack.GetStackSize() << endl;
	cout << mystack.popStack() << endl;
	cout << mystack.popStack() << endl;
	cout << mystack.popStack() << endl;
	cout << mystack.popStack() << endl;
	cout << mystack.GetStackSize() << endl;
}



///////////////////////////////////////////////
//���Զ���
///////////////////////////////////////////////

void TestQueue()				 //���Զ���
{
	Queue<string> myqueue;
	myqueue.enqueue("a");
	myqueue.enqueue("b");
	myqueue.enqueue("c");
	myqueue.enqueue("d");
	cout << myqueue.size() << endl;
	//cout << myqueue.head->next->next->data << endl;
	cout << myqueue.dequeue() << endl;
	cout << myqueue.dequeue() << endl;
	cout << myqueue.dequeue() << endl;
	cout << myqueue.dequeue() << endl;
	cout << myqueue.size() << endl;
}


///////////////////////////////////////////////
//���԰���������ƥ��
///////////////////////////////////////////////
void TestisMatch()			 //���԰���������ƥ��
{
	string str = "(�Ϻ�(����)())";
	//1������һ��ջ�����洢������
	Stack<string> mystring;
	//2���������ұ����ַ������õ�ÿһ���ַ�
	for (unsigned int i = 0; i < str.size(); i++)
	{
		string currchar = str[i] + "";
		//3���жϸ��ַ��ǲ��������ţ�����ǣ�����ջ�д洢
		if (currchar == "(")
		{
			mystring.pushStack(currchar);
		}
		else if (currchar == ")")//4���жϸ��ַ��ǲ��������ţ�������ǣ�������һ��ѭ��
		{
			//5��������ַ��������ţ����ջ�е���һ��Ԫ��t
			string t = mystring.popStack();
			//6���ж�Ԫ��t�Ƿ�Ϊnull��������ǣ���֤���ж�Ӧ��������
			if (t != "(")
			{
				cout << "��ƥ��" << endl;
			}
		}
	}
	//7��ѭ���������ж�ջ�л���û��ʣ��������ţ�����У���ƥ�䣬���û�У���ƥ��
	if (mystring.GetStackSize() == 0)
		cout << "ƥ��" << endl;
	else
		cout << "��ƥ��" << endl;
}

///////////////////////////////////////////////
//���԰������沨�����ʽ��ֵ
///////////////////////////////////////////////
void Testcaculate()			 //���԰������沨�����ʽ��ֵ
{
	string notation[] = { "3", "17", "15", "-", "*","18", "6","/","+" };
	Stack<int> oprands;
	for (int i = 0; i < 9; i++)
	{
		string curr = notation[i];
		int o1;
		int o2;
		int result;
		if (curr == "+")
		{
			o1 = oprands.popStack();
			o2 = oprands.popStack();
			result = o1 + o2;
			oprands.pushStack(result);
		}
		else if (curr == "-")
		{
			o1 = oprands.popStack();
			o2 = oprands.popStack();
			result = o2 - o1;
			oprands.pushStack(result);
		}
		else if (curr == "*")
		{
			o1 = oprands.popStack();
			o2 = oprands.popStack();
			result = o1 * o2;
			oprands.pushStack(result);
		}
		else if (curr == "/")
		{
			o1 = oprands.popStack();
			o2 = oprands.popStack();
			result = o2 / o1;
			oprands.pushStack(result);
		}
		else
		{
			oprands.pushStack(stoi(curr));
		}
	}
	int ret = oprands.popStack();
	cout << ret << endl;
}





///////////////////////////////////////////////
//���Է��ű�
///////////////////////////////////////////////
void TestSymbolTable()			 //���Է��ű�
{
	SymbolTable<int, string> st;
	st.Put(1, "����");
	st.Put(3, "����");
	st.Put(5, "����");
	cout << st.Size() << endl;
	st.Put(1, "����");
	cout << st.Get(1) << endl;
	cout << st.Size() << endl;
	st.Delete(1);
	cout << st.Size() << endl;
	cout << st.Get(3) << endl;
}




///////////////////////////////////////////////
//���Զ��������
///////////////////////////////////////////////
//��������������������������������������������������
//�������������ڸ��ڵ㴦��һ��0�����ǹ��캯����ʼ������
void TestBinaryTree()			 //���Զ��������
{
	//BinaryTree<int, string> bt(100,"nima",NULL,NULL);
	BinaryTree<int, string> bt;
	bt.Put(5, "����");
	bt.Put(7, "����");
	bt.Put(8, "����");
	bt.Put(4, "����");
	bt.Put(2, "����");
	bt.Put(1, "����");
	bt.Put(3, "����");
	bt.Put(6, "����");
	bt.Put(9, "����");
	cout << bt.Size() << endl;
	cout << bt.Get(1) << endl;
	cout << bt.Get(2) << endl;
	cout << bt.Get(3) << endl;
	cout << bt.Get(4) << endl;
	cout << bt.Get(5) << endl;
	cout << bt.Get(6) << endl;
	cout << bt.Get(7) << endl;
	cout << bt.Get(8) << endl;
	cout << bt.Get(9) << endl;
	cout << bt.Max() << endl;
	//bt.Delete(0);

	cout << ".....................ǰ�����............." << endl;
	vector<int> myvec = bt.preErgodic();
	cout << myvec.size() << endl;
	for (unsigned int i = 0; i < myvec.size(); i++)
	{
		cout << myvec[i] << bt.Get(myvec[i]) << endl;
	}

	cout << ".....................zhong�����............." << endl;
	Queue<int> myvec1 = bt.midErgodic();
	cout << myvec1.size() << endl;
	cout << myvec1.dequeue() << endl;
	cout << bt.Get(myvec1.dequeue()) << endl;
	cout << myvec1.dequeue() << endl;
	cout << myvec1.dequeue() << endl;
	cout << myvec1.dequeue() << endl;
	cout << myvec1.dequeue() << endl;
	cout << myvec1.dequeue() << endl;
	cout << myvec1.dequeue() << endl;
	cout << myvec1.dequeue() << endl;
	//cout << myvec1.dequeue() << endl;



	cout << ".....................hou �����............." << endl;
	Queue<int> myvec2 = bt.afterErgodic();
	cout << myvec2.size() << endl;
	cout << myvec2.dequeue() << endl;
	cout << myvec2.dequeue() << endl;
	cout << myvec2.dequeue() << endl;
	cout << myvec2.dequeue() << endl;
	cout << myvec2.dequeue() << endl;
	cout << myvec2.dequeue() << endl;
	cout << myvec2.dequeue() << endl;
	cout << myvec2.dequeue() << endl;
	cout << myvec2.dequeue() << endl;
	//cout << myvec2.dequeue() << endl;

	cout << ".....................ceng�����............." << endl;
	Queue<int> myvec3 = bt.layerErgodic();
	cout << myvec3.size() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << myvec3.dequeue() << endl;
	cout << "������Ϊ" << endl;
	cout << bt.maxDepth() << endl;
}


///////////////////////////////////////////////
//���԰�������ֽ����
///////////////////////////////////////////////
//���һ��ֽ�����ŷ��������ϣ�Ȼ���ֽ�����±����Ϸ�����1�Σ�ѹ���ۺۺ�չ������ʱ 
//�ۺ��ǰ���ȥ�ģ����ۺ�ͻ��ķ���ָ��ֽ���ı��档�����ֽ�����±����Ϸ���������2 
//�Σ�ѹ���ۺۺ�չ������ʱ�������ۺۣ����ϵ������������ۺۡ����ۺۺ����ۺۡ�
//����һ ���������N������ֽ�������±����Ϸ���������N�Σ�����ϵ��´�ӡ�����ۺ۵�
//���� ���磺N = 1ʱ����ӡ�� down��N = 2ʱ����ӡ�� down down up

void TestPaperFolding()         //���԰�������ֽ����
{
	PaperFoldingNode* tree = createTree(2);
	printTree(tree);
}

///////////////////////////////////////////////
//���Զ�
///////////////////////////////////////////////
void TestHead()				 //���Զ�
{
	Heap<string> myheap(20);
	myheap.Insert("S");
	myheap.Insert("G");
	myheap.Insert("I");
	myheap.Insert("E");
	myheap.Insert("N");
	myheap.Insert("H");
	myheap.Insert("O");
	myheap.Insert("A");
	myheap.Insert("T");
	myheap.Insert("P");
	myheap.Insert("R");
	cout << myheap.Size() << endl;
	string del;
	for (int i = 0; i < 11; i++)
	{
		del = myheap.DelMax();
		cout << del << " , ";
	}
	cout << endl;
}



///////////////////////////////////////////////
//���������С���ȶ���
///////////////////////////////////////////////
void TestMaxMinPriorityQueue()  //���������С���ȶ���
{
	MaxMinPriorityQueue<int> maxminpq(20, 2);
	int arr[] = { 1,2,58,6,4,5,25,14,62,22,11 };
	for (int i = 0; i < 11; i++)
	{
		maxminpq.Insert(arr[i]);
	}
	cout << maxminpq.Size() << endl;
	int dels;
	for (int i = 0; i < 11; i++)
	{
		dels = maxminpq.DelMaxMin();
		cout << dels << " , ";
	}
}

///////////////////////////////////////////////
//�����������ȶ���
///////////////////////////////////////////////
void TestIndexMaxMinPriorityQueue() //�����������ȶ���
{
	//string arr[] = { "S", "O", "R", "T", "E", "X", "A", "M", "P", "L", "E" };
	//IndexMaxMinPriorityQueue<string> indexMaxMinPQ(20, 1);
	//for (int i = 0; i < 11; i++)
	//{
	//	indexMaxMinPQ.Insert(i, arr[i]);
	//}
	//cout << indexMaxMinPQ.Size() << endl;
	//cout << indexMaxMinPQ.MaxMinIndex() << endl;
	//indexMaxMinPQ.ChangeItem(0, "Z");
	//int minindex = -1;
	//while (!indexMaxMinPQ.IsEmpty())
	//{
	//	minindex = indexMaxMinPQ.DelMaxMin();
	//	cout << minindex << " + ";
	//}
	IndexMaxMinPriorityQueue<string> indexMaxMinPQ(20, 2);
	indexMaxMinPQ.Insert(0, "A");
	indexMaxMinPQ.Insert(1, "C");
	indexMaxMinPQ.Insert(2, "F");
	indexMaxMinPQ.ChangeItem(2, "B");
	while (!indexMaxMinPQ.IsEmpty())
	{
		int inedx = indexMaxMinPQ.DelMaxMin();
		cout << inedx << " ";
	}
	cout << endl;

}
///////////////////////////////////////////////
//���Ժ����
///////////////////////////////////////////////
void TestRedBlackTree()			 //���Ժ����
{
	RedBlackTree<int, string> mybt;
	mybt.Put(4, "����");
	mybt.Put(1, "����");
	mybt.Put(3, "����");
	mybt.Put(5, "����");
	cout << mybt.Size() << endl;
	mybt.Put(1, "laosan");
	cout << mybt.Get(1) << endl;
	cout << mybt.Get(3) << endl;
	cout << mybt.Get(4) << endl;
	cout << mybt.Get(5) << endl;
	cout << mybt.Size() << endl;
}

///////////////////////////////////////////////
//���Բ����
///////////////////////////////////////////////
void TestUF()						 //���Բ����
{


}


///////////////////////////////////////////////
//�����ڽӾ���ʵ��ͼ
///////////////////////////////////////////////
void TestGraphWithVector()			 //�����ڽӾ���ʵ��ͼ
{
	cout << "������һ��������ѡ�񹹽�ͼ�����ͣ�" << endl;
	cout << "1����������ͼ" << endl;
	cout << "2�������Ȩ����ͼ" << endl;
	cout << "3����������ͼ" << endl;
	cout << "4�������Ȩ����ͼ" << endl;
	int ch;
	cin >> ch;
	switch (ch)//���Ҫ��case���涨���������Ҫ������������{}
	{
	case 1:
	{
		cout << "��������ͼ��" << endl;
		MGraph<char, int, int> udgGraph(8, UDG);
		udgGraph.Create();
		udgGraph.displayGraph();
		break;
	}
	case 2:
	{
		cout << "�����Ȩ����ͼ��" << endl;
		MGraph<char, int, int> wudgGraph(9, WUDG);
		wudgGraph.Create();
		wudgGraph.displayGraph();
		break;
	}
	case 3:
	{
		cout << "��������ͼ��" << endl;
		MGraph<char, int, int> dgGraph(6, DG);
		dgGraph.Create();
		dgGraph.displayGraph();
		break;
	}
	case 4:
	{
		cout << "�����Ȩ����ͼ��" << endl;
		MGraph<char, int, int> wdgGraph(6, WDG);//����6������
		wdgGraph.Create();//ÿ����һ�飬����
		wdgGraph.displayGraph();
		break;
	}
	}
}

///////////////////////////////////////////////
//�����ڽӱ�ʵ��ͼ
///////////////////////////////////////////////
void TestGraphWithList()		     //�����ڽӱ�ʵ��ͼ
{
	cout << "������һ��������ѡ�񹹽�ͼ�����ͣ�" << endl;
	cout << "1����������ͼ" << endl;
	cout << "2�������Ȩ����ͼ" << endl;
	cout << "3����������ͼ" << endl;
	cout << "4�������Ȩ����ͼ" << endl;
	int ch;
	cin >> ch;
	switch (ch)//���Ҫ��case���涨���������Ҫ������������{}
	{
	case 1:
	{
		cout << "��������ͼ��" << endl;
		ALGraph<char, int> udgGraph(8, ALUDG);
		udgGraph.Create();
		udgGraph.displayGraph();
		cout << "....................................." << endl;
		udgGraph.DFS();
		cout << "....................................." << endl;
		udgGraph.BFS();
		cout << "....................................." << endl;
		break;
	}
	case 2:
	{
		cout << "�����Ȩ����ͼ��" << endl;
		ALGraph<char, int> wudgGraph(9, ALWUDG);
		wudgGraph.Create();
		wudgGraph.displayGraph();
		break;
	}
	case 3:
	{
		cout << "��������ͼ��" << endl;
		ALGraph<char, int> dgGraph(6, ALDG);
		dgGraph.Create();
		dgGraph.displayGraph();
		break;
	}
	case 4:
	{
		cout << "�����Ȩ����ͼ��" << endl;
		ALGraph<char, int> wdgGraph(6, ALWDG);
		wdgGraph.Create();
		wdgGraph.displayGraph();
		break;
	}
	}
}








