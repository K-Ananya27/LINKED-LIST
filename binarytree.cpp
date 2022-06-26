#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *right,*left;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};

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
    struct Node* root=new Node(1);
    root->left=new Node(12);
    root->right=new Node(3);
    root->left->left=new Node(5);
    root->left->right=new Node(6);
    cout<<" Inorder : "<<" ";
    inorder(root);
    cout<<" \nPostorder : "<<" ";
    postorder(root);
    cout<<" \nPreorder : "<<" ";
    preorder(root);
}
