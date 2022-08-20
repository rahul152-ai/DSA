#include <iostream>
using namespace std;
#include <vector>
#include <queue>
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

void print(TreeNode<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

TreeNode<int> *takeInput()
{
    int rootdata;
    cout << "Enter data" << endl;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    int n;
    cout << "Enter numbers of children" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int> *takeInputlevelWise()
{
    int rootdata;
    cout << "Enter data" << endl;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << "Enter number of children of " << front->data << endl;
        int childNumbers;
        cin >> childNumbers;
        for (int i = 0; i < childNumbers; i++)
        {
            int childData;
            cout << "Enter the " << i + 1 << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNode.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int> *roots)
{

    TreeNode<int> *root = roots;
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    cout << root->data << ", ";
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *front = pendingNode.front();

        int childNumbers = front->children.size();
        for (int i = 0; i < childNumbers; i++)
        {
            TreeNode<int> *child = front->children.at(i);
            pendingNode.push(child);
            cout << child->data << ", ";
        }
        pendingNode.pop();
    }
}
int totalNode(TreeNode<int> *root)
{
    int num = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        num += totalNode(root->children.at(i));
    }

    return num;
}

int height(TreeNode<int> *root)
{
    int h = 1;
    int childHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int curentChildHeight = height(root->children.at(i));
        if (curentChildHeight > childHeight)
        {
            childHeight = curentChildHeight;
        }
    }
    return h + childHeight;
}

int heightApna(TreeNode<int> *root)
{

    int childheight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int currentChildHeight = heightApna(root->children.at(i));
        if (currentChildHeight > childheight)
        {
            childheight = currentChildHeight;
        }
    }
    return 1 + childheight;
}
void PrintAtLevelK(TreeNode<int> *root, int k)
{
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PrintAtLevelK(root->children.at(i), k - 1);
    }
}

int numberOfLeafNode(TreeNode<int> *root)
{
    int leafNodeNumber = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        leafNodeNumber += numberOfLeafNode(root->children.at(i));
    }

    return leafNodeNumber;
}

int main()
{

    TreeNode<int> *root = takeInputlevelWise();

    printLevelWise(root);
    cout << "Total number of node is: " << totalNode(root) << endl;
    // cout << heightApna(root)<<endl;
    // PrintAtLevelK(root,2);
    cout << numberOfLeafNode;

    return 0;
}
