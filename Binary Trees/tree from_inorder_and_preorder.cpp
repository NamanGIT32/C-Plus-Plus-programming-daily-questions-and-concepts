#include<iostream>
#include<queue>
using namespace std;
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
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
BinaryTreeNode<int> *buildTreehelper(int *in,int *pre,int inS,int inE,int preS,int preE){
    if(inS>inE){
        return NULL;           //Base case
    }
    int rootData=pre[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }

    int LinS=inS;
    int LpreS=preS+1;           //simple and obvious
    int RinE=inE;
    int RpreE=preE;
    
    int LinE=rootIndex-1;
    int RinS=rootIndex+1;       //with the help of rootindex
    int LpreE=LinE-LinS+LpreS;
    int RpreS=LpreE+1;

    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreehelper(in,pre,LinS,LinE,LpreS,LpreE);      //calling recursion for left 
    root->right=buildTreehelper(in,pre,RinS,RinE,RpreS,RpreE);     // and right subtree
    return root;
}
BinaryTreeNode<int> *buildTree(int *in,int *pre,int size){
    return buildTreehelper(in,pre,0,size-1,0,size-1);
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
int main(){
    int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};
    BinaryTreeNode<int> *root=buildTree(in,pre,9);
    PrintLevelWise(root);
    delete root;
    return 0;
}
