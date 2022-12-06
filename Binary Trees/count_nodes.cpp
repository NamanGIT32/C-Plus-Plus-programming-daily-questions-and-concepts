#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<queue>
template<typename T>
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;
    BinaryTreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
BinaryTreeNode<int> *TakeInputLevelWise(){
    int rootdata;
    cout<<"enter the root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        BinaryTreeNode<int> *front=pendingnodes.front();
        pendingnodes.pop();
        int leftchild;
        cout<<"enter the left child of "<<front->data<<endl;
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTreeNode<int> *child=new  BinaryTreeNode<int>(leftchild);
            front->left=child;
            pendingnodes.push(child);
        }
        int rightchild;
        cout<<"enter the right child of "<<front->data<<endl;
        cin>>rightchild;
        if(leftchild!=-1){
            BinaryTreeNode<int> *child=new  BinaryTreeNode<int>(rightchild);
            front->right=child;
            pendingnodes.push(child);
        }
    }
    return root;
}
void PrintLevelWise(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
    BinaryTreeNode<int> *front=pendingnodes.front();
    pendingnodes.pop();
    cout<<front->data<<" :";
    if(front->left!=NULL){
        cout<<" L"<<front->left->data;
        pendingnodes.push(front->left);
    }
    if(front->right!=NULL){
        cout<<" R"<<front->right->data;
        pendingnodes.push(front->right);
    }
    cout<<endl;
    }
}  
int count_nodes(BinaryTreeNode<int> *root){
    //Base case
    if(root==NULL){
        return 0;
    }
    int count=1;
    count=count+count_nodes(root->left)+count_nodes(root->right);
    return count;
}

int main(){
    cout<<"Enter the Tree : "<<endl;
    BinaryTreeNode<int> *root=TakeInputLevelWise();
    cout<<"The entered binary tree is : "<<endl;
    PrintLevelWise(root);
    cout<<"Number of nodes in binary tree is : "<<endl;
    cout<<count_nodes(root)<<endl;
    delete(root);
    return 0;
}
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 g
