#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *previous;

    Node(int val)
    {
        this->val = val;
        next = NULL;
        previous = NULL;
    }
};

void print_left_to_right(Node *head)
{
    cout << "L ->";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->val;
        temp = temp->next;
    }
    cout << endl;
}

void print_right_to_left(Node *tail)
{
    cout << "R ->";
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << " " << temp->val;
        temp = temp->previous;
    }
    cout << endl;
}

int get_size(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void insert_at_head(Node* &head,Node* &tail, int val)
{


    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;

    }
    newnode->next = head;
    head->previous = newnode;
    head = newnode;

}


void insert_at_tail(Node* &head,Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->previous = tail;
    tail = newnode;

}


void insert_at_any_position(Node *&head, int index, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    } 

 
   newNode->next = temp->next;
   temp->next->previous = newNode;
   temp->next = newNode;
   newNode->previous = temp;
}

void insert_at_position(Node *&head, Node *&tail, int posi, int val)
{
    int size = get_size(head);

    if (posi < 0 || posi > size)
    {
        cout << "Invalid" << endl;
        return;
    }

    else if (posi == 0)
    {
        insert_at_head(head, tail, val);
    }
    else if (posi == size)
    {
        insert_at_tail(head, tail, val);
    }
    else
    {
        insert_at_any_position(head, posi, val);
    }

    print_left_to_right(head);
    print_right_to_left(tail);
}

int main()
{
    int q;
    cin >> q;

    Node *head = NULL;
    Node *tail = NULL;

    while (q--)
    {
        int X, V;
        cin >> X >> V;
        insert_at_position(head, tail, X, V);
    }

    return 0;
}
