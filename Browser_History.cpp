#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string val;
    Node* next;
    Node* previous;

    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->previous = NULL;
    }
};


void insert_at_tail(Node* &head, Node* &tail, string val)
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

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    string address;


    while(true)
    {
        cin >> address;
        if(address == "end")
        {
            break;
        } 
        insert_at_tail(head, tail, address);
    }

    int q;
    cin >> q;
    cin.ignore(); 

    Node* current = head; 

    while(q--)
    {
        string commandLine;
        getline(cin, commandLine);
        stringstream ss(commandLine);
        string command, value;
        ss >> command;

        if(command == "visit")
        {
            ss >> value;
            Node* tmp = head;
            bool found = false;
            while(tmp != NULL)
            {
                if(tmp->val ==  value)
                {
                    current = tmp;
                    cout << current->val << endl;
                    found = true;
                    break;
                }
                tmp  = tmp->next;
            }
            if(!found)
            {
                cout << "Not Available" << endl;
            }
        }
        else if(command == "next")
        {
            if(current->next != NULL)
            {
                current = current->next;
                cout << current-> val << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }


        }
        else if(command == "prev")
        {
            if(current->previous != NULL)
            {
                current = current->previous;
                cout << current->val << endl ;

            }
            else
            {
                cout << "Not Available" <<  endl;
            }
        }
    }

    return 0;
}
