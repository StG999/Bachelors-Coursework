#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode
{
    public:
        T data;
        vector <TreeNode*> children;

    TreeNode(T x)
    {
        data = x;
    }
};

TreeNode <int>* createTreeLevelWise();
void printTreeLevelWise(TreeNode <int> *rootNode, int height=0);
int heightTree(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *root = createTreeLevelWise();
    cout<<endl<<endl;
    printTreeLevelWise(root);
    cout<<"Height of the tree is: "<<heightTree(root)<<endl;
}

void printTreeLevelWise(TreeNode <int> *rootNode, int height)
{
    if(rootNode == nullptr)
        return;

    queue <TreeNode <int> *> pendingNodes;
    pendingNodes.push(rootNode);
    
    while(!pendingNodes.empty())
    {
        TreeNode <int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<subRoot->data<<": ";
        for(int i=0; i<subRoot->children.size(); i++)
        {
            cout<<subRoot->children[i]->data<<',';
            pendingNodes.push(subRoot->children[i]);
        }

        cout<<endl;
    }
}

int heightTree(TreeNode <int> *rootNode)
{
    if(rootNode == nullptr)
        return 0;
    
    int height = 1, subHeight = 0;

    for(int i=0; i<rootNode->children.size(); i++)
        subHeight = max(subHeight, heightTree(rootNode->children[i]));
    
    return height + subHeight;
}

TreeNode <int>* createTreeLevelWise()
{
    queue <TreeNode <int>*> pendingNodes;
    int rootData;
    cout<<"data: ";
    cin>>rootData;
    TreeNode <int> *rootNode = new TreeNode(rootData);
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode <int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        int noOfChildren;
        cout<<"no of children of "<<subRoot->data<<": ";
        cin>>noOfChildren;
        int childData;

        for(int i=0; i<noOfChildren; i++)
        {
            cout<<"data of "<<i<<"th child of "<<subRoot->data<<": ";
            cin>>childData;
            TreeNode <int> *childNode = new TreeNode<int>(childData);
            subRoot->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }

    return rootNode;
}