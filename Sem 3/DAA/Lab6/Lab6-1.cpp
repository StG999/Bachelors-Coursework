#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
    public:
        T data;
        vector <TreeNode *> children;
    
    TreeNode(T x)
    {
        data = x;
    }
};

class Pair
{
    public:
        int maximum;
        int minimum;
    
    Pair(int max, int min)
    {
        maximum = max;
        minimum = min;
    }
};

TreeNode <int>* createTree();
Pair MinMaxOfTree(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *root = createTree();
    cout<<endl<<endl;
    Pair ans = MinMaxOfTree(root);
    cout<<"maximum node: "<<ans.maximum<<endl<<"minimum node: "<<ans.minimum<<endl;
}

TreeNode <int>* createTree()
{
    int rootData;
    cout<<"root data: ";
    cin>>rootData;

    TreeNode <int> *rootNode = new TreeNode(rootData);

    queue <TreeNode <int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode <int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        int noOfChildren;
        cout<<"no of children of "<<subRoot->data<<": ";
        cin>>noOfChildren;

        for(int i=0; i<noOfChildren; i++)
        {
            int childData;
            cout<<"data of "<<i<<"th child of "<<subRoot->data<<": ";
            cin>>childData;

            TreeNode <int> *childNode = new TreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}

Pair MinMaxOfTree(TreeNode <int> *rootNode)
{
    int largest = rootNode->data;
    int mininum = rootNode->data;

    for(int i=0; i<rootNode->children.size(); i++)
    {
        largest = max(largest, MinMaxOfTree(rootNode->children[i]).maximum);
        mininum = min(mininum, MinMaxOfTree(rootNode->children[i]).minimum);
    }

    Pair ans(largest, mininum);
    return ans;
}