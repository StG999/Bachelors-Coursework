#include <iostream>
#include <fstream>

// MY PROGRAM TAKES INPUT FROM input.txt AND RETURNS THE OUTPUT ON THE TERMINAL ITSELF (as sir had allowed in the class).

using namespace std;

class Node
{
    public:
        string name;                    // PASSENGER OR AIRPLANE NAME
        Node *next;
    
    Node(string name)
    {
        this->name = name;
        next = nullptr;
    }
};

Node* addingReservation(Node *head, string data)
{
    Node *newNode = new Node(data);

    while(head->next != nullptr)
        head = head->next;
    
    head->next = newNode;

    return head;
}

Node* addingPlanes(Node *head, string data)
{
    Node *newNode = new Node(data);
    return newNode;
}

Node* cancelReservation(Node *head, string data)
{
    Node *current = head->next;
    Node *prev = head;


    while(current->name != data && current != nullptr)
    {
        prev = current;
        current = current->next;
    }

    if(current == nullptr)
    {
        cout<<"passenger does not exist in the given plane\n";
        return head;
    }
    
    prev->next = current->next;

    delete current;
    return head;
}

void printNames(Node *head)
{
    if(head == nullptr)
    {
        cout<<"No passengers on the given plane\n";
        return;
    }

    while(head != nullptr)
    {
        cout<<head->name<<" ";
        head = head->next;
    }

    cout<<endl;
}

int noOfPassengers(Node *head)
{
    int counter = 0;
    
    while(head != nullptr)
    {
        counter++;
        head = head->next;
    }
    
    return counter-1;
}

int main()
{
    ifstream iFILE;
    iFILE.open("input.txt");

    int noOfPlanes = 0;
    iFILE>>noOfPlanes;
    string name;
    
    Node *heads[noOfPlanes];
    for(int i=0; i<noOfPlanes; i++)
    {
        iFILE>>name;
        heads[i] = addingPlanes(heads[i], name);
    }

    while(!iFILE.eof())
    {
        int n;
        iFILE>>n;

        switch(n)
        {
            case 1:
            {
                string planeName;
                iFILE>>planeName;
                Node *currentHead;
                if(planeName == "\0")                       // THIS WORKED
                    continue;

                for(int i=0; i<noOfPlanes; i++)
                    if(heads[i]->name == planeName)
                    {
                        currentHead = heads[i];
                        break;
                    }
                
                int passengersToAdd = 0;
                iFILE>>passengersToAdd;

                for(int i=0; i<passengersToAdd; i++)
                {
                    string passengerName;
                    iFILE>>passengerName;
                    addingReservation(currentHead, passengerName);
                }

                break;
            }
            
            case 2:
            {
                string planeName;
                iFILE>>planeName;
                Node *currentHead;
                if(planeName == "\0")                       // THIS WORKED
                    continue;

                for(int i=0; i<noOfPlanes; i++)
                    if(heads[i]->name == planeName)
                    {
                        currentHead = heads[i];
                        break;
                    }
                
                int passengersToDelete = 0;
                iFILE>>passengersToDelete;

                for(int i=0; i<passengersToDelete; i++)
                {
                    string passengerName;
                    iFILE>>passengerName;
                    cancelReservation(currentHead, passengerName);
                }

                break;
            }

            case 3:
            {
                string planeName;
                iFILE>>planeName;
                Node *currentHead;
                if(planeName == "\0")                       // THIS WORKED
                    continue;

                for(int i=0; i<noOfPlanes; i++)
                    if(heads[i]->name == planeName)
                    {
                        currentHead = heads[i];
                        break;
                    }
                cout<<"Passenger(s) in plane "<<planeName<<" is/are:"<<endl;
                printNames(currentHead->next);
                cout<<endl;
                break;
            }

            case 4:
            {
                string planeName;
                iFILE>>planeName;
                // if(planeName == "\0")                       // THIS IS TO BE UNCOMMENTED IF THE LAST COMMAND GETS EXECUTED TWICE
                //     continue;

                Node *currentHead;

                for(int i=0; i<noOfPlanes; i++)
                {
                    if(heads[i]->name == planeName)
                    {
                        currentHead = heads[i];
                        break;
                    }
                }
                int ans = noOfPassengers(currentHead);
                ans == 0 ? cout<<"No Passengers travelling in plane "<<planeName<<endl : cout<<ans<<" passenger(s) in the plane "<<planeName<<endl;

                cout<<endl;
                break;    
            }
        }
    }

    iFILE.close();
}