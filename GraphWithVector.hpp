#pragma once
#include<iostream>
#include<vector>
using namespace std;

//ö�����ͣ�ͼ������ DG������ͼ��WDG����Ȩֵ������ͼ��
//UDG: ����ͼ��WUDG: ��Ȩֵ������ͼ
enum MGraphKind { DG, WDG, UDG, WUDG };

template<typename VertexType, typename VRType, typename InfoType>
class MGraph
{
public:
	MGraph(int vexNum, MGraphKind __kind) :vexnum(vexNum), arcnum(0), kind(__kind)
	{
		vvec = new VertexType[vexnum];
		arcs = new ArcCell * [vexnum];//��ά���鶯̬���䣨vexnum*vexnum)
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
		cout << "������ÿ������Ĺؼ��֣�" << endl;
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

	void CreateDG()//����һ������ͼ
	{
		Init();
		int vhead, vtail;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail)
		{
			arcnum++;
			arcs[vhead][vtail].adj = 1;
		}
	}

	void CreateWDG()//����һ����Ȩ����ͼ
	{
		Init();
		int vhead, vtail;
		InfoType w;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
		while (cin >> vhead >> vtail >> w)
		{
			arcnum++;
			arcs[vhead][vtail].adj = w;
		}
	}

	void CreateUDG()//����һ������ͼ
	{
		Init();
		int vhead, vtail;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail)
		{
			arcnum += 2;
			arcs[vhead][vtail].adj = 1;
			arcs[vtail][vhead].adj = 1;
		}
	}

	void CreateWUDG()//����һ����Ȩ����ͼ
	{
		Init();
		int vhead, vtail;
		InfoType w;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
		while (cin >> vhead >> vtail >> w)
		{
			arcnum += 2;
			arcs[vhead][vtail].adj = w;
			arcs[vtail][vhead].adj = w;
		}
	}

	void displayGraph()
	{
		cout << "�ܹ���" << vexnum << "�����㣬" << arcnum << "����" << endl;
		for (int i = 0; i < vexnum; i++)
		{
			cout << "��" << i + 1 << "�������ǣ�" << vvec[i] << "���ڵı��У�";
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
		VRType adj;//�����ӵ�֮���Ȩֵ
		InfoType info;
	};
	VertexType* vvec;//��������
	ArcCell** arcs;//�ڽӾ���
	int vexnum;//ͼ�Ľ�����
	int arcnum;//ͼ�ıߵĸ���
	MGraphKind kind;//ͼ������
};