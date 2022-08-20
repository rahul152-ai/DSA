#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include "binaryTree.cpp"

binaryTreeNode<int> *binarySearchTree(binaryTreeNode<int> *root, int search)
{

  if (root == NULL)
  {
    return NULL;
  }
  if (root->data == search)
  {
    return root;
  }
  if (root->data > search)
  {
    return binarySearchTree(root->left, search);
  }
  else
  {
    return binarySearchTree(root->right, search);
  }
  return NULL;
}
// function for search in range;
void binarySearchTreeInRange(binaryTreeNode<int> *root, int Range1, int Range2)
{
  if (root == NULL)
  {
    return;
  }
  if (root->data > Range1)
  {
    binarySearchTreeInRange(root->left, Range1, Range2);
  }
  if (Range1 <= root->data and Range2 >= root->data)
  {
    cout << root->data << " ";
  }
  if (root->data < Range2)
  {
    binarySearchTreeInRange(root->right, Range1, Range2);
  }
}

// function to check if tree is binary tree or not;

int maximum(binaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return INT_MIN;
  }

  return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(binaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return INT_MAX;
  }
  return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBstOrNot(binaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return true;
  }
  int leftMax = maximum(root->left);
  int rightMin = minimum(root->right);
  return (root->data > leftMax) && (root->data <= rightMin) && isBstOrNot(root->left) && isBstOrNot(root->right);
}

//function to to find path to particular binary tree

vector<int>* getRootNodeToPath(binaryTreeNode<int> *root,int data){
  if (root==NULL)
  {
    return NULL;
  }
  
  if (root->data==data)
  {
    vector<int> *output = new vector<int>();
    output->push_back(root->data);
    return output;
  }

  vector<int>* leftOutput=getRootNodeToPath(root->left,data);
  if (leftOutput!= NULL)
  {
    leftOutput->push_back(root->data);
    return leftOutput;
  }

  vector<int>* rightOutput = getRootNodeToPath(root->right,data);
  if (rightOutput!= NULL)
  {
    rightOutput->push_back(root->data);
    return rightOutput;
  }

  else{
    return NULL;
  }
  
} 

int main()
{

  binaryTreeNode<int> *root;
  root = takeInputLevelWise();
  vector<int>* output = getRootNodeToPath(root, 8);
  for (int i = 0; i < output->size(); i++)
  {
    cout<<output->at(i)<<endl;
  }
  delete output;
  // cout << isBstOrNot(root);
  // binarySearchTreeInRange(root, 20, 30);
  // binaryTreeNode<int> *key = binarySearchTree(root, 7);
  // cout << key->data << endl;
  // cout << key->left->data << endl;
  // cout << key->right->data << endl;

  return 0;
}