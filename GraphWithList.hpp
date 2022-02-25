#pragma once
#include <iostream>
using namespace std;
//ö�����ͣ�ͼ������ ALDG������ͼ��ALWDG����Ȩֵ������ͼ��
//ALUDG: ����ͼ��ALWUDG: ��Ȩֵ������ͼ
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
	void DFS();//���������������
	void BFS();//����������������������Ĳ�α���������

private:
	void InitVertics();//��ʼ��ͷ�б�
	void InsertArc(int vHead,int vTail,InfoType w);
	void CreateDG();//����һ������ͼ
	void CreateWDG();//����һ����Ȩ����ͼ
	void CreateUDG();//����һ������ͼ
	void CreateWUDG();//����һ����Ȩֵ������ͼ
	void DFS(int i, int* visited);
private:
	struct ArcNode//����
	{
		int adjvex;//�û���ָ��Ķ����λ��
		ArcNode* nextarc;//ָ����һ������ָ��
		InfoType info;//�û������Ϣ��ָ��
	};
	struct VNode//ͷ���
	{
		VertexType data;//������Ϣ
		ArcNode* firstarc;//ָ���һ�������ڸö���Ļ���ָ��
	};

	VNode vertices[MAX_VERTEX_NUM];//ͷ�б�
	int vexnum; //ͼ�ĵ�ǰ������
	int arcnum; //ͼ�Ļ���
	ALGraphKind kind;//ͼ������

};

template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::Create()
{
	switch (kind)
	{
	case ALDG://����һ������ͼ
		CreateDG();
		break;
	case ALWDG://����һ����Ȩ����ͼ
		CreateWDG();
		break;
	case ALUDG://����һ������ͼ
		CreateUDG();
		break;
	case ALWUDG://����һ����Ȩ����ͼ
		CreateWUDG();
		break;
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::displayGraph()
{
	for (int i = 0; i < vexnum; i++)
	{
		cout << "��" << i + 1 << "�������ǣ�" << vertices[i].data<< "�ڽӱ�Ϊ��";
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
void ALGraph<VertexType, InfoType>::InitVertics()//��ʼ��ͷ�б�
{
	cout << "������" << this->vexnum << "������Ĺؼ��֣�" << endl;
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
void ALGraph<VertexType, InfoType>::CreateDG()//����һ������ͼ
{
	InitVertics();
	int vhead, vtail;
	cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
	while (cin >> vhead >> vtail)
	{
		InsertArc(vhead, vtail, 0);
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::CreateWDG()//����һ����Ȩ����ͼ
{
	InitVertics();
	int vhead, vtail;
	InfoType w;
	cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
	while (cin >> vhead >> vtail >> w)
	{
		InsertArc(vhead, vtail, w);
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::CreateUDG()//����һ������ͼ
{
	InitVertics();
	int vhead, vtail;
	cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
	while (cin >> vhead >> vtail)
	{
		InsertArc(vhead, vtail, 0);
		InsertArc(vtail, vhead, 0);
	}
}


template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::CreateWUDG()//����һ����Ȩֵ������ͼ
{
	InitVertics();
	int vhead, vtail;
	InfoType w;
	cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
	while (cin >> vhead >> vtail >> w)
	{
		InsertArc(vhead, vtail, w);
		InsertArc(vtail, vhead, w);
	}
}

template<typename VertexType, typename InfoType>
void ALGraph<VertexType, InfoType>::DFS(int i, int* visited)//������������ݹ�
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
void ALGraph<VertexType, InfoType>::DFS()//�����������
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
void ALGraph<VertexType, InfoType>::BFS()//����������������������Ĳ�α�����
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

