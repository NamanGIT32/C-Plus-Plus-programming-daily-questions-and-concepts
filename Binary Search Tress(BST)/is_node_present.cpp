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
bool is_node_present(BinarySearchTreeNode<int> *root,int x){
    //Base case
    if(root==NULL){
        return 0;
    }
    if(root->data==x){
        return 1;
    }
    if(x<root->data){
        is_node_present(root->left,x);
    }
    else{
        is_node_present(root->right,x);
    }
} 
int main(){
    cout<<"Let's grow a binary tree : "<<endl;
    BinarySearchTreeNode<int> *root=TakeInputLevelWise();
    cout<<"the entered binary tree is : "<<endl;
    PrintLevelWise(root);
    int x=5;
    cout<<is_node_present(root,x)<<endl;
    delete root;
    return 0;
    }
