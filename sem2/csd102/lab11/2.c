#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insertNode(struct TreeNode* root, int value);

void inOrderTraversal(struct TreeNode* root);

int main(){
    struct TreeNode* root=NULL;
    int nodeValue, n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &nodeValue);
        root=insertNode(root, nodeValue);
    }


    inOrderTraversal(root);

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

void inOrderTraversal(struct TreeNode* root)//requisite code
{
    if (root!=NULL)
    {
        inOrderTraversal(root->left);//going to the left node and setting up recursive
        printf("%d ", root->data);//printing values
        inOrderTraversal(root->right);//going to the right, then to the left and setting up recursive
    }
}