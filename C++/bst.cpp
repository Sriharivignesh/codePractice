/* https://codefights.com/challenge/n75eG9MuhDzejuCyp/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>
#include <set>
#include <queue>

typedef struct tree_node
{
    int value;
    struct tree_node *right;
    struct tree_node *left;
}bnode;

bnode *new_node_creator(int value)
{
    bnode *temp = (bnode *)malloc(sizeof(bnode));
    temp->right = NULL;
    temp->left = NULL;
    temp->value = value;
    return temp;
}

void insert_node(bnode *broot,int val)
{
    bnode *new_node = new_node_creator(val);
    bnode *temp = broot;
    while(1)
    {
        if(new_node->value == temp->value)
        {
            free(new_node);
            break;
        }
        else if(new_node->value > temp->value)
        {
            if(temp->right == NULL)
            {
                temp->right = new_node;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            if(temp->left == NULL)
            {
                temp->left = new_node;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
    }
}

void inorder(bnode *temp) {
   if (temp != NULL) {
      inorder(temp->left);
      std::cout<<temp->value<<std::endl;
      inorder(temp->right);
   }
}
/*
 This function displays the tree in preorder fashion
 */
void preorder(bnode *temp) {
   if (temp != NULL) {
       std::cout<<temp->value<<std::endl;
      preorder(temp->left);
      preorder(temp->right);
   }
}
 
/*
 This function displays the tree in postorder fashion
 */
void postorder(bnode *temp) {
   if (temp != NULL) {
      postorder(temp->left);
      postorder(temp->right);
      std::cout<<temp->value<<std::endl;
   }
}

int maxDepth(bnode *node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int left_Depth = maxDepth(node->left);
       int right_Depth = maxDepth(node->right);
 
       /* use the larger one */
       if (left_Depth > right_Depth) 
           return(left_Depth+1);
       else 
           return(right_Depth+1);
   }
} 

bnode * minValueNode(bnode* node)
{
    bnode* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
bnode* deleteNode(bnode *broot, int key)
{
    // base case
    if (broot == NULL) return broot;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < broot->value)
        broot->left = deleteNode(broot->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > broot->value)
        broot->right = deleteNode(broot->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (broot->left == NULL)
        {
            bnode *temp = broot->right;
            free(broot);
            return temp;
        }
        else if (broot->right == NULL)
        {
            bnode *temp = broot->left;
            free(broot);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
         bnode* temp = minValueNode(broot->right);
 
        // Copy the inorder successor's content to this node
        broot->value = temp->value;
 
        // Delete the inorder successor
        broot->right = deleteNode(broot->right, temp->value);
    }
    return broot;
}

/* Print nodes at a given level */
void printGivenLevel(bnode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        std::cout<<root->value<<std::endl;
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}


void printLevelOrder(bnode* root)
{
    int h = maxDepth(root);
    int i = 0;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 




int main()
{
   /* bnode *root = new_node_creator(50);
    insert_node(root,23);
    insert_node(root,33);
    insert_node(root,34);
    insert_node(root,33);
    insert_node(root,59);
    insert_node(root,7);*/
    /*std::cout<<root->left->value<<std::endl;
    std::cout<<root->right->value<<std::endl;*/
    /*inorder(root);
    std::cout<<"*******************"<<std::endl;
    postorder(root);
    std::cout<<"*******************"<<std::endl;
    preorder(root);
    std::cout<<"*******************"<<std::endl;
    std::cout<<maxDepth(root)<<std::endl;*/
    int n = 10;
    std::cout<<!!10<<std::endl;
    return 0;
}

