//
// Created by Sri Hari Vignesh on 13/03/17.
//


//Credit: Tushar Roy

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


struct node
{
	int value;
	struct node *right;
	struct node *left;
};

struct node *construct_node(int node_value)
{
	struct node *new_node = new node;
	new_node -> value = node_value;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
}

struct node *rightrightRotate(struct node *node)
{
	auto new_root = node -> left;
	node -> left = new_root -> right;
	new_root -> right = node;
	return new_root;
}
struct node *leftleftRotate(struct node *node)
{
	auto new_root = node -> right;
	node -> right = new_root -> left;
	new_root -> left = node;
	return new_root;
}

struct node *makerightright(struct node *node)
{
	auto new_root = node -> left -> right;
	node -> left -> right = new_root -> left;
	new_root -> left = node -> left;
	node -> left = new_root;
	return node;
}

struct node *makeleftleft(struct node *node)
{
	auto new_root = node -> right -> left;
	node -> right -> left = new_root -> right;
	new_root -> right = node -> right;
	node -> right = new_root;
	return node;
}

void inorder_traversal(struct node *nroot)
{
	if(nroot != NULL)
	{
		inorder_traversal(nroot -> left);
		std::cout << nroot -> value << ",";
		inorder_traversal(nroot -> right);
	}
	return;
}

int max_depth_of_node(struct node *node)
{
	if(node == NULL)
	{
		return 0;
	}
	int right_depth = node -> right ? 1 + max_depth_of_node(node -> right):0;
	int left_depth = node -> left ? 1 + max_depth_of_node(node -> left):0;
	return std::max(right_depth, left_depth);

}

int return_balance(struct node *node)
{
	if(node == NULL)
	{
		return 0;
	}
	return max_depth_of_node(node -> left) - max_depth_of_node(node -> right);
}

struct node *insert_node(struct node *root, struct node *node)
{
	if(root == NULL)
	{
		return root;
	}
	if(node -> value < root -> value)
	{
		if(root -> left == NULL)
		{
			root -> left = node;
		}
		else
		{
			insert_node(root -> left, node);
		}
	}
	if(node -> value > root -> value)
	{
		if(root -> right == NULL)
		{
			root -> right = node;
		}
		else
		{
			insert_node(root -> right, node);
		}
	}
	int balance = return_balance(node);
	if(balance > 1)
	{
		if(return_balance(node -> left) > 1)
		{
			node = rightrightRotate(node);
		}
		else
		{
			node = makerightright(node);
			node = rightrightRotate(node);
		}
	}
	else if(balance < -1)
	{
		if(return_balance(node -> right) < 1)
		{
			node = leftleftRotate(node);
		}
		else
		{
			node = makeleftleft(node);
			node = leftleftRotate(node);
		}
	}
	else
	{
		return root;
	}
	return root;
}

int main()
{
	struct node *root = construct_node(-10);
	root = insert_node(root, construct_node(2));
	root = insert_node(root, construct_node(13));
	root = insert_node(root, construct_node(-13));
	root = insert_node(root, construct_node(-15));
	root = insert_node(root, construct_node(15));
	root = insert_node(root, construct_node(17));
	root = insert_node(root, construct_node(400));
	root = insert_node(root, construct_node(500));
	root = insert_node(root, construct_node(600));
	insert_node(root, construct_node(20));
	inorder_traversal(root);
	return 0;
}

