#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename T>
class BinarySearchTreeNode{
    public:
    int data;
    BinarySearchTreeNode<int> *left;
    BinarySearchTreeNode<int> *right;
    BinarySearchTreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinarySearchTreeNode(){
        delete left;
        delete right;
    }
};
BinarySearchTreeNode<int> *TakeInputLevelWise(){
    int rootdata;
    cout<<"enter the root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinarySearchTreeNode<int> *root=new BinarySearchTreeNode<int>(rootdata);
    queue<BinarySearchTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        BinarySearchTreeNode<int> *front=pendingnodes.front();
        pendingnodes.pop();
        int leftchild;
        cout<<"enter the left child of "<<front->data<<endl;
        cin>>leftchild;
        if(leftchild!=-1){
            BinarySearchTreeNode<int> *child=new  BinarySearchTreeNode<int>(leftchild);
            front->left=child;
            pendingnodes.push(child);
        }
        int rightchild;
        cout<<"enter the right child of "<<front->data<<endl;
        cin>>rightchild;
        if(leftchild!=-1){
            BinarySearchTreeNode<int> *child=new  BinarySearchTreeNode<int>(rightchild);
            front->right=child;
            pendingnodes.push(child);
        }
    }
    return root;
}
void PrintLevelWise(BinarySearchTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    queue<BinarySearchTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
    BinarySearchTreeNode<int> *front=pendingnodes.front();
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
void elements_in_range(BinarySearchTreeNode<int> *root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data>=k1 && root->data<=k2){
        cout<<root->data<<" ";
    }
    if(k1<root->data){
        elements_in_range(root->left,k1,k2);
    }
    if(k2>root->data){
        elements_in_range(root->right,k1,k2);
    }
}
int main(){
    cout<<"Let's grow a binary tree : "<<endl;
    BinarySearchTreeNode<int> *root=TakeInputLevelWise();
    cout<<"the entered binary tree is : "<<endl;
    PrintLevelWise(root);
    int k1=2,k2=6;
    cout<<"the elements between "<<k1<<" and "<<k2<<" are : "<<endl;
    elements_in_range(root,k1,k2);
    delete(root);
    return 0;
}
