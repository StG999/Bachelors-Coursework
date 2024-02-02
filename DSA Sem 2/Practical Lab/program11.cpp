// 11. Write a program to add two polynomials using linked lists.

#include <iostream>
using namespace std;

class Node
{
public:
    int coff;
    int pow;
    Node *next;
};

class Poly
{
    Node *root;

public:
    Poly();
    ~Poly();
    void Create(int coff, int pow);
    // Node * add(Node * p, Node * q);
    Node *getroot() { return root; }
    void Display();
};

void Poly::Display()
{
    Node *p = root;
    while (p != NULL)
    {
        cout << p->coff << "x^" << p->pow;
        if (p->next != NULL)
        {
            if (p->next->coff > 0)
            {
                cout << " + ";
            }
            else if (p->next->coff < 0)
            {
                cout << " - ";
            }
        }
        p = p->next;
    }
    cout << endl;
}

void Poly::Create(int coff1, int pow1)
{
    if (root == NULL)
    {
        root = new Node;
        root->coff = coff1;
        root->pow = pow1;
        root->next = NULL;
        return;
    }
    else
    {
        Node *p = root;
        while (p->next != NULL)
        {
            p = p->next;
        }
        Node *t = new Node;
        t->coff = coff1;
        t->pow = pow1;
        t->next = NULL;
        p->next = t;
    }
}

Poly::Poly()
{
    root = NULL;
}

Poly::~Poly()
{
    Node *p;
    while (root != NULL)
    {
        p = root;
        root = root->next;
        delete p;
    }
}

Poly add1(Node *p, Node *q)
{
    Poly result;

    while (p != NULL && q != NULL)
    {
        if (p->pow > q->pow)
        {
            result.Create(p->coff, p->pow);
            p = p->next;
        }
        else if (p->pow < q->pow)
        {
            result.Create(q->coff, q->pow);
            q = q->next;
        }
        else if (p->pow == q->pow)
        {
            result.Create(p->coff + q->coff, p->pow);
            p = p->next;
            q = q->next;
        }
    }

    while (p != NULL)
    {
        result.Create(p->coff, p->pow);
        p = p->next;
    }
    while (q != NULL)
    {
        result.Create(q->coff, q->pow);
        q = q->next;
    }

    return result;
}

int main()
{
    Poly p1;
    Poly p2;
    for (int i = 0; i < 2; i++)
    {
        int n;
        cout << "Enter the number of terms in polynomial " << i + 1 << endl;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x, y;
            cout << "Enter the cofficient and power of term no. " << j + 1 << " of Polynomail No. " << i + 1 << endl;
            cin >> x >> y;
            if (i == 0)
            {
                p1.Create(x, y);
            }
            else if (i == 1)
            {
                p2.Create(x, y);
            }
        }
    }
    cout<<"Polynomial No. 1 : ";
    p1.Display();
    cout<<"Polynomial No. 2 : ";
    p2.Display();

    Poly p3;
    p3 = add1(p1.getroot(), p2.getroot());
    cout<<"Resultant Polynomail : ";
    p3.Display();

    return 0;
}