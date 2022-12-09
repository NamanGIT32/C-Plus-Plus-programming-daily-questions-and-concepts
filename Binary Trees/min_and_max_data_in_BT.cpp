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
pair<int,int> min_and_max(BinaryTreeNode<int> *root){
    pair<int,int> p;
    p.first=INT_MAX;
    p.second=INT_MIN;
    if(root==NULL){
        return p;
    }
    pair<int,int> left=min_and_max(root->left);
    pair<int,int> right=min_and_max(root->right);
    p.first=min(root->data,min(left.first,right.first));
    p.second=max(root->data,max(left.second,right.second));
    return p;
}
int main(){
    cout<<"Enter the Tree : "<<endl;
    BinaryTreeNode<int> *root=TakeInputLevelWise();
    cout<<"The entered binary tree is : "<<endl;
    PrintLevelWise(root);
    cout<<"The minimum and maximum nodes of binary tree are : "<<endl;
    pair<int,int> p=min_and_max(root);
    cout<<p.first<<" "<<p.second<<endl;

    delete(root);
    return 0;
}
