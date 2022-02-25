#pragma once
#include <iostream>
#include "Queue.hpp"
using namespace std;

class PaperFoldingNode
{
public:
	PaperFoldingNode(string item, PaperFoldingNode* left, PaperFoldingNode* right)
	{
		this->item = item;
		this->left = left;
		this->right = right;
	}
	string item;
	PaperFoldingNode* left;
	PaperFoldingNode* right;
};


void printTree(PaperFoldingNode* tree)
{
	if(tree!=NULL)
	{
		printTree(tree->left);
		cout << tree->item << ",";
		printTree(tree->right);
	}
}
PaperFoldingNode* createTree(int N)
{
	PaperFoldingNode* root = NULL;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			root = new PaperFoldingNode("down", NULL, NULL);
		}
		else
		{
			Queue<PaperFoldingNode*> myqueuepaper;
			myqueuepaper.enqueue(root);
			while (!myqueuepaper.isEmpty())
			{
				PaperFoldingNode* tmp = myqueuepaper.dequeue();
				if (tmp->left != NULL)
				{
					myqueuepaper.enqueue(tmp->left);
				}
				if (tmp->right != NULL)
				{
					myqueuepaper.enqueue(tmp->right);
				}
				if (tmp->left == NULL && tmp->right == NULL)
				{
					tmp->left = new PaperFoldingNode("down", NULL, NULL);
					tmp->right = new PaperFoldingNode("up", NULL, NULL);
				}
			}
		}
	}
	return root;
}