#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int item)
{
    struct node* temp = new struct node;

    temp->data = item;
    temp->left = temp->right = NULL;

    return temp;
}

struct node* insert(struct node* node, int value)
{
    if (node == NULL)
        return newNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);

    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

void inorder(struct node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}

int main()
{
    struct node* root = NULL;

    root = insert(root, 45);
    insert(root, 25);
    insert(root, 65);
    insert(root, 15);
    insert(root, 35);
    insert(root, 55);
    insert(root, 75);

    cout << "\nInorder traversal\n";

    inorder(root);

    return 0;
}