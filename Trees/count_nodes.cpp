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
        int numChild;
        cout<<"Enter no. of childrens of "<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
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
void printTree(TreeNode<int> *root){
    if(root==nullptr){
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size()!=0){
    TreeNode<int> *front=q.front();
    q.pop();
    cout<<front->data<<" : ";
    if(front->children.size()){
        cout<<front->children[0]->data;
        q.push(front->children[0]);
    }
    for(int i=1;i<front->children.size();i++){
        cout<<" ,"<<front->children[i]->data;
        q.push(front->children[i]);  
    }
    cout<<endl;
    }
}
int count_nodes(TreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans=ans+count_nodes(root->children[i]);
    }
    return ans;
}
int main(){
    cout<<"Let's Grow a Tree : "<<endl;
    TreeNode<int> *root=TakeInputLevelWise();
    cout<<"--------------------------------------"<<endl;
    cout<<"The entered tree is : "<<endl;
    printTree(root);
    cout<<"Number of nodes in tree are : "<<endl;
    cout<<count_nodes(root)<<endl;
    return 0;
}
