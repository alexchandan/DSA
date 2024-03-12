#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // creating constructor to set data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// inserting new node at head position;
void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

// inserting new node at the end of the list position
void insertAtTail(Node *head, int d)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(d);
    temp->next = newNode;
    newNode = NULL;
}

// insert newNode at the given position.
void insertAtPosition(Node *&head, int d, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    int count = 1;
    while (count < pos - 1)
    {
        count++;
        temp = temp->next;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Deleting nodes
void deleteNode(Node *&head, int pos)
{
    Node *curr = head;
    if (pos == 1)
    {
        head = curr->next;
        curr = NULL;
        delete curr;
    }

    else
    {
        int cnt = 1;
        Node *curr = head;
        Node *prev = NULL;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// Displaying data
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node = new Node(12);
    Node *head = node;
    Node *tail = tail;
    cout << node->data << endl;
    cout << node->next << endl;
    insertAtHead(head, 5);
    insertAtHead(head, 10);
    insertAtTail(head, 23);
    insertAtTail(head, 26);
    insertAtPosition(head, 8, 3);
    // inserting at positing 1;
    insertAtPosition(head, 9, 1);

    // deleting a node
    cout << "before deleting " << endl;
    display(head);
    cout << endl;
    deleteNode(head, 1);
    cout << "after delete" << endl;
    display(head);
    return 0;
}