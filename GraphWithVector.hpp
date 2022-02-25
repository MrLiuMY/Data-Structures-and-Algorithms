#pragma once
#include<iostream>
#include<vector>
using namespace std;

//枚举类型，图的种类 DG：有向图；WDG：带权值的有向图；
//UDG: 无向图；WUDG: 带权值的无向图
enum MGraphKind { DG, WDG, UDG, WUDG };

template<typename VertexType, typename VRType, typename InfoType>
class MGraph
{
public:
	MGraph(int vexNum, MGraphKind __kind) :vexnum(vexNum), arcnum(0), kind(__kind)
	{
		vvec = new VertexType[vexnum];
		arcs = new ArcCell * [vexnum];//二维数组动态分配（vexnum*vexnum)
		for (int i = 0; i < vexnum; i++)
		{
			arcs[i] = new ArcCell[vexnum];
		}
	}

	void Create()
	{
		switch (kind)
		{
		case DG:
			CreateDG();
			break;
		case WDG:
			CreateWDG();
			break;
		case UDG:
			CreateUDG();
			break;
		case WUDG:
			CreateWUDG();
			break;
		default:
			return;
		}
	}

	void Init()
	{
		cout << "请输入每个顶点的关键字：" << endl;
		VertexType val;
		for (int i = 0; i < vexnum; i++)
		{
			cin >> val;
			vvec[i] = val;
		}
		for (int i = 0; i < vexnum; i++)
		{
			ArcCell ac;
			ac.adj = 0;
			ac.info = NULL;
			for (int j = 0; j < vexnum; j++)
				arcs[i][j] = ac;
		}
	}

	void CreateDG()//构造一个有向图
	{
		Init();
		int vhead, vtail;
		cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
		while (cin >> vhead >> vtail)
		{
			arcnum++;
			arcs[vhead][vtail].adj = 1;
		}
	}

	void CreateWDG()//构造一个带权有向图
	{
		Init();
		int vhead, vtail;
		InfoType w;
		cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
		while (cin >> vhead >> vtail >> w)
		{
			arcnum++;
			arcs[vhead][vtail].adj = w;
		}
	}

	void CreateUDG()//构造一个无向图
	{
		Init();
		int vhead, vtail;
		cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
		while (cin >> vhead >> vtail)
		{
			arcnum += 2;
			arcs[vhead][vtail].adj = 1;
			arcs[vtail][vhead].adj = 1;
		}
	}

	void CreateWUDG()//构造一个带权无向图
	{
		Init();
		int vhead, vtail;
		InfoType w;
		cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
		while (cin >> vhead >> vtail >> w)
		{
			arcnum += 2;
			arcs[vhead][vtail].adj = w;
			arcs[vtail][vhead].adj = w;
		}
	}

	void displayGraph()
	{
		cout << "总共有" << vexnum << "个顶点，" << arcnum << "条边" << endl;
		for (int i = 0; i < vexnum; i++)
		{
			cout << "第" << i + 1 << "个顶点是：" << vvec[i] << "相邻的边有：";
			for (int j = 0; j < vexnum; j++)
			{
				if (arcs[i][j].adj != 0)
					cout << vvec[j] << "(" << arcs[i][j].adj << ")"<<" ==> ";
			}
			cout << " NULL ";
			cout << endl;
		}
	}

private:
	struct ArcCell
	{
		VRType adj;//两连接点之间的权值
		InfoType info;
	};
	VertexType* vvec;//顶点向量
	ArcCell** arcs;//邻接矩阵
	int vexnum;//图的结点个数
	int arcnum;//图的边的个数
	MGraphKind kind;//图的种类
};