#include<iostream>
#include<vector>
#include"queue"
using namespace std;
template<typename T>
class TreeNode{
    public:
    int data;
    vector<TreeNode<int>*> children;
    TreeNode(T data){
        this->data=data;
    }
};
TreeNode<int> *TakeInputLevelWise(){
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    TreeNode<int> *root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        int rootChild;
        cout<<"Enter no. of childrens of "<<front->data<<endl;
        cin>>rootChild;
        for(int i=0;i<rootChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}
void print_preorder(TreeNode<int> *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" "; 
    for(int i=0;i<root->children.size();i++){
        print_preorder(root->children[i]);
    }
}
void print_postorder(TreeNode<int> *root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        print_postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}
int main(){
    cout<<"Let's Grow a Tree : "<<endl;
    TreeNode<int> *root=TakeInputLevelWise();
    cout<<"--------------------------------------"<<endl;
    cout<<"The entered tree in preorder traversal is : "<<endl;
    print_preorder(root);
    cout<<"The entered tree in postorder traversal is : "<<endl;
    print_postorder(root);
    return 0;
}
