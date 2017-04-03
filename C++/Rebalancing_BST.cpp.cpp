//
// Created by Sri Hari Vignesh on 29/03/17.
//

//Implementation of Tree Rebalancing in Optimal Space algorithm by Quentin and Bette

//Paper: http://web.eecs.umich.edu/~qstout/pap/CACM86.pdf


#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>
#include <set>
#include <queue>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <cstdint>
#include <random>
#include <valarray>
#include <numeric>
#include <sstream>
#include <list>

struct Node
{
	int value;
	struct Node *right;
	struct Node *left;
};


struct Node *create_node(int value)
{
	struct Node *temp = new Node;
	temp -> right = NULL;
	temp -> left = NULL;
	temp -> value = value;
	return temp;
}

void insert_node(struct Node *root, int nvalue)
{
	if(root == NULL)
	{
		return;
	}
	if(root -> value == nvalue)
	{
		return;
	}
	else if(root -> value > nvalue)
	{
		if(root -> left == NULL)
		{
			root -> left = create_node(nvalue);
			return;
		}
		else
		{
			insert_node(root -> left, nvalue);
		}
	}
	else
	{
		if(root -> right == NULL)
		{
			root -> right = create_node(nvalue);
			return;
		}
		else
		{
			insert_node(root -> right, nvalue);
		}
	}
	return;
}

struct Node *tree_to_vine(struct Node *root)
{
	struct Node *temp_head = new Node;
	temp_head -> right = root;
	temp_head -> left = NULL;
	temp_head -> value = INT_MAX;
	struct Node *vine_head = root;
	struct Node *holder = temp_head;
	int size = 0;
	while(vine_head != NULL)
	{
		if(vine_head -> left == NULL)
		{
			size++;
			vine_head = vine_head -> right;
			temp_head = temp_head -> right;
		}
		else
		{
			struct Node *tvine_head = vine_head -> left;
			vine_head -> left = tvine_head -> right;
			tvine_head -> right = temp_head -> right;
			temp_head -> right = tvine_head;
			vine_head = tvine_head;
		}
	}
	//Storing the size of the vine in pseudo-root's value field
	holder -> value = size;
	return holder;
}


void compression(struct Node *root, int v)
{
	struct Node *scanner = root;
	for(int i = 1; i <= v; i++)
	{
		struct Node *child = scanner -> right;
		scanner -> right = child -> right;
		scanner = scanner -> right;
		child -> right = scanner -> left;
		scanner -> left = child;
	}
	return;
}

int main()
{
	struct Node *root = create_node(10);
	insert_node(root, 5);
	insert_node(root, 3);
	insert_node(root, 8);
	insert_node(root, 20);
	insert_node(root, 15);
	insert_node(root, 25);
	insert_node(root, 45);
	insert_node(root, 100);
	insert_node(root, 125);
	auto temp_head = tree_to_vine(root);
	int size = temp_head -> value;
	int leaf_count = (size + 1 - (pow(2, std::floor(std::log2(size + 1)))));
	compression(temp_head, leaf_count);
	size -= leaf_count;
	while(size > 1)
	{
		compression(temp_head, size/2);
		size /= 2;
	}
	root = temp_head -> right;
	temp_head -> right = NULL;
	free(temp_head);
	return 0;
}