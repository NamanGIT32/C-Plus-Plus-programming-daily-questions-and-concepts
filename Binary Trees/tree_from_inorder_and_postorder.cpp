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
BinaryTreeNode<int> *buildTreeHelper(int *in,int *pst,int inS,int inE,int pstS,int pstE){
    if(inS>inE){
        return NULL;                                         //Base Case(empty array)
    }
    int rootdata=pst[pstE];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootdata){
            rootIndex=i;
            break;
      
        }
    }

    int LinS=inS;
    int RinE=inE;
    int LpstS=pstS;                                       //simple and obvious
    int RpstE=pstE-1; 

    int LinE=rootIndex-1;
    int RinS=rootIndex+1;
    int LpstE=LinE-LinS+LpstS;
    int RpstS=LpstE+1;

    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);
    root->left=buildTreeHelper(in,pst,LinS,LinE,LpstS,LpstE);
    root->right=buildTreeHelper(in,pst,RinS,RinE,RpstS,RpstE);
    return root;
}
BinaryTreeNode<int> *buildTree(int *in,int *pst,int size){
    return buildTreeHelper(in,pst,0,size-1,0,size-1);
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
    int pst[]={4,5,2,8,9,6,7,3,1};
    BinaryTreeNode<int> *root=buildTree(in,pst,9);
    PrintLevelWise(root);
    delete root;
    return 0;
}
