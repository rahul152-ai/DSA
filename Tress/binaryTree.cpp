#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include<algorithm>
#include <utility>


template <typename T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;
    binaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void prntBinaryTree(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        
        return;
    }

    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " , ";
    }

    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }

    cout << endl;

    prntBinaryTree(root->left);
    prntBinaryTree(root->right);
}
binaryTreeNode<int> *takeInput()
{

    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    binaryTreeNode<int> *leftChild = takeInput();
    binaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

binaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{

    if (inS > inE)
    {
        return NULL;
    }
    int rootData = pre[preS];
    int rootInex = -1;
    for (int i = inS; i <=inE; i++)
    {
        if (in[i] == rootData)
        {
            rootInex = i;
            break;
        }
    }

    
    int linS = inS;
    int linE = rootInex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = rootInex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, linS, linE, lpreS, lpreE);
    root->right = buildTreeHelper(in, pre, rinS, rinE, rpreS, rpreE);
    // cout<<root->data;
    return root;
}

binaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

//height of the binary tree;
int height(binaryTreeNode<int> *root){
    if (root==NULL)
    {
       return 0;
    }

    return 1+ max(height(root->left),height(root->right));
    
}

//Dimeter of the binary tree
int dimeterOfBinaryTree(binaryTreeNode<int>* root){
    if (root==NULL)
    {
       return 0;
    }
    int option1 = height(root->left)+height(root->right);
    int option2 = dimeterOfBinaryTree(root->left);
    int option3 = dimeterOfBinaryTree(root->right);
    cout<<option2<<option3;
    return max(option1,max(option2,option3));
}
//calculating dimeter and height  of the tree with single function using pair;
pair<int,int> dimeterAndHeightWithSingleFunction(binaryTreeNode<int> *root){
    if (root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftAns = dimeterAndHeightWithSingleFunction(root->left);
    pair<int,int> rightAns = dimeterAndHeightWithSingleFunction(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd =rightAns.second;
    int rh = rightAns.first;
    int height = 1+ max(lh,rh);
    int dimeter = max(lh+rh,max(ld,rd));
    pair<int ,int> p;
    p.first=height;
    p.second=dimeter;
    return p;
    
}
//taking input levelwise in binary tree;
binaryTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout<<"Enter the root Data: ";
    cin>>rootData;
    binaryTreeNode<int> * root=new binaryTreeNode<int>(rootData);
    queue<binaryTreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size()!=0)
    {
        binaryTreeNode<int> *front=  pendingNode.front();
        pendingNode.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if (leftChildData!=-1)
        {
          binaryTreeNode<int> * child=new binaryTreeNode<int>(leftChildData);  
          front->left= child;
          pendingNode.push(child);
        }

        cout<<"Enter right child of "<<front->data<<endl;
        int rightChild;
        cin>>rightChild;
        if (rightChild!=-1)
        {
           binaryTreeNode<int> * child=new binaryTreeNode<int>(rightChild);
           front->right=child;
           pendingNode.push(child);
        }
        
    }
    return root;
    
}
// int main()
// {
//     // binaryTreeNode<int> *root = new binaryTreeNode<int>(1);
//     // binaryTreeNode<int> *node1 = new binaryTreeNode<int>(2);
//     // binaryTreeNode<int> *node2 = new binaryTreeNode<int>(3);
//     // root->left = node1;
//     // root->right = node2;
//     // int in[]={4,2,5,1,8,6,9,7,3};
//     // int pre[]={1,2,4,5,3,6,8,9,7};
    
//     // binaryTreeNode<int> *root=buildTree(in,pre,9);

//     // binaryTreeNode<int> * root;
//     // root = takeInputLevelWise();
//     // prntBinaryTree(root);
//     // pair<int,int> p = dimeterAndHeightWithSingleFunction(root);
//     // cout<<"Height of The tree: "<<p.first<<endl;
//     // cout<<"Dimeter of The Tree: "<<p.second<<endl;
//     return 0;
// }