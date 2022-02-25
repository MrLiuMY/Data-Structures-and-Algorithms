#pragma once
#include <iostream>
using namespace std;
//枚举类型，图的种类 ALDG：有向图；ALWDG：带权值的有向图；
//ALUDG: 无向图；ALWUDG: 带权值的无向图
enum ALGraphKind { ALDG, ALWDG, ALUDG, ALWUDG };

template<typename VertexType, typename InfoType>
class ALGraph
{
public:
	static const int MAX_VERTEX_NUM = 20;
	ALGraph(int verNum, ALGraphKind _kind) :vexnum(verNum), arcnum(0), kind(_kind)
	{
		//this->vexnum = verNum;
		//this->arcnum = 0;
		//this->kind = _kind;
		for (int i = 0; i < MAX_VERTEX_NUM; i++)
			vertices[i].firstarc = NULL;
	}
	void Create();
	void displayGraph();
	void DFS();//深度优先搜索？？
	void BFS();//广度优先搜索（类似于树的层次遍历）？？

private:
	void InitVertics();//初始化头列表
	void InsertArc(int vHead,int vTail,InfoType w);
	void CreateDG();//构造一个有向图
	void CreateWDG();//构造一个带权有向图
	void CreateUDG();//构造一个无向图
	void CreateWUDG();//构造一个带权值的无向图
	void DFS(int i, int* visited);
private:
	struct ArcNode//表结点
	{
		int adjvex;//该弧所指向的顶点的位置
		ArcNode* nextarc;//指向下一条弧的指针
		InfoType info;//该弧相关信息的指针
	};
	struct VNode//头结点
	{
		VertexType data;//顶点信息
		ArcNode* firstarc;//指向第一条依附在该顶点的弧的指针
	};

	VNode vertices[MAX_VERTEX_NUM];//头列表
	int vexnum; //图的当前顶点数
	int arcnum; //图的弧数
	ALGraphKind kind;//图的种类

};

template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::Create()
{
	switch (kind)
	{
	case ALDG://构造一个有向图
		CreateDG();
		break;
	case ALWDG://构造一个带权有向图
		CreateWDG();
		break;
	case ALUDG://构造一个无向图
		CreateUDG();
		break;
	case ALWUDG://构造一个带权无向图
		CreateWUDG();
		break;
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::displayGraph()
{
	for (int i = 0; i < vexnum; i++)
	{
		cout << "第" << i + 1 << "个顶点是：" << vertices[i].data<< "邻接表为：";
		ArcNode* arcNode = vertices[i].firstarc;
		while (arcNode)
		{
			cout << "->" << vertices[arcNode->adjvex].data << "(" << arcNode->info << ")";
			arcNode = arcNode->nextarc;
		}
		cout << endl;
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::InitVertics()//初始化头列表
{
	cout << "请输入" << this->vexnum << "个顶点的关键字：" << endl;
	VertexType val;
	for (int i = 0; i < vexnum; i++)
	{
		cin >> val;
		vertices[i].data = val;
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::InsertArc(int vHead, int vTail, InfoType w)
{
	ArcNode* newArcNode = new ArcNode;
	newArcNode->adjvex = vTail;
	newArcNode->nextarc = NULL;
	newArcNode->info = w;
	ArcNode* arcNode = vertices[vHead].firstarc;
	if (NULL == arcNode)
		vertices[vHead].firstarc = newArcNode;
	else
	{
		while (arcNode->nextarc != NULL)
		{
			arcNode = arcNode->nextarc;
		}
		arcNode->nextarc = newArcNode;
	}
	arcnum++;
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::CreateDG()//构造一个有向图
{
	InitVertics();
	int vhead, vtail;
	cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
	while (cin >> vhead >> vtail)
	{
		InsertArc(vhead, vtail, 0);
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::CreateWDG()//构造一个带权有向图
{
	InitVertics();
	int vhead, vtail;
	InfoType w;
	cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
	while (cin >> vhead >> vtail >> w)
	{
		InsertArc(vhead, vtail, w);
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::CreateUDG()//构造一个无向图
{
	InitVertics();
	int vhead, vtail;
	cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
	while (cin >> vhead >> vtail)
	{
		InsertArc(vhead, vtail, 0);
		InsertArc(vtail, vhead, 0);
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::CreateWUDG()//构造一个带权值的无向图
{
	InitVertics();
	int vhead, vtail;
	InfoType w;
	cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
	while (cin >> vhead >> vtail >> w)
	{
		InsertArc(vhead, vtail, w);
		InsertArc(vtail, vhead, w);
	}
}

template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::DFS(int i, int* visited)//深度优先搜索递归
{
	ArcNode* node;
	visited[i] = 1;
	cout << vertices[i].data << " ";
	node = vertices[i].firstarc;
	while (node != NULL)
	{
		if (!visited[node->adjvex])
			DFS(node->adjvex, visited);
		node = node->nextarc;
	}
}

template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::DFS()//深度优先搜索
{
	int visited[MAX_VERTEX_NUM];
	for (int i = 0; i < this->vexnum; i++)
		visited[i] = 0;
	cout << "DFS:";
	for (int i = 0; i < this->vexnum; i++)
	{
		if (!visited[i])
			DFS(i, visited);
	}
	cout << endl;
}

template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::BFS()//广度优先搜索（类似于树的层次遍历）
{
	int head = 0;
	int rear = 0;
	int queue[MAX_VERTEX_NUM];//
	int visited[MAX_VERTEX_NUM];//
	int i, j, k;
	ArcNode* node;
	for (i = 0; i < this->vexnum; i++)
	{
		visited[i] = 0;
	}
	cout << "BFS:" << " ";
	for (i = 0; i < this->vexnum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << vertices[i].data << " ";
			queue[rear++] = i;
		}
		while (head != rear)
		{
			j = queue[head++];
			node = vertices[j].firstarc;
			while (node != NULL)
			{
				k = node->adjvex;
				if (!visited[k])
				{
					visited[k] = 1;
					cout << vertices[k].data << " ";
					queue[rear++] = k;
				}
				node = node->nextarc;
			}
		}
	}
	cout << endl;
}

