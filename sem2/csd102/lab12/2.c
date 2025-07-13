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
struct TreeNode* deleteNode(struct TreeNode* root, int key);
void postOrderTraversal(struct TreeNode* root);

int max_finder(int p, int q);//function to find maximum from two values
struct TreeNode* rotate_left(struct TreeNode* p);//rotating left node with parent
struct TreeNode* rotate_right(struct TreeNode* q);//rotating right node with parent
int get_balance(struct TreeNode* a);//finding balance
struct TreeNode* min_val(struct TreeNode* a);


int main()
{
    struct TreeNode* root = NULL;
    int key, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &key);
        root = insert(root, key);
    }

    root=deleteNode(root, root->data);

    postOrderTraversal(root);
   
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

void postOrderTraversal(struct TreeNode* root)//traversing tree as per post order traversal, aka root->left->right
{
    if (root != NULL) 
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int max_finder(int p, int q)//finding max value from two
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

struct TreeNode* deleteNode(struct TreeNode* root, int key) 
{
    if (root == NULL)//estabilishing for a empty tree
        return root;

    if (key < root->data)//deleting relevant node as per conditions of avl to maintain balance property
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left == NULL)//assuming no left subtree
        {
            struct TreeNode* a = root->right;
            free(root);//freeing up memory
            return a;
        } 
        else if (root->right == NULL)//assuming no right subtree 
        {
            struct TreeNode* b = root->left;
            free(root);//freeing up memory
            return b;
        }

        struct TreeNode* c = min_val(root->right);//temporary node for traversal

        root->data = c->data;

        root->right = deleteNode(root->right, c->data);
    }

    root->height = 1 + max_finder(height(root->left), height(root->right));//incrementing height as per balance
    int value = get_balance(root);//temporary variable to hold value
   
    //performing relevant rotations to maintain balance
    if (value > 1 && get_balance(root->left) >= 0)
        return rotate_right(root);

    if (value > 1 && get_balance(root->left) < 0) 
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (value < -1 && get_balance(root->right) <= 0)
        return rotate_left(root);

    if (value < -1 && get_balance(root->right) > 0) 
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;//ending operation and returning node to tree
}

struct TreeNode* min_val(struct TreeNode* a) //finding mind val node, going to left most node possible
{
    struct TreeNode* current = a;//temporary node to traverse tree

    //going to the left most node
    while (current->left != NULL)
        current = current->left;

    return current;//returning relevant node to the main tree for operations
}