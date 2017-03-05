//
// Created by Sri Hari Vignesh on 03/03/17.
//
#include <iostream>
#include <vector>



struct interval
{
	int low;
	int high;
};
struct interval_node
{
	int max;
	interval *interval_info;
	interval_node *left;
	interval_node *right;
};

struct interval_node *create_new_node(interval k)
{
	interval_node *node = new interval_node();
	node->max = k.high;
	node->interval_info = new interval(k);
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insert_interval(struct interval_node *iroot, interval &k)
{
	if(k.low == iroot -> interval_info -> low && k.high == iroot -> interval_info -> high)
	{
		return;
	}
	else if(k.low < iroot -> interval_info -> low)
	{
		if(iroot -> left == NULL)
		{
			iroot -> left = create_new_node(k);
		}
		else
		{
			insert_interval(iroot -> left, k);
		}
	}
	else
	{
		if(iroot -> right == NULL)
		{
			iroot -> right = create_new_node(k);
		}
		else
		{
			insert_interval(iroot -> right, k);
		}
	}
	if(iroot -> max < k.high)
	{
		iroot -> max = k.high;
	}
	return;
}

void inorder_traversal(struct interval_node *iroot)
{
	if(iroot == NULL)
	{
		return;
	}
	inorder_traversal(iroot -> left);
	std::cout << "[" << iroot -> interval_info -> low << "," << iroot -> interval_info -> high << "]"  << "   max: " << iroot -> max << "\n";
	inorder_traversal(iroot -> right);
	return;
}

bool overlap_check(interval *i1, interval &i2)
{
	if(i1 -> low <= i2.high && i2.low <= i1 -> high)
	{
		return 1;
	}
	return 0;
}

struct interval_node *overlap_search(struct interval_node *iroot, interval &k)
{
	if(iroot == NULL)
	{
		return NULL;
	}
	if(overlap_check(iroot -> interval_info, k))
	{
		return iroot;
	}
	if(iroot -> left != NULL && iroot -> left -> max >= k.low)
	{
		return overlap_search(iroot -> left, k);
	}
	return overlap_search(iroot -> right, k);
}

int main()
{
	std::vector<interval> intervals = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40}};

	interval_node *root = NULL;
	root = create_new_node(intervals[0]);
	for(auto i : intervals)
	{
		insert_interval(root, i);
	}
	inorder_traversal(root);
	struct interval p = {7,20};
	struct interval_node *r = overlap_search(root, p);
	if(r)
	{
		std::cout <<"The overlapping interval is : " << "[" << r -> interval_info -> low << "," << r -> interval_info -> high << "]" << "\n";
	}

	return 0;
}

