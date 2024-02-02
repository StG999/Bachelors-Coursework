#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node* createList(int size)
{
    if(size < 1)
        return nullptr;

    int value;
    cin>>value;

    Node *head = new Node(value);
    Node *tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>>value;
        Node *newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

void printList(Node *head)
{
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

void FPE(Node *head)
{
    int counter = 0;

    if(head->next == nullptr)
    {   
        cout<<"Peak Value: "<<head->data<<endl<<"Comparisons: "<<counter<<endl;
        return;
    }

    Node *prev = head;
    head = head->next;

    while(head != nullptr && head->next != nullptr)
    {
        counter += 2;                                                           // +2 since considering two comparisons at once to determine the peak.
        if(prev->data < head->data && head->data > head->next->data)
        {
            cout<<"Peak Value: "<<head->data<<endl<<"Comparisons: "<<counter<<endl;
            return;
        }
        prev = head;
        head = head->next;
    }

    cout<<"Peak Value: "<<-1<<endl<<"Comparisons: "<<counter<<endl;
}

int main(void)
{
    int n;
    cin>>n;

    Node *list1 = createList(n);
    FPE(list1);
}