#include<iostream>
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
void Inorder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
} 
void Preorder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
} 
void Postorder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
} 
int main(){
    cout<<"Enter the Tree : "<<endl;
    BinaryTreeNode<int> *root=TakeInputLevelWise();
    cout<<"The entered binary tree is : "<<endl;
    PrintLevelWise(root);

    cout<<"Binary tree in inorder traversal is : "<<endl;
    Inorder(root);
    cout<<endl;

    cout<<"Binary tree in preorder traversal is : "<<endl;
    Preorder(root);
    cout<<endl;

    cout<<"Binary tree in postorder traversal is : "<<endl;
    Postorder(root);
    cout<<endl;

    delete(root);
    return 0;
}
