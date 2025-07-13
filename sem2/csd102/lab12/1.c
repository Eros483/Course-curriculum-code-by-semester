#include <stdio.h>//all relevant libraries
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
};//defining a node

int height(struct TreeNode* node);
struct TreeNode* insert(struct TreeNode* root, int key);
void preOrderTraversal(struct TreeNode* root);

int max_finder(int p, int q);//function to find maximum from two values
struct TreeNode* rotate_left(struct TreeNode* p);//rotating left node with parent
struct TreeNode* rotate_right(struct TreeNode* q);//rotating right node with parent
int get_balance(struct TreeNode* a);//finding balance


int main()
{
    struct TreeNode* root = NULL;
    int key, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &key);
        root = insert(root, key);
    }
    preOrderTraversal(root);
   
    printf("\n");//newline character

    return 0;
}

int height(struct TreeNode* node)
{
    if (node == NULL)
    {
        return -1;
    }//handling empty tree
    else
    {
        return node->height;
    }
}

struct TreeNode* insert(struct TreeNode* root, int key)//insertion function
{
    if (root == NULL)//handling empty tree
    {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        return newNode;//creating basically a empty node to show empty tree
    }

    if (key < root->data)//relevant comparisons as per requirements of AVL
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
        return root;

    root->height = 1 + max_finder(height(root->left), height(root->right));//incrememnting height
    int value = get_balance(root);//balance as per avl rules

    //relevant node shifting as per avl
    if (value > 1 && key < root->left->data)
        return rotate_right(root);

    if (value < -1 && key > root->right->data)
        return rotate_left(root);

    if (value > 1 && key > root->left->data)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (value < -1 && key < root->right->data)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;//returning final positioning
}

void preOrderTraversal(struct TreeNode* root)
{
    if (root != NULL)//handling empty list
    {
        printf("%d ", root->data);//sequentially printing values as per preorder aka left->right->root
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int max_finder(int p, int q)
{
    return (p > q) ? p : q;
}

struct TreeNode* rotate_left(struct TreeNode* p)//left rotation
{
    struct TreeNode* q = p->right;//setting up temp nodes for the swap
    struct TreeNode* T2 = q->left;

    q->left = p;
    p->right = T2;

    p->height = max_finder(height(p->left), height(p->right)) + 1;//updating heights with incremements
    q->height = max_finder(height(q->left), height(q->right)) + 1;

    return q;
}

struct TreeNode* rotate_right(struct TreeNode* q)//right rotation
{
    struct TreeNode* p = q->left;//setting up temp nodes for the swap
    struct TreeNode* T2 = p->right;

    p->right = q;
    q->left = T2;

    q->height = max_finder(height(q->left), height(q->right)) + 1;//updating heights with increments
    p->height = max_finder(height(p->left), height(p->right)) + 1;

    return p;
}

int get_balance(struct TreeNode* a)// balance finding function as per avl
{
    if (a == NULL)
        return 0;
    else
        return height(a->left) - height(a->right);
}
