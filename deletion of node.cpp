
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *right,*left;
};

struct Node* newNode(int key)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=key;
    temp->right=temp->left=NULL;
    return temp;
}

struct Node* minValueNode(struct Node *node)
{
    struct Node *current=node;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node *root, int key)
{
    
    if(root==NULL)
        return root;
    if(key < root->data)
    {
        root->left=deleteNode(root->left,key);
    }
    else if(key > root->data)
    {
        root->right=deleteNode(root->right,key);
    }
    else
    {
        if(root->left==NULL) 
        {//0 or 1 child
            struct Node* temp =root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
           struct Node *temp=root->left;
           free(root);
           return temp;
        }
        struct Node* temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;        
}
struct Node* insert(struct Node* node,int key)
{
    if(node==NULL)
        return newNode(key);
    if(key < node->data)
    {
        node->left=insert(node->left,key);
    }
    else
    {
        node->right=insert(node->right,key);
    }
    return node;
}
struct Node* inorder(struct Node* node)
{
    if(node==NULL)
        return 0;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
struct Node* preorder(struct Node* node)
{
    if(node==NULL)
        return 0;
    
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}


struct Node* postorder(struct Node* node)
{
    if(node==NULL)
        return 0;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}
int main()
{
    struct Node* root=NULL;
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root, 12);
    root=insert(root,5);
    root=insert(root, 6);
    cout<<" Inorder : "<<" ";
    inorder(root);
    cout<<" \nPostorder : "<<" ";
    postorder(root);
    cout<<" \nPreorder : "<<" ";
    preorder(root);
    root = deleteNode(root, 5);
}
