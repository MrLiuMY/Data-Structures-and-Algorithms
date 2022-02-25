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

void TestSequenceList();			 //测试顺序表
void TestLinkList();				 //测试单向链表
void TestTwoWayLinkList();			 //测试双向链表
void TestJoseph();					 //测试案例：约瑟夫环
void TestStack();					 //测试栈
void TestisMatch();					 //测试案例：括号匹配
void Testcaculate();				 //测试案例：逆波兰表达式求值
void TestQueue();					 //测试队列
void TestSymbolTable();				 //测试符号表
void TestBinaryTree();				 //测试二叉查找树？
void TestPaperFolding();		     //测试案例：折纸问题
void TestHead();					 //测试堆
void TestMaxMinPriorityQueue();		 //测试最大最小优先队列
void TestIndexMaxMinPriorityQueue(); //测试索引优先队列??代码应该没错误，但没理解
void TestRedBlackTree();			 //测试红黑树
void TestUF();						 //测试并查表????
void TestGraphWithVector();			 //测试邻接矩阵实现图
void TestGraphWithList();		     //测试邻接表实现图




int main()
{
	TestGraphWithList();
	system("pause");
	return 0;
}




///////////////////////////////////////////////
//测试顺序表
///////////////////////////////////////////////
void TestSequenceList()
{
	//输出结果
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
//测试单向链表
///////////////////////////////////////////////
void TestLinkList()
{
	//创建链表1 2 3 4 5 
	LinkList list;
	list.CreateLinkList(5);
	list.TravalLinkList();//输出1 2 3 4 5
	cout << list.getMid() << endl;   ///输出3
	list.reverse();
	list.TravalLinkList();//输出5 4 3 2 1
	list.DeleteLinklist(0);//输出2 3 4 5 
	list.TravalLinkList();
	cout << list.GetLength() << endl;//输出4
	cout << list.GetVal(1) << endl;//输出3
	cout << list.indexOf(2) << endl;;//输出0
	list.InsertLinkList(6);//输出2 3 4 5 6
	list.TravalLinkList();
	list.InsertLinkList(3, 2);//输出2 3 3 4 5 6
	list.TravalLinkList();
	if (!list.IsEmply()) cout << "no" << endl;  //输出no
	list.TravalLinkList();
}



///////////////////////////////////////////////
//测试双向链表
///////////////////////////////////////////////
void TestTwoWayLinkList()		 //测试双向链表
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
	//输出11 22 33 44 55
	Link.CleardoubleLink();
	Link.GetData(1);
	//输出非法位置
	Link.InsertNode(11);
	Link.InsertNode(22);
	Link.InsertNode(33);
	Link.InsertNode(44);
	Link.InsertNode(55);
	if (!Link.IsEmpty()) cout << "非空" << endl;//输出非空
	cout << Link.Getlength() << endl;//输出5
	Link.InsertNode(25, 3);
	for (int i = 1; i <= 6; i++)
	{
		cout << Link.GetData(i) << " ";
	}
	cout << endl;
	//输出11 22  33 25 44 55
	Link.DeleteNode(2);
	for (int i = 1; i <= 5; i++)
	{
		cout << Link.GetData(i) << " ";
	}
	cout << endl;
	cout << endl;
	//输出11  33 25 44 55
	cout << Link.FindData(55) << endl;//输出5
}


//////////////////////////////////////////////
//测试约瑟夫环
//////////////////////////////////////////////
/*传说有这样一个故事，在罗马人占领乔塔帕特后，39 个犹太人与约瑟夫及他的朋友躲到一个洞中，
39个犹太人决定宁愿死也不要被敌人抓到，于是决定了一个自杀方式，41个人排成一个圆圈，第一个
人从1开始报数，依次往后，如果有人报数到3，那么这个人就必须自杀，然后再由他的下一个人重新
从1开始报数，直到所有人都自杀身亡为止。然而约瑟夫和他的朋友并不想遵从。于是，约瑟夫要他
的朋友先假装遵从，他将朋友与自己安排在第16个与第31个位置，从而逃过了这场死亡游戏 。*/
void TestJoseph()				 //测试约瑟夫环
{
	//构建一个循环链表
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
	//使用count，记录当前报数值
	int count = 0;
	//遍历链表，每循环一次，count++
	Node* n = head;
	Node* before = NULL;
	Node* dele = NULL;
	while (n != n->next)
	{
		//判断count的值，如果是3，则从链表中删除这个结点并打印当前结点的值，把count置为0
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
	//打印最后一个人
	cout << n->data << "这号人成功存活" << endl;
}



///////////////////////////////////////////////
//测试栈
///////////////////////////////////////////////
void TestStack()				 //测试栈
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
//测试队列
///////////////////////////////////////////////

void TestQueue()				 //测试队列
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
//测试案例：括号匹配
///////////////////////////////////////////////
void TestisMatch()			 //测试案例：括号匹配
{
	string str = "(上海(长安)())";
	//1、创建一个栈用来存储左括号
	Stack<string> mystring;
	//2、从左往右遍历字符串，拿到每一个字符
	for (unsigned int i = 0; i < str.size(); i++)
	{
		string currchar = str[i] + "";
		//3、判断该字符是不是左括号，如果是，放入栈中存储
		if (currchar == "(")
		{
			mystring.pushStack(currchar);
		}
		else if (currchar == ")")//4、判断该字符是不是右括号，如果不是，继续下一次循环
		{
			//5、如果该字符是右括号，则从栈中弹出一个元素t
			string t = mystring.popStack();
			//6、判断元素t是否为null，如果不是，则证明有对应的左括号
			if (t != "(")
			{
				cout << "不匹配" << endl;
			}
		}
	}
	//7、循环结束后，判断栈中还有没有剩余的左括号，如果有，则不匹配，如果没有，则匹配
	if (mystring.GetStackSize() == 0)
		cout << "匹配" << endl;
	else
		cout << "不匹配" << endl;
}

///////////////////////////////////////////////
//测试案例：逆波兰表达式求值
///////////////////////////////////////////////
void Testcaculate()			 //测试案例：逆波兰表达式求值
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
//测试符号表
///////////////////////////////////////////////
void TestSymbolTable()			 //测试符号表
{
	SymbolTable<int, string> st;
	st.Put(1, "张三");
	st.Put(3, "李四");
	st.Put(5, "王五");
	cout << st.Size() << endl;
	st.Put(1, "老三");
	cout << st.Get(1) << endl;
	cout << st.Size() << endl;
	st.Delete(1);
	cout << st.Size() << endl;
	cout << st.Get(3) << endl;
}




///////////////////////////////////////////////
//测试二叉查找树
///////////////////////////////////////////////
//？？？？？？？？？？？？？？？？？？？？？？？？？
//遍历二叉树，在根节点处多一个0，考虑构造函数初始化问题
void TestBinaryTree()			 //测试二叉查找树
{
	//BinaryTree<int, string> bt(100,"nima",NULL,NULL);
	BinaryTree<int, string> bt;
	bt.Put(5, "王五");
	bt.Put(7, "张三");
	bt.Put(8, "三三");
	bt.Put(4, "二哈");
	bt.Put(2, "张三");
	bt.Put(1, "张三");
	bt.Put(3, "李四");
	bt.Put(6, "二哈");
	bt.Put(9, "王五");
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

	cout << ".....................前序遍历............." << endl;
	vector<int> myvec = bt.preErgodic();
	cout << myvec.size() << endl;
	for (unsigned int i = 0; i < myvec.size(); i++)
	{
		cout << myvec[i] << bt.Get(myvec[i]) << endl;
	}

	cout << ".....................zhong序遍历............." << endl;
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



	cout << ".....................hou 序遍历............." << endl;
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

	cout << ".....................ceng序遍历............." << endl;
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
	cout << "最大深度为" << endl;
	cout << bt.maxDepth() << endl;
}


///////////////////////////////////////////////
//测试案例：折纸问题
///////////////////////////////////////////////
//请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，压出折痕后展开。此时 
//折痕是凹下去的，即折痕突起的方向指向纸条的背面。如果从纸条的下边向上方连续对折2 
//次，压出折痕后展开，此时有三条折痕，从上到下依次是下折痕、下折痕和上折痕。
//给定一 个输入参数N，代表纸条都从下边向上方连续对折N次，请从上到下打印所有折痕的
//方向 例如：N = 1时，打印： down；N = 2时，打印： down down up

void TestPaperFolding()         //测试案例：折纸问题
{
	PaperFoldingNode* tree = createTree(2);
	printTree(tree);
}

///////////////////////////////////////////////
//测试堆
///////////////////////////////////////////////
void TestHead()				 //测试堆
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
//测试最大最小优先队列
///////////////////////////////////////////////
void TestMaxMinPriorityQueue()  //测试最大最小优先队列
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
//测试索引优先队列
///////////////////////////////////////////////
void TestIndexMaxMinPriorityQueue() //测试索引优先队列
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
//测试红黑树
///////////////////////////////////////////////
void TestRedBlackTree()			 //测试红黑树
{
	RedBlackTree<int, string> mybt;
	mybt.Put(4, "二哈");
	mybt.Put(1, "张三");
	mybt.Put(3, "李四");
	mybt.Put(5, "王五");
	cout << mybt.Size() << endl;
	mybt.Put(1, "laosan");
	cout << mybt.Get(1) << endl;
	cout << mybt.Get(3) << endl;
	cout << mybt.Get(4) << endl;
	cout << mybt.Get(5) << endl;
	cout << mybt.Size() << endl;
}

///////////////////////////////////////////////
//测试并查表
///////////////////////////////////////////////
void TestUF()						 //测试并查表
{


}


///////////////////////////////////////////////
//测试邻接矩阵实现图
///////////////////////////////////////////////
void TestGraphWithVector()			 //测试邻接矩阵实现图
{
	cout << "请输入一个整数，选择构建图的类型：" << endl;
	cout << "1、构造无向图" << endl;
	cout << "2、构造带权无向图" << endl;
	cout << "3、构造有向图" << endl;
	cout << "4、构造带权有向图" << endl;
	int ch;
	cin >> ch;
	switch (ch)//如果要在case里面定义变量，需要用括号括起来{}
	{
	case 1:
	{
		cout << "构造无向图：" << endl;
		MGraph<char, int, int> udgGraph(8, UDG);
		udgGraph.Create();
		udgGraph.displayGraph();
		break;
	}
	case 2:
	{
		cout << "构造带权无向图：" << endl;
		MGraph<char, int, int> wudgGraph(9, WUDG);
		wudgGraph.Create();
		wudgGraph.displayGraph();
		break;
	}
	case 3:
	{
		cout << "构造有向图：" << endl;
		MGraph<char, int, int> dgGraph(6, DG);
		dgGraph.Create();
		dgGraph.displayGraph();
		break;
	}
	case 4:
	{
		cout << "构造带权有向图：" << endl;
		MGraph<char, int, int> wdgGraph(6, WDG);//构造6个顶点
		wdgGraph.Create();//每三个一组，输入
		wdgGraph.displayGraph();
		break;
	}
	}
}

///////////////////////////////////////////////
//测试邻接表实现图
///////////////////////////////////////////////
void TestGraphWithList()		     //测试邻接表实现图
{
	cout << "请输入一个整数，选择构建图的类型：" << endl;
	cout << "1、构造无向图" << endl;
	cout << "2、构造带权无向图" << endl;
	cout << "3、构造有向图" << endl;
	cout << "4、构造带权有向图" << endl;
	int ch;
	cin >> ch;
	switch (ch)//如果要在case里面定义变量，需要用括号括起来{}
	{
	case 1:
	{
		cout << "构造无向图：" << endl;
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
		cout << "构造带权无向图：" << endl;
		ALGraph<char, int> wudgGraph(9, ALWUDG);
		wudgGraph.Create();
		wudgGraph.displayGraph();
		break;
	}
	case 3:
	{
		cout << "构造有向图：" << endl;
		ALGraph<char, int> dgGraph(6, ALDG);
		dgGraph.Create();
		dgGraph.displayGraph();
		break;
	}
	case 4:
	{
		cout << "构造带权有向图：" << endl;
		ALGraph<char, int> wdgGraph(6, ALWDG);
		wdgGraph.Create();
		wdgGraph.displayGraph();
		break;
	}
	}
}








