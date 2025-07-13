#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode*left;
    struct TreeNode*right;
};

struct TreeNode* insertNode(struct TreeNode*root, int value);

int treeHeight(struct TreeNode*root);

int main(){
    struct TreeNode* root=NULL;
    int nodeValue, n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &nodeValue);
        root=insertNode(root, nodeValue);
    }


    int height=treeHeight(root);
    printf("%d ", height);
    return 0;
}

struct TreeNode* insertNode(struct TreeNode* root, int value)
{
    if (root==NULL)//assuming empty tree
    {
        struct TreeNode*newNode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data=value;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
    }

    if (value<root->data)//if value is smaller than tree root
    {
        root->left=insertNode(root->left, value);
    }

    if (value>root->data)//if value is greater than tree root
    {
        root->right=insertNode(root->right, value);
    }

    return root;
}

int treeHeight(struct TreeNode*root)
{
    if (root==NULL)//handling empty tree
    {
        return 0;
    }

    int left=treeHeight(root->left);//recursively finding height of each left subbranch
    int right=treeHeight(root->right);//recursively finding height of each right subbranch

    return 1+(left>right?left:right);//simultaneously incrementing while returning higher value from base node
}
