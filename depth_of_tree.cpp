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


int maxDepth(struct Node* node)
{
    int lDepth,rDepth;
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        lDepth=maxDepth(node->left);
        rDepth=maxDepth(node->right);
    }
    
    if(lDepth>rDepth)
    {
        return lDepth+1;
    }
    else
    {
        return rDepth+1;
    }
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

int main()
{
    struct Node* root=NULL;
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root, 12);
    root=insert(root,5);
    root=insert(root, 6);
    
    cout<<"\nMax Depth is: "<<maxDepth(root);
}
