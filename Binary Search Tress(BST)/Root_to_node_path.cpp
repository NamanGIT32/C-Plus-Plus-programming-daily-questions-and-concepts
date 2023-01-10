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
vector<int>* RootToNodePath(BinarySearchTreeNode<int> *root,int data){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* Leftoutput=RootToNodePath(root->left,data);
    if(Leftoutput != NULL){
        Leftoutput->push_back(root->data);
        return Leftoutput;
    }
    vector<int>* Rightoutput=RootToNodePath(root->right,data);
    if(Rightoutput != NULL){
        Rightoutput->push_back(root->data);
        return Rightoutput;
    }
    else{
        return NULL;
    }
}
int main(){
    cout<<"Let's grow a binary tree : "<<endl;
    BinarySearchTreeNode<int> *root=TakeInputLevelWise();
    cout<<"the entered binary tree is : "<<endl;
    PrintLevelWise(root); 
    cout<<"root to node path in our binary tree is : "<<endl;
    int data=8;
    vector<int>* output=RootToNodePath(root,data);
    for(int i=0;i<output->size();i++){             //given tree is : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
        cout<<output->at(i)<<endl;
    }
    delete output;      //deleting the output vector
    delete(root);
    return 0;
}
